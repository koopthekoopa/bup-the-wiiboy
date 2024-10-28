#include "functions.h"

#include <lunarengine.h>
#include <SDL2/SDL.h>

#include "assets/assets.h"
#include "game/data.h"
#include "game/input.h"
#include "game/camera.h"
#include "game/level.h"
#include "game/network/common.h"
#include "game/network/packet.h"
#include "game/overlay/hud.h"
#include "main.h"

#define arrsize(x) (sizeof(x) / sizeof(*(x)))

entity_texture(player) {
    LE_EntityProperty property;
    LE_EntityGetProperty(entity, &property, "player_id");
    int player_id = property.asInt;
    int sprite = 0;
    LE_EntityProperty facing_left;
    facing_left.asBool = false;
    LE_EntityGetProperty(entity, &facing_left, "facing_left");
    if (fabs(entity->velX) > 0) {
        if (entity->velX < 0) facing_left.asBool = true;
        if (entity->velX > 0) facing_left.asBool = false;
        sprite = (int)(entity->posX) % 2 + 1;
    }
    if (
        (facing_left.asBool && is_button_down(player_id, BUTTON_MOVE_RIGHT)) ||
        (!facing_left.asBool && is_button_down(player_id, BUTTON_MOVE_LEFT))
    ) sprite = 5;
    if (entity->velY > 0) sprite = 4;
    if (entity->velY < 0) sprite = 3;
    LE_EntitySetProperty(entity, facing_left, "facing_left");
    *srcX = sprite * 16;
    *srcY = 0;
    *srcW = 16;
    *srcH = 16;
    *w = facing_left.asBool ? -16 : 16;
    *h = 16;
    return GET_ASSET(struct Texture, "images/entities/player.png");
}

entity_update(player_spawner) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (!players[i].camera || players[i].entity) continue;
        players[i].entity = LE_CreateEntity(LE_EntityGetList(entity), get_entity_builder_by_id(player), entity->posX, entity->posY);
        LE_EntitySetProperty(players[i].entity, (LE_EntityProperty){ .asInt = i }, "player_id");
    }
}

entity_update(player) {
    LE_EntityProperty property;
    LE_EntityGetProperty(entity, &property, "player_id");
    int player_id = property.asInt;
    bool l = is_button_down(player_id, BUTTON_MOVE_LEFT);
    bool r = is_button_down(player_id, BUTTON_MOVE_RIGHT);
    if (l && !r) {
        entity->velX -= 0.02f;
        if (entity->velX < -0.2f) entity->velX = -0.2f;
    }
    else if (!l && r) {
        entity->velX += 0.02f;
        if (entity->velX > 0.2f) entity->velX = 0.2f;
    }
    else {
        if (entity->velX < 0) {
            entity->velX += 0.02f;
            if (entity->velX > 0) entity->velX = 0;
        }
        if (entity->velX > 0) {
            entity->velX -= 0.02f;
            if (entity->velX < 0) entity->velX = 0;
        }
    }
    entity->velY += 0.03f;
    if ((entity->flags & LE_EntityFlags_OnGround) && is_button_pressed(player_id, BUTTON_JUMP)) entity->velY = -0.5f;
    hud_update(entity);
    camera_set_focus(players[player_id].camera, entity->posX, 8);
}

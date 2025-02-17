#ifndef REACTION_H
#define REACTION_H

#include "obj_types.h"

typedef enum NpcReaction {
    NPC_REACTION_BAD,
    NPC_REACTION_NEUTRAL,
    NPC_REACTION_GOOD,
} NpcReaction;

int reactionSetValue(Object* critter, int a2);
int reactionTranslateValue(int a1);
int sub_4A29F0();
int reactionGetValue(Object* critter);

#endif /* REACTION_H */

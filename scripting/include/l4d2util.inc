#pragma semicolon 1

#if defined l4d2util_inc_
    #endinput
#endif
#define l4d2util_inc_

#include <l4d2util_constants>
#include <l4d2util_infected>
#include <l4d2util_rounds>
#include <l4d2util_survivors>
#include <l4d2util_tanks>

/**
 * Called when a new round begins.
 *
 * @noreturn
 */
forward OnRoundStart();

/**
 * Called when a round ends.
 *
 * @noreturn
 */
forward OnRoundEnd();

/**
 * Called when a tank punches a hittable, like a car or dumpster.
 *
 * @param iTank Client ID of the tank
 * @param iEntity Entity ID of the hittable
 * @noreturn
 */
forward OnTankPunchHittable(iTank, iEntity);

/**
 * Called when a tank first spawns.
 *
 * @param iTank Client ID of the tank
 * @noreturn
 */
forward OnTankSpawn(iTank);

/**
 * Called when a tank passes control from one player to another.
 *
 * @param iTank Client ID of the tank
 * @param iOldTank Client ID of the previous tank
 * @noreturn
 */
forward OnTankPass(iTank, iOldTank);

/**
 * Called when the tank dies.
 *
 * @param Tank Client ID of the dead tank
 * @noreturn
 */
forward OnTankDeath();

/**
 * Is there a tank currently in play?
 *
 * @return bool
 */
native bool:IsTankInPlay();

/**
 * Retuns the client ID of the player currently playing tank.
 *
 * @return client ID
 */
native GetTankClient();

public SharedPlugin:__pl_l4d2util = {
    name = "l4d2util",
    file = "l4d2util.smx",
#if defined REQUIRE_PLUGIN
    required = 1,
#else
    required = 0,
};

public __pl_l4d2util_SetNTVOptional() {
    MarkNativeAsOptional("GetTankClient");
    MarkNativeAsOptional("IsTankInPlay");
}

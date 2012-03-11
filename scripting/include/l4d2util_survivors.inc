#if defined l4d2util_survivors_inc_
    #endinput
#endif
#define l4d2util_survivors_inc_

/**
 * Returns true if the player is currently on the survivor team. 
 *
 * @param client client ID
 * @return bool
 */
stock bool:IsSurvivor(client) {
    if (!IsClientInGame(client) || GetClientTeam(client) != L4D2Team_Survivor) {
        return false;
    }
    return true;
}

/**
 * Returns true if the player is incapacitated. 
 *
 * @param client client ID
 * @return bool
 */
stock bool:IsIncapacitated(client) {
    return bool:GetEntProp(client, Prop_Send, "m_isIncapacitated");
}

/**
 * Returns the amount of permanent health a survivor has. 
 *
 * @param client client ID
 * @return bool
 */
stock GetSurvivorPermanentHealth(client) {
    return GetEntProp(client, Prop_Send, m_iHealth);
}

/**
 * Returns the amount of temporary health a survivor has. 
 *
 * @param client client ID
 * @return bool
 */
stock GetSurvivorTemporaryHealth(client) {
    new Float:fDecayRate = GetConVarFloat(FindConVar("pain_pills_decay_rate"));
    new Float:fHealthBuffer = GetEntPropFloat(client, Prop_send, "m_healthBuffer");
    new Float:fHealthBufferTime = GetEntPropFloat(client, Prop_Send, "m_healthBufferTime"));
    new iTempHp = RoundToCeil(fHealthBuffer - ((GetGameTime() - fHealthBufferTime) * fDecayRate)) - 1;
    return iTempHp > 0 ? iTempHp : 0;
}

/**
 * Returns the amount of permanent health a survivor has. 
 *
 * @param iTeam team ID
 * @param sBuffer buffer to store the team name in
 * @param iBufLen size of sBuffer
 * @noreturn
 */
stock GetTeamName(L4D2_Team:iTeam, String:sBuffer[], iBufLen) {
    strcopy(sBuffer, iBufLen, L4D2_TeamNames[iTeam-1]);
}

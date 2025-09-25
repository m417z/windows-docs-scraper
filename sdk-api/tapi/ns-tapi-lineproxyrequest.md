# LINEPROXYREQUEST structure

## Description

The
**LINEPROXYREQUEST** structure contains parameter values of the application making the proxy request. Multiple
[TAPI call center functions](https://learn.microsoft.com/windows/desktop/Tapi/call-center-functions) generate a
[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest) message that references a
**LINEPROXYREQUEST** structure.

## Members

### `dwSize`

Total number of bytes allocated by TAPI to contain the
**LINEPROXYREQUEST** structure. The **dwTotalSize** member of any structure contained within
**LINEPROXYREQUEST** (for example,
[LINEAGENTCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentcaps)) reflects only the number of bytes allocated for that specific structure.
Total size, in bytes, of the *Params* parameter block.

### `dwClientMachineNameSize`

Size of the client machine name string, in bytes, including the **null**-terminating character.

### `dwClientMachineNameOffset`

Offset from the beginning of the structure to a **null**-terminated string identifying the client machine that made this request. The size of the string is specified by **dwClientMachineNameSize**.

### `dwClientUserNameSize`

Size of the client user name string, in bytes, including the **null**-terminating character.

### `dwClientUserNameOffset`

Offset from the beginning of the structure to a **null**-terminated string identifying the user under whose account the application is running on the client machine. The size of the string is specified by **dwClientUserNameSize**.

### `dwClientAppAPIVersion`

Highest API version supported by the application that made the request. The proxy handler should restrict the contents of any data returned to the application to those members and values that were defined in this, or earlier, versions of TAPI.

### `dwRequestType`

One of the
[LINEPROXYREQUEST_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineproxyrequest--constants). Identifies the type of function and the union component that defines the remaining data in the structure.

### `SetAgentGroup`

Union component used when **dwRequestType** is LINEPROXYREQUEST_SETAGENT.

### `SetAgentGroup.dwAddressID`

Identifier of the address for which the agent is to be set.

### `SetAgentGroup.GroupList`

Structure of type
[LINEAGENTGROUPLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgrouplist). Offsets within this structure are relative to the beginning of **SetAgentGroup.GroupList** rather than to the beginning of the
**LINEPROXYREQUEST** structure.

### `SetAgentState`

Union component used when **dwRequestType** is LINEPROXYREQUEST_SETAGENTSTATE.

### `SetAgentState.dwAddressID`

Identifier of the address for which the agent state is to be set.

### `SetAgentState.dwAgentState`

New agent state, or zero to leave the agent state unchanged.

### `SetAgentState.dwNextAgentState`

New next agent state, or zero to use the default next state associated with the specified agent state.

### `SetAgentActivity`

Union component used when **dwRequestType** is LINEPROXYREQUEST_SETAGENTACTIVITY.

### `SetAgentActivity.dwAddressID`

Identifier of the address for which the agent activity is to be set.

### `SetAgentActivity.dwActivityID`

Identifier for the activity being selected.

### `GetAgentCaps`

Union component used when **dwRequestType** is LINEPROXYREQUEST_GETAGENTCAPS.

### `GetAgentCaps.dwAddressID`

Identifier of the address for which the agent capabilities are to be retrieved.

### `GetAgentCaps.AgentCaps`

Structure of type
[LINEAGENTCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentcaps). Offsets within this structure are relative to the beginning of **GetAgentCaps.AgentCaps** rather than to the beginning of the
**LINEPROXYREQUEST** structure. The **dwTotalSize** member is set by TAPI and the remaining bytes set to zero. The proxy handler must fill in **dwNeededSize**, **dwUsedSize**, and the remaining members as appropriate, before calling
[lineProxyResponse](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineproxyresponse).

### `GetAgentStatus`

Union component used when **dwRequestType** is LINEPROXYREQUEST_SETAGENTGROUP.

### `GetAgentStatus.dwAddressID`

Identifier of the address for which the agent status is to be retrieved.

### `GetAgentStatus.AgentStatus`

Structure of type
[LINEAGENTSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentstatus). Offsets within this structure are relative to the beginning of **GetAgentStatus.AgentStatus** rather than to the beginning of the
**LINEPROXYREQUEST** structure. The **dwTotalSize** member is set by TAPI and the remaining bytes set to zero. The proxy handler must fill in **dwNeededSize**, **dwUsedSize**, and the remaining members as appropriate, before calling
[lineProxyResponse](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineproxyresponse).

### `AgentSpecific`

Union component used when **dwRequestType** is LINEPROXYREQUEST_AGENTSPECIFIC.

### `AgentSpecific.dwAddressID`

Identifier of the address for which the agent status is to be retrieved.

### `AgentSpecific.dwAgentExtensionIDIndex`

Index of the handler extension being invoked; the identifier's position within the array of extension identifiers returned in
[LINEAGENTCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentcaps).

### `AgentSpecific.dwSize`

Total size, in bytes, of the *Params* parameter block.

### `AgentSpecific.Params`

Block of memory that includes the contents passed to the handler from the application. If the handler is to return data to the application, it must be written into this parameter block before calling
[lineProxyResponse](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineproxyresponse).

### `GetAgentActivityList`

Union component used when **dwRequestType** is LINEPROXYREQUEST_GETAGENTACTIVITYLIST.

### `GetAgentActivityList.dwAddressID`

Identifier of the address for which the agent activity list is to be retrieved.

### `GetAgentActivityList.ActivityList`

Structure of type
[LINEAGENTACTIVITYLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentactivitylist). Offsets within this structure are relative to the beginning of **GetAgentActivityList.ActivityList** rather than to the beginning of the
**LINEPROXYREQUEST** structure. The **dwTotalSize** member is set by TAPI and the remaining bytes set to zero. The proxy handler must fill in **dwNeededSize**, **dwUsedSize**, and the remaining members as appropriate, before calling
[lineProxyResponse](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineproxyresponse).

### `GetAgentGroupList`

Union component used when **dwRequestType** is LINEPROXYREQUEST_GETAGENTGROUPLIST.

### `GetAgentGroupList.dwAddressID`

Identifier of the address for which the agent group list is to be retrieved.

### `GetAgentGroupList.GroupList`

Structure of type
[LINEAGENTGROUPLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgrouplist). Offsets within this structure are relative to the beginning of **GetAgentGroupList.GroupList** rather than to the beginning of the
**LINEPROXYREQUEST** structure. The **dwTotalSize** member is set by TAPI and the remaining bytes set to zero. The proxy handler must fill in **dwNeededSize**, **dwUsedSize**, and the remaining members as appropriate, before calling
[lineProxyResponse](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineproxyresponse).

### `CreateAgent`

Union component used when **dwRequestType** is LINEPROXYREQUEST_CREATEAGENT.

### `CreateAgent.hAgent`

Unique identifier for an agent. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `CreateAgent.dwAgentIDSize`

Size of the agent ID string, in bytes.

### `CreateAgent.dwAgentIDOffset`

Offset from the beginning of the structure to a **null**-terminated string that specifies the ID of the agent. The size of the string is specified by **dwAgentIDSize**.

### `CreateAgent.dwAgentPINSize`

Size of the PIN string including the **null** terminator, in bytes.

### `CreateAgent.dwAgentPINOffset`

Offset from the beginning of the structure to a **null**-terminated string that specifies the PIN or password of the agent. The size of the string is specified by **dwAgentPINSize**.

### `SetAgentStateEx`

Union component used when **dwRequestType** is LINEPROXYREQUEST_SETAGENTSTATEEX.

### `SetAgentStateEx.hAgent`

Unique identifier for an agent. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `SetAgentStateEx.dwAgentState`

One of the
[LINEAGENTSTATEEX_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentstateex--constants).

### `SetAgentStateEx.dwNextAgentState`

One of the
[LINEAGENTSTATEEX_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentstateex--constants).

### `SetAgentMeasurementPeriod`

Union component used when **dwRequestType** is LINEPROXYREQUEST_SETAGENTMEASUREMENTPERIOD.

### `SetAgentMeasurementPeriod.hAgent`

Unique identifier for an agent. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `SetAgentMeasurementPeriod.dwMeasurementPeriod`

Period for which the switch or implementation stores and calculates information, in seconds. For example, **dwNumberOfACDCalls** holds the number of calls the agent handled; **dwMeasurementPeriod** indicates if this value referenced the calls handled in the last hour, day, or month.

### `GetAgentInfo`

Union component used when **dwRequestType** is LINEPROXYREQUEST_GETAGENTINFO.

### `GetAgentInfo.hAgent`

Unique identifier for an agent. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `GetAgentInfo.AgentInfo`

Structure of type
[LINEAGENTINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentinfo).

### `CreateAgentSession`

Union component used when **dwRequestType** is LINEPROXYREQUEST_CREATEAGENTSESSION.

### `CreateAgentSession.hAgentSession`

Unique identifier for an agent session.

### `CreateAgentSession.dwAgentPINSize`

Size of the agent PIN string including the **null** terminator, in bytes.

### `CreateAgentSession.dwAgentPINOffset`

Offset from the beginning of the structure to a **null**-terminated string that specifies the PIN or password of the agent. The size of this string is specified by **dwAgentPINSize**.

### `CreateAgentSession.hAgent`

Unique identifier for an agent. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `CreateAgentSession.GroupID`

Universally unique identifier for an ACD group. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `CreateAgentSession.dwWorkingAddressID`

Identifier of the address on which the agent will receive calls for this session.

### `GetAgentSessionList`

Union component used when **dwRequestType** is LINEPROXYREQUEST_GETAGENTSESSIONLIST.

### `GetAgentSessionList.hAgent`

Unique identifier for an agent. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `GetAgentSessionList.SessionList`

Structure of type
[LINEAGENTSESSIONLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentsessionlist).

### `GetAgentSessionInfo`

Union component used when **dwRequestType** is LINEPROXYREQUEST_GETAGENTSESSIONINFO.

### `GetAgentSessionInfo.hAgentSession`

Unique identifier for an agent session. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `GetAgentSessionInfo.SessionInfo`

Structure of type
[LINEAGENTSESSIONINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentsessioninfo).

### `SetAgentSessionState`

Union component used when **dwRequestType** is LINEPROXYREQUEST_SETAGENTSESSIONSTATE.

### `SetAgentSessionState.hAgentSession`

Unique identifier for an agent session. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `SetAgentSessionState.dwAgentSessionState`

One of the
[LINEAGENTSESSIONSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentsessionstate--constants).

### `SetAgentSessionState.dwNextAgentSessionState`

One of the
[LINEAGENTSESSIONSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentsessionstate--constants).

### `GetQueueList`

Union component used when **dwRequestType** is LINEPROXYREQUEST_GETQUEUELIST.

### `GetQueueList.GroupID`

Universally unique identifier for an ACD group. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `GetQueueList.QueueList`

Structure of type
[LINEQUEUELIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linequeuelist).

### `SetQueueMeasurementPeriod`

Union component used when **dwRequestType** is LINEPROXYREQUEST_SETQUEUEMEASUREMENTPERIOD.

### `SetQueueMeasurementPeriod.dwQueueID`

Unique identifier for a queue. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `SetQueueMeasurementPeriod.dwMeasurementPeriod`

Period for which the switch or implementation stores and calculates information, in seconds.

### `GetQueueInfo`

Union component used when **dwRequestType** is LINEPROXYREQUEST_GETQUEUEINFO.

### `GetQueueInfo.dwQueueID`

Unique identifier for a queue. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `GetQueueInfo.QueueInfo`

Structure of type
[LINEQUEUEINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linequeueinfo).

### `GetGroupList`

Union component used when **dwRequestType** is LINEPROXYREQUEST_GETGROUPLIST.

### `GetGroupList.GroupList`

Structure of type
[LINEAGENTGROUPLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgrouplist).

## Remarks

An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

## See also

[LINEAGENTACTIVITYLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentactivitylist)

[LINEAGENTCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentcaps)

[LINEAGENTGROUPLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgrouplist)

[LINEAGENTSESSIONINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentsessioninfo)

[LINEAGENTSESSIONLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentsessionlist)

[LINEAGENTSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentstatus)

[LINEQUEUELIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linequeuelist)

[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest)

[lineProxyResponse](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineproxyresponse)
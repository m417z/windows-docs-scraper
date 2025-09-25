# LINEAGENTSTATUS structure

## Description

The
**LINEAGENTSTATUS** structure describes the current status of an ACD agent. The
[lineGetAgentStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentstatusa) function returns the
**LINEAGENTSTATUS** structure.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size needed to hold all the information requested, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwNumEntries`

Number of
[LINEAGENTGROUPENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgroupentry) structures that appear in the *GroupList* array. The value is 0 if no agent is logged in on the address.

### `dwGroupListSize`

Size of the group list array, in bytes.

### `dwGroupListOffset`

Offset from the beginning of this structure to an array of
[LINEAGENTGROUPENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgroupentry) structures. The size is **dwNumEntries** times SIZEOF(LINEAGENTGROUPENTRY). The array contains groups into which the agent is currently logged in on the address. The size of the field is specified by **dwGroupListSize**.

### `dwState`

Current state of the agent. One of the
[LINEAGENTSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentstate--constants).

### `dwNextState`

State into which the agent is automatically placed when the current call completes. One of the [LINEAGENTSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentstate--constants).

### `dwActivityID`

Identifier of the current agent activity.

### `dwActivitySize`

Size of the agent activity string, in bytes.

### `dwActivityOffset`

Offset from the beginning of the structure to a null-terminated string specifying the current agent activity. The size of the string is specified by **dwActivitySize**.

### `dwAgentFeatures`

Agent-related features available at the time the status was obtained, using the
[LINEAGENTFEATURE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentfeature--constants).

### `dwValidStates`

Agent states that could be selected, at this point in time, using
[lineSetAgentState](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentstate). Consists of one or more of the
[LINEAGENTSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentstate--constants).

### `dwValidNextStates`

Next agent states that could be selected, at this point in time, by calling the
[lineSetAgentState](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentstate) function. Consists of one or more of the [LINEAGENTSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentstate--constants).

## See also

[LINEAGENTFEATURE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentfeature--constants)

[LINEAGENTGROUPENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgroupentry)

[LINEAGENTSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentstate--constants)

[lineGetAgentStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentstatusa)

[lineSetAgentState](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentstate)
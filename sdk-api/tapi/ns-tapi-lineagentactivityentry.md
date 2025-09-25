# LINEAGENTACTIVITYENTRY structure

## Description

The
**LINEAGENTACTIVITYENTRY** structure describes a single ACD agent activity. The
[LINEAGENTACTIVITYLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentactivitylist) structure can contain an array of
**LINEAGENTACTIVITYENTRY** structures.

## Members

### `dwID`

Unique identifier for an activity. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `dwNameSize`

Size of the activity name including the **null** terminator, in bytes.

### `dwNameOffset`

Offset from the beginning of this structure to a **null**-terminated string specifying the name and other identifying information of an activity that can be selected by calling the
[lineSetAgentActivity](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentactivity) function. The size of the string is specified by **dwNameSize**.

## See also

[LINEAGENTACTIVITYLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentactivitylist)

[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest)

[lineGetAgentActivityList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentactivitylista)

[lineSetAgentActivity](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentactivity)
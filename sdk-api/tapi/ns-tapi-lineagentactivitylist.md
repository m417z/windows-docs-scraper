# LINEAGENTACTIVITYLIST structure

## Description

The
**LINEAGENTACTIVITYLIST** structure describes a list of ACD agent activities. This structure can contain an array of
[LINEAGENTACTIVITYENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentactivityentry) structures. The
[lineGetAgentActivityList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentactivitylista) function returns the
**LINEAGENTACTIVITYLIST** structure.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size needed to hold all the information requested, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwNumEntries`

Number of
[LINEAGENTACTIVITYENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentactivityentry) structures that appear in the *List* array. The value is 0 if no agent activity codes are available.

### `dwListSize`

Size of the activity list array, in bytes.

### `dwListOffset`

Offset from the beginning of the structure to an array of
[LINEAGENTACTIVITYENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentactivityentry) structures indicating information about activity that could be specified for the current logged-in agent. This is **dwNumEntries** times SIZEOF(LINEAGENTACTIVITYENTRY). The size of the array is specified by **dwListSize**.

## See also

[LINEAGENTACTIVITYENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentactivityentry)

[lineGetAgentActivityList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentactivitylista)

[lineSetAgentActivity](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentactivity)
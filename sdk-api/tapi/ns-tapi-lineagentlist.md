# LINEAGENTLIST structure

## Description

The
**LINEAGENTLIST** structure describes a list of ACD agents. This structure can contain an array of
[LINEAGENTENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagententry) structures.

## Members

### `dwTotalSize`

Total size allocated to this structure, in bytes.

### `dwNeededSize`

Size needed to hold all the information requested, in bytes.

### `dwUsedSize`

Size of the portion of this structure that contains useful information, in bytes.

### `dwNumEntries`

Number of
[LINEAGENTENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagententry) structures that appear in the list array. The value is zero if no agents are available.

### `dwListSize`

Size of the agent list array, in bytes.

### `dwListOffset`

Offset from the beginning of the structure to an array of
[LINEAGENTENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagententry) structures that specify information about agents. The **dwListOffset** member is **dwNumEntries** times SIZEOF(LINEAGENTENTRY). The size of the field is specified by **dwListSize**.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[LINEAGENTENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagententry)
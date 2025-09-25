# LINEAGENTSESSIONLIST structure

## Description

The
**LINEAGENTSESSIONLIST** structure describes a list of ACD agent sessions. This structure can contain an array of
[LINEAGENTSESSIONENTRY](https://learn.microsoft.com/windows/win32/api/tapi/ns-tapi-lineagentsessionentry) structures. The
[lineGetAgentSessionList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentsessionlist) function returns the
**LINEAGENTSESSIONLIST** structure.

## Members

### `dwTotalSize`

Total size allocated to this structure, in bytes.

### `dwNeededSize`

Size needed to hold all the information requested, in bytes.

### `dwUsedSize`

Size of the portion of this structure that contains useful information, in bytes.

### `dwNumEntries`

Number of
[LINEAGENTSESSIONENTRY](https://learn.microsoft.com/windows/win32/api/tapi/ns-tapi-lineagentsessionentry) structures that appear in the list array. The value is zero if no agent sessions have been created.

### `dwListSize`

Size of the agent session list array, in bytes.

### `dwListOffset`

Offset from the beginning of this structure to an array of
[LINEAGENTSESSIONENTRY](https://learn.microsoft.com/windows/win32/api/tapi/ns-tapi-lineagentsessionentry) structures that specify information about agents. The **dwListOffset** member is **dwNumEntries** times SIZEOF(LINEAGENTSESSIONENTRY). The size of the field is specified by **dwListSize**.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[LINEAGENTSESSIONENTRY](https://learn.microsoft.com/windows/win32/api/tapi/ns-tapi-lineagentsessionentry)

[lineGetAgentSessionList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentsessionlist)
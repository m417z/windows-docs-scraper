# LINEAGENTGROUPLIST structure

## Description

The
**LINEAGENTGROUPLIST** structure describes a list of ACD agent groups. This structure can contain an array of
[LINEAGENTGROUPENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgroupentry) structures.

Multiple functions use the
**LINEAGENTGROUPLIST** structure; these include the
[lineGetAgentGroupList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentgrouplista),
[lineGetGroupList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetgrouplista) and
[lineSetAgentGroup](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentgroup) functions.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size needed to hold all the information requested, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwNumEntries`

Number of
[LINEAGENTGROUPENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgroupentry) structures that appear in the *List* array. The value is 0 if no agent is to be logged in on the address.

### `dwListSize`

Size of the group list array, in bytes.

### `dwListOffset`

Offset from the beginning of this structure to an array of
[LINEAGENTGROUPENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgroupentry) structures that specify information about each group into which the current agent is to be logged in at the address. This is **dwNumEntries** times SIZEOF(LINEAGENTGROUPENTRY). The size of the field is specified by **dwListSize**.

## See also

[LINEAGENTGROUPENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgroupentry)

[lineGetAgentGroupList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentgrouplista)

[lineGetGroupList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetgrouplista)

[lineSetAgentGroup](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentgroup)
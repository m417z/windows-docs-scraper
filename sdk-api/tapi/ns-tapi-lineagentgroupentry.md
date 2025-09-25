# LINEAGENTGROUPENTRY structure

## Description

The
**LINEAGENTGROUPENTRY** structure provides information on ACD agent groups. The
[LINEAGENTGROUPLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgrouplist) structure can contain an array of
**LINEAGENTGROUPENTRY** structures.

## Members

### `GroupID`

### `GroupID.dwGroupID1`

First part of the universally unique identifier for the group.

### `GroupID.dwGroupID2`

Second part of the universally unique identifier for the group.

### `GroupID.dwGroupID3`

Third part of the universally unique identifier for the group.

### `GroupID.dwGroupID4`

Fourth part of the universally unique identifier for a group. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `dwNameSize`

Size of the ACD group or queue name including the **null** terminator, in bytes.

### `dwNameOffset`

Offset from the beginning of the structure to a **null**-terminated string specifying the name and other identifying information of an ACD group or queue into which the agent can log in. This string can contain such information as supervisor and skill level, to assist the agent in selecting the correct group from a list displayed on their workstation screen. The size of the field is specified by **dwNameSize**.

## See also

[LINEAGENTGROUPLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgrouplist)

[lineGetAgentGroupList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentgrouplista)

[lineGetGroupList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetgrouplista)

[lineSetAgentGroup](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentgroup)
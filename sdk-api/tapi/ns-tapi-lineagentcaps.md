# LINEAGENTCAPS structure

## Description

The
**LINEAGENTCAPS** structure describes the capabilities of an ACD agent. The
[lineGetAgentCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentcapsa) function returns the
**LINEAGENTCAPS** structure.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size needed to hold all the information requested, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwAgentHandlerInfoSize`

Size of the agent handler information, in bytes.

### `dwAgentHandlerInfoOffset`

Offset from the beginning of the structure to a null-terminated string specifying the name, version, or other identifying information of the server application that is handling agent requests. The size of the string is specified by **dwAgentHandlerInfoSize**.

### `dwCapsVersion`

TAPI version that the agent handler application used in preparing the contents of this structure. This is no greater than the API version that the calling application passed in to
[lineGetAgentCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentcapsa).

### `dwFeatures`

Agent-related features available for this line using the
[LINEAGENTFEATURE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentfeature--constants). Invoking a supported feature requires the line and address to be in the proper state. A zero in a bit position indicates that the corresponding feature is never available. A one indicates that the corresponding feature may be available if the line is in the appropriate state for the operation to be meaningful. This field allows an application to discover which agent features can be (and which can never be) supported by the device.

### `dwStates`

[LINEAGENTSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentstate--constants) that can be used in the *dwAgentState* parameter of
[lineSetAgentState](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentstate). Setting a supported state requires the line and address to be in the proper state. A zero in a bit position indicates that the corresponding state is never available. A one indicates that the corresponding state may be available if the line is in the appropriate state for the state to be meaningful. This field allows an application to discover which agent states can be (and which can never be) supported on the device.

### `dwNextStates`

LINEAGENTSTATE_ constants that can be used in the *dwNextAgentState* parameter of
[lineSetAgentState](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentstate). Setting a supported state requires the line and address to be in the proper state. A zero in a bit position indicates that the corresponding state is never available. A one indicates that the corresponding state may be available if the line is in the appropriate state for the state to be meaningful. This field allows an application to discover which agent states can be (and which can never be) supported on the device.

### `dwMaxNumGroupEntries`

Maximum number of agent identifiers that can be logged in on the address simultaneously. Determines the highest value that can be passed in as the **dwNumEntries** member in the
[LINEAGENTGROUPLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgrouplist) structure to
[lineSetAgentGroup](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentgroup).

### `dwAgentStatusMessages`

Indicates the
[LINEAGENTSTATUS_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentstatus--constants) that can be received by the application in *dwParam2* of a
[LINE_AGENTSTATUS](https://learn.microsoft.com/windows/desktop/Tapi/line-agentstatus) message.

### `dwNumAgentExtensionIDs`

Number of
[LINEEXTENSIONID](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineextensionid) structures that appear in the *ExtensionIDList* array. The value is 0 if agent-handler-specific extensions are supported on the address.

### `dwAgentExtensionIDListSize`

Size of the agent extension IDs array, in bytes.

### `dwAgentExtensionIDListOffset`

Offset from the beginning of the structure to an array of
[LINEEXTENSIONID](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineextensionid) structures. The size is **dwNumExtensionIDs** times SIZEOF(LINEEXTENSIONID). The array lists the 128-bit universally unique identifiers for all agent-handler-specific extensions supported by the agent handle for the address. The extension being used is referenced in the
[lineAgentSpecific](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineagentspecific) function and
[LINE_AGENTSPECIFIC](https://learn.microsoft.com/windows/desktop/Tapi/line-agentspecific) message by its position in this table, the first entry being entry 0, so it is important that the agent handler always present extension identifiers in this array in the same order. The size of the array is specified by **dwAgentExtensionIDListOffset**.

### `ProxyGUID`

GUID for ACD proxy associated with the line. This element is exposed only to applications that negotiate a TAPI version of 2.2 or higher.

## See also

[LINEAGENTGROUPLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgrouplist)

[LINEEXTENSIONID](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineextensionid)

[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest)

[LINE_AGENTSPECIFIC](https://learn.microsoft.com/windows/desktop/Tapi/line-agentspecific)

[LINE_AGENTSTATUS](https://learn.microsoft.com/windows/desktop/Tapi/line-agentstatus)

[lineAgentSpecific](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineagentspecific)

[lineGetAgentCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentcapsa)

[lineSetAgentGroup](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentgroup)

[lineSetAgentState](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentstate)
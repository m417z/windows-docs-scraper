# lineAgentSpecific function

## Description

The
**lineAgentSpecific** function allows the application to access proprietary handler-specific functions of the agent handler associated with the address. The meaning of the extensions are specific to the agent handler. Each set of agent-related extensions is identified by a universally unique 128-bit extension ID that must be obtained, along with the specification for the extension, from the promulgator of that extension (usually the author of the agent handler software on the telephony server). The list of extensions supported by the agent handler is obtained from the
[LINEAGENTCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentcaps) structure returned by
[lineGetAgentCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentcapsa).

## Parameters

### `hLine`

Handle to the open line device.

### `dwAddressID`

Address on the open line device. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `dwAgentExtensionIDIndex`

Position in the **ExtensionIDList** structure in
[LINEAGENTCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentcaps) of the agent handler extension being invoked.

### `lpParams`

Pointer to a memory area used to hold a parameter block. The format of this parameter block is device specific and its contents are passed by TAPI to and from the agent handler application on the telephony server. This parameter block must specify the function to be invoked and include sufficient room for any data to be returned.

### `dwSize`

Size of the parameter block area, in bytes.

**Note** If *lpParams* is a pointer to a string, the size must include the **NULL** terminator.

## Return value

Returns a positive request identifier if the asynchronous operation starts; otherwise, this function returns one of these negative error values:

LINEERR_INVALADDRESSID, LINEERR_INVALAGENTID, LINEERR_INVALLINEHANDLE, LINEERR_INVALPARAM, LINEERR_INVALPOINTER, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_STRUCTURETOOSMALL, LINEERR_UNINITIALIZED.

Additional return values are specific to the agent handler.

## Remarks

This operation is part of the Extended Telephony services. It provides access to an agent handler-specific feature without defining its meaning.

This function provides a generic parameter profile. The interpretation of the parameter structure is handler specific. Indications and replies sent back to the application that are handler specific should use the
[LINE_AGENTSPECIFIC](https://learn.microsoft.com/windows/desktop/Tapi/line-agentspecific) message.

An agent handler can provide access to handler-specific functions by defining parameters for use with this function. Applications that want to make use of these extensions should consult the vendor-specific documentation that describes what extensions are defined. Typically, an application that relies on these extensions is not able to work with other agent handler environments.

## See also

[LINEAGENTCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentcaps)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGetAgentCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentcapsa)
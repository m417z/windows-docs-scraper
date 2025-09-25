# PSTART_PROTOCOL callback function

## Description

The
**StartProtocol** function initializes the routing protocol's functionality. The router manager uses this function to pass the routing protocol global configuration parameters and a set of API entry points. The protocol uses these entry points to call into the router manager.

## Parameters

### `NotificationEvent` [in]

Handle to an event object. The routing protocol signals this event when it wants the router manager to retrieve an asynchronous message from the queue maintained by the protocol.

### `SupportFunctions` [in]

Pointer to a
[SUPPORT_FUNCTIONS](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-support_functions_50) structure. The fields of this structure are pointers to functions in the router manager. These functions allow the protocol to access information that spans routing protocols.

### `GlobalInfo` [in]

Pointer to protocol-defined global, as opposed to interface-specific, configuration information. This information is private to the routing protocol.

### `StructureVersion` [in]

Specifies the version of the information structures pointed to by the *GlobalInfo* parameter. In some cases, this is equal to the version of the routing protocol.

### `StructureSize` [in]

Specifies the size of each of the information structures pointed to by the *GlobalInfo* parameter. Since some information structures contain variable length members, the routing protocol isn't necessarily able to determine the size of the information from the version.

### `StructureCount` [in]

Specifies a count of the number of information structures pointed to by the *GlobalInfo* parameter. This parameter is always one.

## Return value

If the function succeeds, and the protocol is ready to receive interface information, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The attempt to initialize the routing protocol failed. |
| **ERROR_INVALID_PARAMETER** | One of the parameters pointed to by the *GlobalInfo* parameter is invalid. |

## See also

[GetEventMessage](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pget_event_message)

[Routing Protocol Interface Functions](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-functions)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)

[SUPPORT_FUNCTIONS](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-support_functions_50)

[StopProtocol](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pstop_protocol)
# MgmRegisterMProtocol function

## Description

The
**MgmRegisterMProtocol** function is used by clients to register with the multicast group manager. When the registration is complete, the multicast group manager returns a handle to the client. The client must supply this handle in subsequent MGM function calls.

## Parameters

### `prpiInfo` [in]

Pointer to a
[ROUTING_PROTOCOL_CONFIG](https://learn.microsoft.com/windows/desktop/api/mgm/ns-mgm-routing_protocol_config) structure that contains pointers to callbacks into the client.

### `dwProtocolId` [in]

Specifies the ID of the client. The ID is unique for each client.

### `dwComponentId` [in]

Specifies the component ID for a specific instance of the client. This parameter is used with *dwProtocolId* to uniquely identify an instance of a client.

### `phProtocol` [out]

On input, the client must supply a pointer to a handle.

On output, *phProtocol* receives the registration handle for the client. This handle must be used in subsequent calls to the multicast group manager.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ALREADY_EXISTS** | Cannot register the specified client because an entry with the same protocol ID and component ID already exists. |
| **ERROR_CAN_NOT_COMPLETE** | Could not complete the call to this function. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory to complete this operation. |

## Remarks

Registering a protocol is the first operation any multicast routing protocol should perform. After registration, a routing protocol should take ownership of the appropriate interfaces before adding or deleting group memberships.

Only one routing protocol may take ownership of an interface at any given time. Multiple routing protocols may be registered with the multicast group manager, each protocol owning different interfaces.

## See also

[MgmDeRegisterMProtocol](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmderegistermprotocol)

[MgmTakeInterfaceOwnership](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmtakeinterfaceownership)

[ROUTING_PROTOCOL_CONFIG](https://learn.microsoft.com/windows/desktop/api/mgm/ns-mgm-routing_protocol_config)
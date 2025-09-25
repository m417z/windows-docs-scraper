# MprAdminMIBSetTrapInfo function

## Description

The
**MprAdminMIBSetTrapInfo** function specifies a handle to an event that is signaled whenever a TRAP needs to be issued.

## Parameters

### `dwProtocolId` [in]

Specifies a **DWORD** variable that contains the protocol family identifier.

### `dwRoutingPid` [in]

Specifies a **DWORD** variable that contains the identifier of the routing protocol.

### `hEvent` [in]

Handle to an event that is signaled when a trap needs to be issued.

### `lpInData` [in]

Pointer to the input data.

### `dwInDataSize` [in]

Specifies a **DWORD** variable that contains the size in bytes of the data pointed to by *lpInData*.

### `lplpOutData` [out]

Receives the address of a pointer to the output data.

### `lpOutDataSize` [in, out]

On input, pointer to a **DWORD** variable.

On output, receives the size, in bytes, of the data pointed to by ** lplpOutData*.

## Return value

If the functions succeeds, the return value is NO_ERROR

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient privileges. |
| **ERROR_UNKNOWN_PROTOCOL_ID** | The *dwTransportId* value does not match any installed router manager. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |

## See also

[MprAdminMIBGetTrapInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibgettrapinfo)

[Router Management MIB Functions](https://learn.microsoft.com/windows/desktop/RRAS/mib-functions)

[Router Management MIB Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-mib-reference)

[Transport and Protocol Constants](https://learn.microsoft.com/windows/desktop/RRAS/transport-and-protocol-constants)
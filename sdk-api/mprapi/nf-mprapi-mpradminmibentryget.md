# MprAdminMIBEntryGet function

## Description

The
**MprAdminMIBEntryGet** function retrieves the value of one of the variables exported by a routing protocol or router manager.

## Parameters

### `hMibServer` [in]

Handle to the router on which to execute this call. Obtain this handle by calling
[MprAdminMIBServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibserverconnect).

### `dwProtocolId` [in]

Specifies the
[router manager](https://learn.microsoft.com/windows/desktop/RRAS/transport-identifiers) that exported the variable.

### `dwRoutingPid` [in]

Specifies the
[routing protocol](https://learn.microsoft.com/windows/desktop/RRAS/protocol-identifiers) that exported the variable.

### `lpInEntry` [in]

Pointer to an opaque data
[structure](https://learn.microsoft.com/previous-versions/windows/desktop/mib/mib-structures). The data structure's format is determined by the module servicing the call. The data structure should contain information that specifies the variable being queried.

### `dwInEntrySize` [in]

Specifies the size, in bytes, of the data structure pointed to by *lpInEntry*.

### `lplpOutEntry` [out]

Pointer to a pointer variable. On successful return, this pointer variable points to an opaque data
[structure](https://learn.microsoft.com/previous-versions/windows/desktop/mib/mib-structures). The data structure's format is determined by the module servicing the call. The data structure receives the value of the variable that was queried. Free this memory by calling
[MprAdminMIBBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibbufferfree).

### `lpOutEntrySize` [out]

Pointer to a **DWORD** variable that, on successful return, receives the size in bytes of the data structure returned through the *lplpOutEntry* parameter.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following values.

| Value | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient privileges. |
| **ERROR_CANNOT_COMPLETE** | The *dwRoutingPid* variable does not match any installed routing protocol. |
| **ERROR_UNKNOWN_PROTOCOL_ID** | The *dwTransportId* value does not match any installed router manager. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |

## Remarks

Do not pass in **NULL** for the *lpInEntry* parameter because the resulting behavior is undefined.

## See also

[MIB Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mib/mib-structures)

[MprAdminMIBBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibbufferfree)

[MprAdminMIBEntryGetFirst](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibentrygetfirst)

[MprAdminMIBEntryGetNext](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibentrygetnext)

[MprAdminMIBEntrySet](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibentryset)

[MprAdminMIBServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibserverconnect)

[Obtaining the MIB II Interfaces Table](https://learn.microsoft.com/windows/desktop/RRAS/obtaining-the-mib-ii-interfaces-table)

[Protocol Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/protocol-identifiers)

[Router Management MIB Functions](https://learn.microsoft.com/windows/desktop/RRAS/mib-functions)

[Router Management MIB Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-mib-reference)

[Transport Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/transport-identifiers)
# MprAdminMIBEntryCreate function

## Description

The
**MprAdminMIBEntryCreate** function creates an entry for one of the variables exported by a routing protocol or router manager.

## Parameters

### `hMibServer` [in]

Handle to the router on which to execute this call. Obtain this handle by calling
[MprAdminMIBServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibserverconnect).

### `dwPid` [out]

Receives the router manager that exported the variable.

### `dwRoutingPid` [in]

Specifies the routing protocol that exported the variable.

### `lpEntry` [in]

Pointer to an opaque data
[structure](https://learn.microsoft.com/previous-versions/windows/desktop/mib/mib-structures). The data structure's format is determined by the router manager or router manager client servicing the call. The data structure should contain information that specifies the variable being created and the value to assign to the variable.

### `dwEntrySize` [in]

Specifies the size, in bytes, of the data pointed to by the *lpEntry* parameter.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following values.

| Value | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient privileges. |
| **ERROR_CAN_NOT_COMPLETE** | The *dwRoutingPid* variable does not match any installed routing protocol. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **ERROR_UNKNOWN_PROTOCOL_ID** | The *dwTransportId* value does not match any installed router manager. |

## Remarks

Do not pass in **NULL** for the *lpEntry* parameter because the resulting behavior is undefined.

## See also

[MIB Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mib/mib-structures)

[MprAdminMIBEntryDelete](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibentrydelete)

[MprAdminMIBServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibserverconnect)

[Protocol Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/protocol-identifiers)

[Router Management MIB Functions](https://learn.microsoft.com/windows/desktop/RRAS/mib-functions)

[Router Management MIB Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-mib-reference)

[Transport Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/transport-identifiers)
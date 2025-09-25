# MprAdminMIBEntryDelete function

## Description

The
**MprAdminMIBEntryDelete** function deletes an entry for one of the variables exported by a routing protocol or router manager.

## Parameters

### `hMibServer` [in]

Handle to the router on which to execute this call. Obtain this handle by calling
[MprAdminMIBServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibserverconnect).

### `dwProtocolId` [in]

Specifies the router manager that exported the variable.

### `dwRoutingPid` [in]

Specifies the routing protocol that exported the variable.

### `lpEntry` [in]

Pointer to an opaque data
[structure](https://learn.microsoft.com/previous-versions/windows/desktop/mib/mib-structures). The data structure's format is determined by the module servicing the call. The data structure should contain information that specifies the variable to be deleted.

### `dwEntrySize` [in]

Specifies the size, in bytes, of the data pointed to by *lpEntry* parameter.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following values.

| Value | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient privileges. |
| **ERROR_CANNOT_COMPLETE** | The *dwRoutingPid* variable does not match any installed routing protocol. |
| **ERROR_UNKNOWN_PROTOCOL_ID** | The *dwTransportId* value does not match any installed router manager. |

## Remarks

Do not pass in **NULL** for the *lpEntry* parameter because the resulting behavior is undefined.

## See also

[MIB Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mib/mib-structures)

[MprAdminMIBEntryCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibentrycreate)

[MprAdminMIBServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibserverconnect)

[Protocol Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/protocol-identifiers)

[Router Management MIB Functions](https://learn.microsoft.com/windows/desktop/RRAS/mib-functions)

[Router Management MIB Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-mib-reference)

[Transport Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/transport-identifiers)
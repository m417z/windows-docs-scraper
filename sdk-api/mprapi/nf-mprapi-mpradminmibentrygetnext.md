# MprAdminMIBEntryGetNext function

## Description

The
**MprAdminMIBEntryGetNext** function retrieves the next variable of some set of variables exported by a protocol or router manager. The module that services the call defines *next*.

## Parameters

### `hMibServer` [in]

Handle to the router on which to execute this call. This handle is obtained from a previous call to
[MprAdminMIBServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibserverconnect).

### `dwProtocolId` [in]

Specifies the
[router manager](https://learn.microsoft.com/windows/desktop/RRAS/transport-identifiers) that exported the variable.

### `dwRoutingPid` [in]

Specifies the
[routing protocol](https://learn.microsoft.com/windows/desktop/RRAS/protocol-identifiers) that exported the variable.

### `lpInEntry` [in]

Pointer to an opaque data
[structure](https://learn.microsoft.com/previous-versions/windows/desktop/mib/mib-structures). The data structure's format is determined by the module that services the call. The data structure should contain information that specifies the variable being queried.

### `dwInEntrySize` [in]

Specifies the size, in bytes, of the data structure pointed to by *lpInEntry*.

### `lplpOutEntry` [out]

Pointer to a pointer variable. On successful return, this pointer variable points to an opaque data
[structure](https://learn.microsoft.com/previous-versions/windows/desktop/mib/mib-structures). The data structure's format is determined by the module that services the call. The data structure receives the value of the next variable from the set of variables exported. Free this memory by calling
[MprAdminMIBBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibbufferfree).

### `lpOutEntrySize` [out]

Pointer to a **DWORD** variable. This variable receives the size in bytes of the data structure returned through the *lplpOutEntry* parameter.

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

[MprAdminMIBEntryGet](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibentryget)

[MprAdminMIBEntryGetFirst](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibentrygetfirst)

[MprAdminMIBServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibserverconnect)

[Protocol Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/protocol-identifiers)

[Router Management MIB Functions](https://learn.microsoft.com/windows/desktop/RRAS/mib-functions)

[Router Management MIB Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-mib-reference)

[Transport Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/transport-identifiers)
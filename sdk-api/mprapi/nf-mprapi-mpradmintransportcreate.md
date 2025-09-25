# MprAdminTransportCreate function

## Description

The
**MprAdminTransportCreate** function loads a new transport, and starts the router manager for the transport.

## Parameters

### `hMprServer` [in]

Handle to the router on which to set the information. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `dwTransportId` [in]

A **DWORD** value that describes the transport configuration type to set. Acceptable values for *dwTransportId* are listed in the following table.

| Value | Transport (Protocol Family) |
| --- | --- |
| PID_ATALK | AppleTalk |
| PID_IP | Internet Protocol version 4 |
| PID_IPX | Internet Packet Exchange |
| PID_NBF | NetBIOS Frames Protocol |
| PID_IPV6 | Windows Server 2008 or later: Internet Protocol version 6 |

### `lpwsTransportName` [in, optional]

Pointer to a **null**-terminated Unicode string that specifies the name of the transport.

### `pGlobalInfo` [in]

Pointer to a buffer that specifies global information for the transport. Use the
[Information Header Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-information-functions) to manipulate information headers.

### `dwGlobalInfoSize` [in]

Specifies the size, in bytes, of the data pointed to by the *pGlobalInfo* parameter.

### `pClientInterfaceInfo` [in, optional]

Pointer to a buffer that specifies default client interface information for the transport.

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not set the default client interface information.

### `dwClientInterfaceInfoSize` [in, optional]

Specifies the size, in bytes, of the buffer pointed to by the *pClientInterfaceInfo* parameter.

### `lpwsDLLPath` [in]

Pointer to a **null**-terminated Unicode string that specifies the path to the DLL for the transport.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INVALID_PARAMETER** | The *pGlobalInfo* parameter and the *pClientInterfaceInfo* parameter are both **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **ERROR_PROTOCOL_ALREADY_INSTALLED** | The specified transport is already running on the specified router. |
| **ERROR_UNKNOWN_PROTOCOL_ID** | The *dwTransportId* value does not match any supported transport protocol. |

## See also

[MprAdminTransportGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmintransportgetinfo)

[MprAdminTransportSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmintransportsetinfo)
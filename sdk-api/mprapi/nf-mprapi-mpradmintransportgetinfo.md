# MprAdminTransportGetInfo function

## Description

The
**MprAdminTransportGetInfo** function retrieves global information, default client interface information, or both, for a specified transport.

## Parameters

### `hMprServer` [in]

Handle to the router from which information is being retrieved. This handle is obtained from a previous call to
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `dwTransportId` [in]

A **DWORD** value that describes the transport type to retrieve. Acceptable values for *dwTransportId* are listed in the following table.

| Value | Transport (Protocol Family) |
| --- | --- |
| PID_ATALK | AppleTalk |
| PID_IP | Internet Protocol version 4 |
| PID_IPX | Internet Packet Exchange |
| PID_NBF | NetBIOS Frames Protocol |
| PID_IPV6 | Windows Server 2008 or later: Internet Protocol version 6 |

### `ppGlobalInfo` [out, optional]

Pointer to a pointer variable. This variable points to an information header that receives global information for this transport. Use the
[Information Header Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-information-functions) to manipulate information headers.

Free this memory by calling
[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not retrieve the global information.

### `lpdwGlobalInfoSize` [out, optional]

Pointer to a **DWORD** variable. This variable receives the size, in bytes, of the global information for the transport.

### `ppClientInterfaceInfo` [out, optional]

Pointer to a pointer variable. This variable points to default client interface information for this transport. Free this memory by calling
[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree).

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not retrieve the client interface information.

### `lpdwClientInterfaceInfoSize` [out, optional]

Pointer to a **DWORD** variable. This variable receives the size, in bytes, of the client interface information.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INVALID_PARAMETER** | One of the following is true: <br><br>* The *ppGlobalInfo* parameter and the *ppClientInterfaceInfo* parameter are both **NULL**.<br>* The *ppGlobalInfo* parameter does not point to valid memory.<br>* The *ppClientInterfaceInfo* parameter does not point to valid memory. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **ERROR_UNKNOWN_PROTOCOL_ID** | The *dwTransportId* value does not match any installed transport. |

## Remarks

The *ppGlobalInfo* and *ppClientInterfaceInfo* parameters cannot both be **NULL**.

## See also

[MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[MprAdminTransportSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmintransportsetinfo)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)
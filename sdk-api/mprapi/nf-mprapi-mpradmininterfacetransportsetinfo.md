# MprAdminInterfaceTransportSetInfo function

## Description

The
**MprAdminInterfaceTransportSetInfo** function sets information for a transport running on a specified interface.

## Parameters

### `hMprServer` [in]

Handle to the router on which the transport is being set. Obtain the handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hInterface` [in]

Handle to the interface on which the transport is being set. Obtain this handle by calling
[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate).

### `dwTransportId` [in]

A **DWORD** value that describes the transport type to set. Acceptable values for *dwTransportId* are listed in the following table.

| Value | Transport (Protocol Family) |
| --- | --- |
| PID_ATALK | AppleTalk |
| PID_IP | Internet Protocol version 4 |
| PID_IPX | Internet Packet Exchange |
| PID_NBF | NetBIOS Frames Protocol |
| PID_IPV6 | Windows Server 2008 or later: Internet Protocol version 6 |

### `pInterfaceInfo` [in]

Pointer to an information header that contains information for the specified interface and transport. Use the
[Information Header Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-information-functions) to manipulate information headers.

### `dwInterfaceInfoSize` [in]

Specifies the size, in bytes, of the information pointed to by *pInterfaceInfo*.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INVALID_HANDLE** | The *hInterface* value is invalid. |
| **ERROR_INVALID_PARAMETER** | The *pInterfaceInfo* parameter is NULL. |
| **ERROR_NO_SUCH_INTERFACE** | The specified transport is not running on the specified interface. |
| **ERROR_UNKNOWN_PROTOCOL_ID** | The *dwTransportId* value does not match any supported transport. |

## See also

[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate)

[MprAdminInterfaceTransportGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacetransportgetinfo)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)
# MprAdminInterfaceTransportRemove function

## Description

The
**MprAdminInterfaceTransportRemove** function removes a transport (for example, IP or IPX) from a specified interface.

## Parameters

### `hMprServer` [in]

Handle to the router from which the transport is being removed. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hInterface` [in]

Handle to the interface from which the transport is being removed. Obtain this handle by calling
[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate).

### `dwTransportId` [in]

A **DWORD** value that describes the transport type to remove. Acceptable values for *dwTransportId* are listed in the following table.

| Value | Transport (Protocol Family) |
| --- | --- |
| PID_ATALK | AppleTalk |
| PID_IP | Internet Protocol version 4 |
| PID_IPX | Internet Packet Exchange |
| PID_NBF | NetBIOS Frames Protocol |
| PID_IPV6 | Windows Server 2008 or later: Internet Protocol version 6 |

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INTERFACE_CONNECTED** | The interface specified is a demand-dial interface and is currently connected. |
| **ERROR_INVALID_HANDLE** | The *hInterface* value is invalid. |
| **ERROR_NO_SUCH_INTERFACE** | The specified transport is not running on the specified interface. |
| **ERROR_UNKNOWN_PROTOCOL_ID** | The *dwTransportId* value does not match any supported transport. |

## See also

[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate)

[MprAdminInterfaceTransportAdd](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacetransportadd)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)
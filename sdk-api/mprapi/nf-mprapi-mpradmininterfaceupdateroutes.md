# MprAdminInterfaceUpdateRoutes function

## Description

The
**MprAdminInterfaceUpdateRoutes** function requests a specified router manager to update its routing information for a specified interface.

## Parameters

### `hMprServer` [in]

Handle to the router on which information is being updated. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hInterface` [in]

Handle to the interface being updated. Obtain this handle by calling
[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate).

### `dwProtocolId` [in]

A **DWORD** value that specifies which router manager is updating its routing information. The router uses a different router manager for each transport protocol. Acceptable values for *dwTransportId* are listed in the following table.

| Value | Transport (Protocol Family) |
| --- | --- |
| PID_ATALK | AppleTalk |
| PID_IP | Internet Protocol version 4 |
| PID_IPX | Internet Packet Exchange |
| PID_NBF | NetBIOS Frames Protocol |
| PID_IPV6 | Windows Server 2008 or later: Internet Protocol version 6 |

### `hEvent` [in]

Handle to an event that is signaled when the attempt to update routing information for the specified interface has completed. If **NULL**, then the function is synchronous. The calling application must specify **NULL** for this parameter, if *hMprServer* specifies a remote router.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INTERFACE_NOT_CONNECTED** | The specified interface is not connected. Therefore, routes cannot be updated. |
| **ERROR_INVALID_HANDLE** | The *hInterface* value is invalid. |
| **ERROR_NO_SUCH_INTERFACE** | The specified transport is not running on the specified interface. |
| **ERROR_UNKNOWN_PROTOCOL_ID** | The *dwTransportId* value does not match any of the router managers. |
| **ERROR_UPDATE_IN_PROGRESS** | A routing information update operation is already in progress on this interface. |
| **PENDING** | The interface is in the process of updating routing information. The calling application must wait on the event object specified by *hEvent*. After the event is signaled, the status of the update operation can be obtained by calling [MprAdminInterfaceQueryUpdateResult](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacequeryupdateresult). |

## Remarks

The *dwTransportId* parameter specifies both a transport protocol and a unique router manager because the router uses a different router manager for each transport.

## See also

[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate)

[MprAdminInterfaceQueryUpdateResult](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacequeryupdateresult)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)
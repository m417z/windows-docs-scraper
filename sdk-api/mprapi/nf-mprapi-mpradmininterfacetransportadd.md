# MprAdminInterfaceTransportAdd function

## Description

The
**MprAdminInterfaceTransportAdd** function adds a transport (for example, IP or IPX) to a specified interface.

## Parameters

### `hMprServer` [in]

Handle to the router on which information is being added. Obtain this handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hInterface` [in]

Handle to the interface on which the transport is being added. This handle is obtained by a previous call to
[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate).

### `dwTransportId` [in]

A **DWORD** value that describes the transport type to add to the interface. Acceptable values for *dwTransportId* are listed in the following table.

| Value | Transport (Protocol Family) |
| --- | --- |
| PID_ATALK | AppleTalk |
| PID_IP | Internet Protocol version 4 |
| PID_IPX | Internet Packet Exchange |
| PID_NBF | NetBIOS Frames Protocol |
| PID_IPV6 | Windows Server 2008 or later: Internet Protocol version 6 |

### `pInterfaceInfo` [in]

Pointer to an information header that specifies interface information for this transport. Use the
[Information Header Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-information-functions) to manipulate information headers.

### `dwInterfaceInfoSize` [in]

Specifies the size, in bytes, of the information pointed to by *pInterfaceInfo*.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INVALID_HANDLE** | The *hInterface* value is invalid. |
| **ERROR_INVALID_PARAMETER** | The *pInterfaceInfo* parameter is **NULL**. |
| **ERROR_UNKNOWN_PROTOCOL_ID** | The *dwTransportId* value does not match any supported transport. |

## Remarks

The *dwTransportId* parameter also specifies the router manager because a router uses a different router manager for each transport.

## See also

[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate)

[MprAdminInterfaceTransportRemove](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacetransportremove)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)
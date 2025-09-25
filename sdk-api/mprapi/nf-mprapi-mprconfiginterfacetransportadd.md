# MprConfigInterfaceTransportAdd function

## Description

The
**MprConfigInterfaceTransportAdd** function adds a transport protocol to an interface configuration on the router.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `hRouterInterface` [in]

Handle to the interface configuration to which the specified transport is added. Obtain this handle by calling
[MprConfigInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacecreate),
[MprConfigInterfaceGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacegethandle), or
[MprConfigInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfaceenum).

### `dwTransportId` [in]

A **DWORD** value that describes the transport to add to the configuration. This parameter also identifies the router manager for the transport. Acceptable values for *dwTransportId* are listed in the following table.

| Value | Transport (Protocol Family) |
| --- | --- |
| PID_ATALK | AppleTalk |
| PID_IP | Internet Protocol version 4 |
| PID_IPX | Internet Packet Exchange |
| PID_NBF | NetBIOS Frames Protocol |
| PID_IPV6 | Windows Server 2008 or later: Internet Protocol version 6 |

### `lpwsTransportName` [in, optional]

Pointer to a **null**-terminated Unicode string that specifies the name for the transport being added. If this parameter is not specified and the transport is IP or IPX,
**MprConfigInterfaceTransportAdd** uses IP or IPX. If this parameter is not specified and the transport is other than IP or IPX,
**MprConfigInterfaceTransportAdd** converts the *dwTransportId* parameter into a string and uses that as the transport name.

### `pInterfaceInfo` [in]

Pointer to an information header that contains information for the specified interface and transport. The router manager for the specified transport interprets this information. Use the
[Information Header Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-information-functions) to manipulate information headers.

### `dwInterfaceInfoSize` [in]

Specifies the size, in bytes, of the data pointed to by *pInterfaceInfo*.

### `phRouterIfTransport` [out]

A pointer to a
**HANDLE** variable that receives the transport configuration handle type for this interface indicated in the *dwTransportId* parameter.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the following is true: <br><br>* *hMprConfig* is **NULL**.<br>* *hRouterInterface* is **NULL**.<br>* *phRouterIfTransport* is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## Remarks

In addition to specifying a transport, the *dwTransportId* parameter also specifies a router manager, because a router maintains a unique router manager for each transport.

If the specified transport already exists,
**MprConfigInterfaceTransportAdd** does the equivalent of an
[MprConfigInterfaceTransportSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacetransportsetinfo) call using the specified parameter values.

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[Information Header Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-information-functions)

[MPR_IFTRANSPORT_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_iftransport_0)

[MprConfigInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacecreate)

[MprConfigInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfaceenum)

[MprConfigInterfaceGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacegethandle)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)
# MprConfigInterfaceTransportGetHandle function

## Description

The
**MprConfigInterfaceTransportGetHandle** function retrieves a handle to the transport configuration of an interface in the specified router configuration.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `hRouterInterface` [in]

Handle to the interface configuration. Obtain this handle by calling
[MprConfigInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacecreate),
[MprConfigInterfaceGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacegethandle), or
[MprConfigInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfaceenum).

### `dwTransportId` [in]

A **DWORD** value that describes the transport configuration handle type in the *phRouterIfTransport* parameter. Acceptable values for *dwTransportId* are listed in the following table.

| Value | Transport (Protocol Family) |
| --- | --- |
| PID_ATALK | AppleTalk |
| PID_IP | Internet Protocol version 4 |
| PID_IPX | Internet Packet Exchange |
| PID_NBF | NetBIOS Frames Protocol |
| PID_IPV6 | Windows Server 2008 or later: Internet Protocol version 6 |

### `phRouterIfTransport` [out]

A pointer to a
**HANDLE** variable that receives the transport configuration handle type for this interface indicated in the *dwTransportId* parameter.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | At least one of the following is true: <br><br>* *hMprConfig* is **NULL**.<br>* *hRouterInterface* is **NULL**.<br>* *phRouterIfTransport* is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **ERROR_NO_SUCH_INTERFACE** | The interface specified by *hRouterInterface* was not found in the router configuration, or the transport specified by *dwTransportId* was not enabled on the specified interface. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprConfigInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacecreate)

[MprConfigInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfaceenum)

[MprConfigInterfaceGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacegethandle)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)
# MprConfigTransportCreate function

## Description

The
**MprConfigTransportCreate** function adds the specified transport to the list of transport protocols present in the specified router configuration.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration to which to add the transport. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

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

Pointer to a **null**-terminated Unicode string that specifies the name of the transport being added. If this parameter is not specified, the *dwTransportId* parameter is converted into a string and used as the transport name.

### `pGlobalInfo` [in]

Pointer to an information header that specifies global information for the transport. The router manager for the transport interprets this information. Use the
[Information Header Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-information-functions) to manipulate information headers.

### `dwGlobalInfoSize` [in]

Specifies the size, in bytes, of the data pointed to by the *pGlobalInfo* parameter.

### `pClientInterfaceInfo` [in, optional]

Pointer to an information header that specifies default interface information for client routers. This information is used to configure dynamic interfaces for client routers for this transport. Use the
[Information Header Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-information-functions) to manipulate information headers.

This parameter is optional; the calling application can specify **NULL** for this parameter.

### `dwClientInterfaceInfoSize` [in, optional]

Specifies the size, in bytes, of the data pointed to by the *pClientInterfaceInfo* parameter. If the calling application specifies **NULL** for *pClientInterfaceInfo*, the calling application should specify zero for this parameter.

### `lpwsDLLPath` [in, optional]

Pointer to a **null**-terminated Unicode string that specifies the name of the router manager DLL for the specified transport. If this name is specified, the function sets the DLL path for this transport to this name.

This parameter is optional; the calling application can specify **NULL** for this parameter.

### `phRouterTransport` [out]

A pointer to a
**HANDLE** variable that receives the transport configuration handle type indicated in the *dwTransportId* parameter.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *hMprConfig* parameter is **NULL**, or the *phRouterTransport* parameter is **NULL**, or both are **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## Remarks

If the specified transport already exists,
**MprConfigTransportCreate** does the equivalent of an
[MprConfigTransportSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportsetinfo) call using the supplied parameter values.

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)
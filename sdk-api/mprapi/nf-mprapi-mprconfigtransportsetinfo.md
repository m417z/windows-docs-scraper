# MprConfigTransportSetInfo function

## Description

The
**MprConfigTransportSetInfo** function changes the configuration for the specified transport protocol in the specified router configuration.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `hRouterTransport` [in]

Handle to the transport protocol configuration being updated. Obtain this handle by calling
[MprConfigTransportCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportcreate),
[MprConfigTransportGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportgethandle), or
[MprConfigTransportEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportenum). Supported transport protocol types are listed on [Transport Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/transport-identifiers).

### `pGlobalInfo` [in, optional]

Pointer to an information header that specifies global information for the transport protocol. The router manager for the transport interprets this information. Use the
[Information Header Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-information-functions) to manipulate information headers.

This parameter is optional; the calling application may specify **NULL** for this parameter.

### `dwGlobalInfoSize` [in, optional]

Specifies the size, in bytes, of the data pointed to by *pGlobalInfo*. If the calling application specifies **NULL** for *pGlobalInfo*, the calling application should specify zero for this parameter.

### `pClientInterfaceInfo` [in, optional]

Pointer to an information header that specifies default interface information for client routers. The information is used to configure dynamic interfaces for client routers for this transport. Use the
[Information Header Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-information-functions) to manipulate information headers.

This parameter is optional; the calling application can specify **NULL** for this parameter.

### `dwClientInterfaceInfoSize` [in, optional]

Specifies the size, in bytes, of the data pointed to by *pClientInterfaceInfo*. If the calling application specifies **NULL** for *pClientInterfaceInfo*, the calling application should specify zero for this parameter.

### `lpwsDLLPath` [in, optional]

Pointer to a **null**-terminated Unicode string that specifies the name of the router manager DLL for the specified transport.

This parameter is optional; the calling application may specify **NULL** for this parameter.

## Return value

If the function succeeds, the return value is NO_ERROR. For more information, see the Remarks section later in this topic.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *hMprConfig* parameter is **NULL**, the *hRouterTransport* parameter is **NULL**, or both are **NULL**. |
| **ERROR_UNKNOWN_PROTOCOL_ID** | The transport protocol configuration that corresponds to *hRouterTransport* was not found in the router configuration. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## Remarks

Use
**MprConfigTransportSetInfo** to set the transport's global information, default interface information, or the name of the router manager DLL for the transport.

**MprConfigTransportSetInfo** attempts to set the items in the order in which they appear in the parameter list:

1. Global information.
2. Default interface information for client routers.
3. Router manager DLL name.

If
**MprConfigTransportSetInfo** is unable to set any one of the items, it returns immediately without attempting to set the remaining items.

If the *pGlobalInfo*, *pClientInterfaceInfo*, and *lpwsDLLPath* parameters are all **NULL**, the function does nothing, returning a value of NO_ERROR.

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[MprConfigTransportCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportcreate)

[MprConfigTransportEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportenum)

[MprConfigTransportGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportgethandle)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)
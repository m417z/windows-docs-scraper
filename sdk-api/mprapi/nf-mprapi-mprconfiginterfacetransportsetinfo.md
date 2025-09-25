# MprConfigInterfaceTransportSetInfo function

## Description

The
**MprConfigInterfaceTransportSetInfo** function updates the configuration information for the client on the specified interface and transport protocol.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `hRouterInterface` [in]

Handle to the interface configuration in which to update the information. Obtain this handle by calling
[MprConfigInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacecreate) or
[MprConfigInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfaceenum).

### `hRouterIfTransport` [in]

Handle to the transport configuration in which to update the information for the client. Obtain this handle by calling
[MprConfigInterfaceTransportAdd](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacetransportadd),
[MprConfigInterfaceTransportGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacetransportgethandle), or
[MprConfigInterfaceTransportEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacetransportenum). Supported transport protocol types are listed on [Transport Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/transport-identifiers).

### `pInterfaceInfo` [in, optional]

Pointer to an information header that contains configuration information for the client on the specified interface and transport. The router manager for the specified transport interprets this information. Use the
[Information Header Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-information-functions) to manipulate information headers.

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not update the configuration information for the client.

### `dwInterfaceInfoSize` [in, optional]

Specifies the size, in bytes, of the data pointed to by *pInterfaceInfo*.

This parameter is optional; the calling application may specify zero for this parameter. However, if *pInterfaceInfo* is not **NULL**, this parameter cannot be zero. For more information, see the Remarks section later in this topic.

## Return value

If the function succeeds, the return value is NO_ERROR. For more information, see the Remarks section later in this topic.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | At least one of the following is true: <br><br>* *hMprConfig* is **NULL**.<br>* *hRouterInterface* is **NULL**.<br>* *hRouterIfTransport* is **NULL**. |
| **ERROR_NO_SUCH_INTERFACE** | The interface specified by *hRouterInterface* is no longer present in the router configuration, or the transport specified by *hRouterInterface* is no longer present on the interface. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## Remarks

If the *pInterfaceInfo* parameter is **NULL**,
**MprConfigInterfaceTransportSetInfo** does nothing and returns immediately with a value of NO_ERROR.

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprConfigInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacecreate)

[MprConfigInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfaceenum)

[MprConfigInterfaceGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacegethandle)

[MprConfigInterfaceTransportEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacetransportenum)

[MprConfigInterfaceTransportGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacetransportgethandle)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)
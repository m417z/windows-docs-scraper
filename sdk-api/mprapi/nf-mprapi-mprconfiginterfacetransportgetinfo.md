# MprConfigInterfaceTransportGetInfo function

## Description

The
**MprConfigInterfaceTransportGetInfo** function retrieves the configuration information for the specified client on the specified interface.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `hRouterInterface` [in]

Handle to the interface configuration from which to retrieve the specified client information. Obtain this handle by calling
[MprConfigInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacecreate),
[MprConfigInterfaceGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacegethandle), or
[MprConfigInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfaceenum).

### `hRouterIfTransport` [in]

Handle to the transport configuration from which to retrieve the specified client information. Obtain this handle by calling
[MprConfigInterfaceTransportAdd](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacetransportadd),
[MprConfigInterfaceTransportGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacetransportgethandle), or
[MprConfigInterfaceTransportEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacetransportenum). Supported transport protocol types are listed on [Transport Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/transport-identifiers).

### `ppInterfaceInfo` [in, out, optional]

On input, pointer to a pointer variable.

On output, this pointer variable points to an information header that contains configuration information for the client. Use the
[Information Header Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-information-functions) to manipulate information headers. Free this memory by calling
[MprConfigBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigbufferfree).

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not return the configuration information.

### `lpdwInterfaceInfoSize` [out, optional]

Pointer to a **DWORD** variable. This variable receives the size, in bytes, of the data pointed to by *ppInterfaceInfo*.

This parameter is optional; the calling application may specify **NULL** for this parameter. However, if *ppInterfaceInfo* is not **NULL**, this parameter cannot be **NULL**. For more information, see the Remarks section later in this topic.

## Return value

If the function succeeds, the return value is NO_ERROR. For more information, see the Remarks section later in this topic.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the following is true: <br><br>* *hMprConfig* is **NULL**.<br>* *hRouterInterface* is **NULL**.<br>* *hRouterIfTransport* is **NULL**.<br>* *ppInterfaceInfo* is not **NULL**, but *lpdwInterfaceInfoSize* is **NULL**. |
| **ERROR_NO_SUCH_INTERFACE** | The interface specified by *hRouterIfTransport* was not found in the router configuration, or the transport specified by *hRouterIfTransport* was not enabled on the specified interface. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## Remarks

If the *ppInterfaceInfo* parameter is **NULL**,
**MprConfigInterfaceTransportGetInfo** does nothing and returns immediately with a value of NO_ERROR.

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MPR_IFTRANSPORT_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_iftransport_0)

[MprConfigBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigbufferfree)

[MprConfigInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacecreate)

[MprConfigInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfaceenum)

[MprConfigInterfaceGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacegethandle)

[MprConfigInterfaceTransportEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacetransportenum)

[MprConfigInterfaceTransportGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacetransportgethandle)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)
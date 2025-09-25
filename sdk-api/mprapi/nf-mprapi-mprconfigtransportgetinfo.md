# MprConfigTransportGetInfo function

## Description

The
**MprConfigTransportGetInfo** function retrieves the configuration for the specified transport protocol from the router.

## Parameters

### `hMprConfig` [in]

Handle to the router configuration. Obtain this handle by calling
[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect).

### `hRouterTransport` [in]

Handle to the transport protocol configuration being retrieved. Obtain this handle by calling
[MprConfigTransportCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportcreate),
[MprConfigTransportGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportgethandle), or
[MprConfigTransportEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportenum). Supported transport protocol types are listed on [Transport Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/transport-identifiers).

### `ppGlobalInfo` [in, out, optional]

On input, pointer to a pointer variable.

On output, this pointer variable points to an information header that contains global information for the transport. Use the
[Information Header Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-information-functions) to manipulate information headers. Free this buffer by calling
[MprConfigBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigbufferfree).

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not retrieve the global information.

### `lpdwGlobalInfoSize` [out, optional]

Pointer to a **DWORD** variable. This variable receives the size, in bytes, of the buffer returned through the *ppGlobalInfo* parameter.

This parameter is optional; the calling application may specify **NULL** for this parameter. However, if *ppGlobalInfo* is not **NULL**, this parameter cannot be **NULL**.

### `ppClientInterfaceInfo` [in, out, optional]

On input, pointer to a pointer variable.

On output, this pointer points to an information header that contains default interface information for client routers for this transport. Use the
[Information Header Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-information-functions) to manipulate information headers. Free the buffer by calling
[MprConfigBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigbufferfree).

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not retrieve the interface information.

### `lpdwClientInterfaceInfoSize` [out, optional]

Pointer to a **DWORD** variable. This variable receives the size, in bytes, of the buffer returned through the *ppClientInterfaceInfo* parameter.

This parameter is optional; the calling application may specify **NULL** for this parameter. However, if *ppClientInterfaceInfo* is not **NULL**, this parameter cannot be **NULL**.

### `lplpwsDLLPath` [in, out, optional]

On input, pointer to a pointer to a **null**-terminated Unicode string.

On output, the Unicode string receives the name of the router manager DLL for the specified transport.

This parameter is optional. If the calling application specifies **NULL** for this parameter, the function does not retrieve the name of the router manager DLL.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | At least one of the following is true: <br><br>* *hMprConfig* is **NULL**<br>* *hRouterTransport* is **NULL**<br>* *ppGlobalInfo* is not **NULL**, but *lpdwGlobalInfoSize* is **NULL**.<br>* *ppClientInterfaceInfo* is not **NULL**, but *lpdwClientInterfaceInfo* is **NULL**. |
| **ERROR_UNKNOWN_PROTOCOL_ID** | The transport protocol configuration that corresponds to *hRouterTransport* was not found in the router configuration. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## Remarks

If the *pGlobalInfo*, *pClientInterfaceInfo*, and *lpwsDLLPath* parameters are all **NULL**, the function does nothing and returns a value of NO_ERROR.

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[Information Header Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-information-functions)

[MprConfigBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigbufferfree)

[MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect)

[MprConfigTransportCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportcreate)

[MprConfigTransportEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportenum)

[MprConfigTransportGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigtransportgethandle)

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)
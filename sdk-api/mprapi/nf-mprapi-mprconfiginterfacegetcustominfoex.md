# MprConfigInterfaceGetCustomInfoEx function

## Description

Retrieves the custom IKEv2 policy configuration for the specified interface.

## Parameters

### `hMprConfig` [in]

The handle to the router configuration. This handle is obtained by calling the [MprConfigServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigserverconnect) function.

### `hRouterInterface` [in]

The handle to the interface configuration being updated. Obtain this handle by calling the [MprConfigInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacecreate) function, the [MprConfigInterfaceGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfacegethandle) function, or the [MprConfigInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiginterfaceenum) function.

### `pCustomInfo` [out]

A pointer to a [MPR_IF_CUSTOMINFOEX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_if_custominfoex0) structure. When you have finished using the structure, free the buffer by calling the [MprConfigBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfigbufferfree) function.

## Return value

If the function succeeds, the return value is **NO_ERROR**. If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | At least one of the following is true:<br><br>* The *hMprConfig* parameter is **NULL**.<br>* The *hRouterInterface* parameter is **NULL**.<br>* The *pCustomInfo* parameter is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | There were insufficient resources to complete the operation. |
| **ERROR_NO_SUCH_INTERFACE** | The interface that corresponds to *hRouterInterface* parameter is not present in the router configuration. |

## See also

[Router Configuration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-configuration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)
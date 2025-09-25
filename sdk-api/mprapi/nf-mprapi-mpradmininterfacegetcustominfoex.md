# MprAdminInterfaceGetCustomInfoEx function

## Description

Retrieves tunnel-specific configuration for a specified demand dial interface on a specified server.

## Parameters

### `hMprServer` [in]

A handle to the router to query. This handle is obtained by a previous call to the [MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect) function.

### `hInterface` [in]

A handle to the interface. This handle is obtained by a previous call to the [MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate) function.

### `pCustomInfo` [out]

A pointer to a [MPR_IF_CUSTOMINFOEX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_if_custominfoex0) structure. When you have finished using the structure, free the memory by calling the [MprAdminBufferFree](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminbufferfree) function.

## Return value

If the function succeeds, the return value is **NO_ERROR**. If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INVALID_HANDLE** | The *hInterface* value is not valid. |
| **ERROR_INVALID_PARAMETER** | The *hInterface* value is not valid or if the interface type is not **ROUTER_IF_TYPE_FULL_ROUTER**. |
| **ERROR_NOT_ENOUGH_MEMORY** | There were insufficient resources to complete the operation. |

## See also

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)
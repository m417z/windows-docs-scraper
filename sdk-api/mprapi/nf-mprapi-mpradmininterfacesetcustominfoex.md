# MprAdminInterfaceSetCustomInfoEx function

## Description

Sets the tunnel specific custom configuration for a specified demand dial interface on a specified server.

## Parameters

### `hMprServer` [in]

The handle to the router to query. This handle is obtained by a previous call to the [MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect) function.

### `hInterface` [in]

The handle to the interface. This handle is obtained by a previous call to the [MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate) function or the [MprAdminInterfaceGetHandle](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegethandle) function.

### `pCustomInfo` [in]

A pointer to a [MPR_IF_CUSTOMINFOEX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_if_custominfoex0) structure that contains tunnel specific custom configuration.

## Return value

If the function succeeds, the return value is **NO_ERROR**. If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_INVALID_HANDLE** | The *hInterface* value is not valid. |
| **ERROR_INVALID_PARAMETER** | The *pCustomInfo* parameter is **NULL** or the interface type is not **ROUTER_IF_TYPE_FULL_ROUTER**. |
| **ERROR_NOT_ENOUGH_MEMORY** | There were insufficient resources to complete the operation. |

## Remarks

If you need to delete the custom configuration for IKEv2 tunnel of an interface, call the **MprAdminInterfaceSetCustomInfoEx** function with the **dwFlags** member of the [MPR_IF_CUSTOMINFOEX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_if_custominfoex0) structure set to zero.

If you need to delete the IKEv2 main mode and quick mode policy configuration for an interface, set the **customPolicy** parameter of the **customIkev2Config** member in [MPR_IF_CUSTOMINFOEX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_if_custominfoex0) structure to **NULL**.

If you need to delete the certificate configured to be used during IKEv2 main mode SA negotiation, set the **cbData** member of **certificateName** in **customIkev2Config** member of [MPR_IF_CUSTOMINFOEX](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_if_custominfoex0) structure to 0.

## See also

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)
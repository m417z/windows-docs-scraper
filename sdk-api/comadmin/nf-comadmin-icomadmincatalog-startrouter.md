# ICOMAdminCatalog::StartRouter

## Description

Starts the component load balancing service if the service is currently installed.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_SERVICENOTINSTALLED** | The component load balancing service is not currently installed on the computer. |
| **COMADMIN_E_OBJECTERRORS** | Errors occurred while accessing one or more objects. |

## Remarks

When called on a computer acting as the component load balancing (CLB) server, the **StartRouter** method starts up the service; subsequent component activation requests are routed across the application cluster that is defined on the router.

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)
# ICOMAdminCatalog::StopRouter

## Description

Stops the component load balancing service if the service is currently installed.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_SERVICENOTINSTALLED** | The component load balancing service is not currently installed on the computer. |
| **COMADMIN_E_OBJECTERRORS** | Errors occurred while accessing one or more objects. |

## Remarks

When called on a computer acting as the component load balancing (CLB) server, the **StopRouter** method stops the server from routing component activation requests to other servers in the application cluster.

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)
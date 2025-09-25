# ICOMAdminCatalog::ServiceCheck

## Description

Retrieves the current status of the specified COM+ service.

## Parameters

### `lService` [in]

The service for which status is to be checked. This parameter can be COMAdminServiceLoadBalanceRouter
(1) to check the component load balancing service.

### `plStatus` [out, retval]

The status for the specified service.

| Value | Meaning |
| --- | --- |
| **COMAdminServiceStopped**<br><br>0 | The service is stopped. |
| **COMAdminServiceStartPending**<br><br>1 | The service is due to start. |
| **COMAdminServiceStopPending**<br><br>2 | The service is due to stop. |
| **COMAdminServiceRunning**<br><br>3 | The service is running. |
| **COMAdminServiceContinuePending**<br><br>4 | The service is due to continue. |
| **COMAdminServicePausePending**<br><br>5 | The service is due to pause. |
| **COMAdminServicePaused**<br><br>6 | The service is paused. |
| **COMAdminServiceUnknownState**<br><br>7 | The service status is unknown. |

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)
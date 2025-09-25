# RmRestart function

## Description

Restarts applications and services that have been shut down by the [RmShutdown](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmshutdown) function and that have been registered to be restarted using the [RegisterApplicationRestart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrestart) function. This function can only be called by the primary installer that called the [RmStartSession](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmstartsession) function to start the Restart Manager session.

## Parameters

### `dwSessionHandle` [in]

A handle to the existing Restart Manager session.

### `dwRestartFlags`

Reserved. This parameter should be 0.

### `fnStatus` [in, optional]

A pointer to a status message callback function that is used to communicate status while the **RmRestart** function is running. If **NULL**, no status is provided.

## Return value

This is the most recent error received. The function can return one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) that are defined in Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_REQUEST_OUT_OF_SEQUENCE**<br><br>776 | This error value is returned if the [RmRestart](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmrestart) function is called with a valid session handle before calling the [RmShutdown](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmshutdown) function. |
| **ERROR_FAIL_RESTART**<br><br>352 | One or more applications could not be restarted. The [RM_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_process_info) structures that are returned by the [RmGetList](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmgetlist) function contain updated status information. |
| **ERROR_SEM_TIMEOUT**<br><br>121 | A Restart Manager function could not obtain a registry write mutex in the allotted time. A system restart is recommended because further use of the Restart Manager is likely to fail. |
| **ERROR_CANCELLED**<br><br>1223 | This error value is returned by the [RmRestart](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmrestart) function when the request to cancel an operation is successful. |
| **ERROR_BAD_ARGUMENTS**<br><br>160 | One or more arguments are not correct. This error value is returned by the Restart Manager function if a **NULL** pointer or 0 is passed in a parameter that requires a non-**null** and non-zero value. |
| **ERROR_WRITE_FAULT**<br><br>29 | An operation was unable to read or write to the registry. |
| **ERROR_OUTOFMEMORY**<br><br>14 | A Restart Manager operation could not complete because not enough memory was available. |
| **ERROR_INVALID_HANDLE**<br><br>6 | No Restart Manager session exists for the handle supplied. |
| **ERROR_SUCCESS**<br><br>0 | The function succeeds and returns. |

## Remarks

After calling the **RmRestart** function, the [RM_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_process_info) structures that are returned by the [RmGetList](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmgetlist) function contain updated status information.

The Restart Manager respects the privileges that separate different user or terminal sessions. An installer that is running as a service with LocalSystem privileges cannot shut down or restart any applications in another user or terminal session. Installers should implement custom methods to shut down and restart applications that are running in other sessions. One method would be to start a new installer process in the other session to perform shutdown and restart operations.

When a console application is shut down and restarted by Restart Manager, the application is restarted in a new console.

Installers should always restart application and services using the **RmRestart** function even when the [RmShutdown](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmshutdown) function returns an error indicating that not all applications and services could be shut down.

The **RmRestart** function does not restart any applications that run with elevated privileges. Even if the application was shutdown by Restart Manager.

 The **RmRestart** function does not restart any applications that do not run as the currently-logged on user. Even if the application was shutdown by Restart Manager. For example, the **RmRestart** function does not restart applications started with the **Run As** command that do not run as the currently-logged on user. These applications must be manually restarted.

## See also

[RegisterApplicationRestart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrestart)

[RmCancelCurrentTask](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmcancelcurrenttask)

[RmShutdown](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmshutdown)
# RmShutdown function

## Description

Initiates the shutdown of applications. This function can only be called from the installer that started the Restart Manager session using the [RmStartSession](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmstartsession) function.

## Parameters

### `dwSessionHandle` [in]

A handle to an existing Restart Manager session.

### `lActionFlags` [in]

One or more [RM_SHUTDOWN_TYPE](https://learn.microsoft.com/windows/desktop/api/restartmanager/ne-restartmanager-rm_shutdown_type) options that configure the shut down of components. The following values can be combined by an OR operator to specify that unresponsive applications and services are to be forced to shut down if, and only if, all applications have been registered for restart.

| Value | Meaning |
| --- | --- |
| **RmForceShutdown**<br><br>0x1 | Force unresponsive applications and services to shut down after the timeout period. An application that does not respond to a shutdown request is forced to shut down within 30 seconds. A service that does not respond to a shutdown request is forced to shut down after 20 seconds. |
| **RmShutdownOnlyRegistered**<br><br>0x10 | Shut down applications if and only if all the applications have been registered for restart using the [RegisterApplicationRestart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrestart) function. If any processes or services cannot be restarted, then no processes or services are shut down. |

### `fnStatus` [in, optional]

A pointer to an [RM_WRITE_STATUS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/restartmanager/nc-restartmanager-rm_write_status_callback) function that is used to communicate detailed status while this function is executing. If **NULL**, no status is provided.

## Return value

This is the most recent error received. The function can return one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) that are defined in Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | All shutdown, restart, and callback operations were successfully completed. |
| **ERROR_FAIL_NOACTION_REBOOT**<br><br>350 | No shutdown actions were performed. One or more processes or services require a restart of the system to be shut down. This error code is returned when the Restart Manager detects that a restart of the system is required before shutting down any application. |
| **ERROR_FAIL_SHUTDOWN**<br><br>351 | Some applications could not be shut down. The **AppStatus** of the [RM_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_process_info) structures returned by the [RmGetList](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmgetlist) function contain updated status information. |
| **ERROR_CANCELLED**<br><br>1223 | This error value is returned by the [RmShutdown](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmshutdown) function when the request to cancel an operation is successful. |
| **ERROR_SEM_TIMEOUT**<br><br>121 | A Restart Manager function could not obtain a Registry write mutex in the allotted time. A system restart is recommended because further use of the Restart Manager is likely to fail. |
| **ERROR_BAD_ARGUMENTS**<br><br>160 | One or more arguments are not correct. This error value is returned by the Restart Manager function if a **NULL** pointer or 0 is passed in a parameter that requires a non-**null** and non-zero value. |
| **ERROR_WRITE_FAULT**<br><br>29 | An operation was unable to read or write to the registry. |
| **ERROR_OUTOFMEMORY**<br><br>14 | A Restart Manager operation could not be completed because not enough memory is available. |
| **ERROR_INVALID_HANDLE**<br><br>6 | No Restart Manager session exists for the handle supplied. |

## Remarks

The **RmShutdown** function calls [RmGetList](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmgetlist) and updates the list of processes currently using registered resources before attempting to shut down any processes. The **RmShutdown** function then attempts to shut down the processes using registered resources in the most current list. The **RmShutdown** function updates the **AppStatus** member of the [RM_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_process_info) structures that are returned by the **RmGetList** function with detailed status information.

The Restart Manager respects the privileges that separate different user or terminal sessions. An installer that is running as a service with LocalSystem privileges cannot shut down or restart any applications in another user or terminal session. Installers should implement custom methods to shut down and restart applications that are running in other sessions. One method would be to start a new installer process in the other session to perform shutdown and restart operations.

Installers should always restart application and services using the [RmRestart](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmrestart) function even when the **RmShutdown** function returns an error indicating that not all applications and services could be shut down.

## See also

[RegisterApplicationRestart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrestart)

[RmCancelCurrentTask](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmcancelcurrenttask)

[RmRestart](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmrestart)
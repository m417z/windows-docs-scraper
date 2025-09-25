# ExitWindowsEx function

## Description

Logs off the interactive user, shuts down the system, or shuts down and restarts the system. It sends the
[WM_QUERYENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-queryendsession) message to all applications to determine if they can be terminated.

## Parameters

### `uFlags` [in]

The shutdown type. This parameter must include one of the following values.

| Value | Meaning |
| --- | --- |
| **EWX_HYBRID_SHUTDOWN**<br><br>0x00400000 | **Beginning with Windows 8:** You can prepare the system for a faster startup by combining the **EWX_HYBRID_SHUTDOWN** flag with the **EWX_SHUTDOWN** flag. |
| **EWX_LOGOFF**<br><br>0 | Shuts down all processes running in the logon session of the process that called the **ExitWindowsEx** function. Then it logs the user off.<br><br>This flag can be used only by processes running in an interactive user's logon session. |
| **EWX_POWEROFF**<br><br>0x00000008 | Shuts down the system and turns off the power. The system must support the power-off feature. <br><br>The calling process must have the SE_SHUTDOWN_NAME privilege. For more information, see the following Remarks section. |
| **EWX_REBOOT**<br><br>0x00000002 | Shuts down the system and then restarts the system. <br><br>The calling process must have the SE_SHUTDOWN_NAME privilege. For more information, see the following Remarks section. |
| **EWX_RESTARTAPPS**<br><br>0x00000040 | Shuts down the system and then restarts it, as well as any applications that have been registered for restart using the [RegisterApplicationRestart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrestart) function. These application receive the [WM_QUERYENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-queryendsession) message with *lParam* set to the ENDSESSION_CLOSEAPP value. For more information, see [Guidelines for Applications](https://learn.microsoft.com/windows/desktop/RstMgr/guidelines-for-applications). |
| **EWX_SHUTDOWN**<br><br>0x00000001 | Shuts down the system to a point at which it is safe to turn off the power. All file buffers have been flushed to disk, and all running processes have stopped. <br><br>The calling process must have the SE_SHUTDOWN_NAME privilege. For more information, see the following Remarks section.<br><br>Specifying this flag will not turn off the power even if the system supports the power-off feature. You must specify EWX_POWEROFF to do this.**Windows XP with SP1:** If the system supports the power-off feature, specifying this flag turns off the power. |

This parameter can optionally include one of the following values.

| Value | Meaning |
| --- | --- |
| **EWX_FORCE**<br><br>0x00000004 | This flag has no effect if terminal services is enabled. Otherwise, the system does not send the [WM_QUERYENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-queryendsession) message. This can cause applications to lose data. Therefore, you should only use this flag in an emergency. |
| **EWX_FORCEIFHUNG**<br><br>0x00000010 | Forces processes to terminate if they do not respond to the [WM_QUERYENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-queryendsession) or [WM_ENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-endsession) message within the timeout interval. For more information, see the Remarks. |

### `dwReason` [in]

The reason for initiating the shutdown. This parameter must be one of the
[system shutdown reason codes](https://learn.microsoft.com/windows/desktop/Shutdown/system-shutdown-reason-codes).

If this parameter is zero, the SHTDN_REASON_FLAG_PLANNED reason code will not be set and therefore the default action is an undefined shutdown that is logged as "No title for this reason could be found". By default, it is also an unplanned shutdown. Depending on how the system is configured, an unplanned shutdown triggers the creation of a file that contains the system state information, which can delay shutdown. Therefore, do not use zero for this parameter.

## Return value

If the function succeeds, the return value is nonzero. Because the function executes asynchronously, a nonzero return value indicates that the shutdown has been initiated. It does not indicate whether the shutdown will succeed. It is possible that the system, the user, or another application will abort the shutdown.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**ExitWindowsEx** function returns as soon as it has initiated the shutdown process. The shutdown or logoff then proceeds asynchronously. The function is designed to stop all processes in the caller's logon session. Therefore, if you are not the interactive user, the function can succeed without actually shutting down the computer. If you are not the interactive user, use the
[InitiateSystemShutdown](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-initiatesystemshutdowna) or
[InitiateSystemShutdownEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-initiatesystemshutdownexa) function.

A non-zero return value does not mean the logoff was or will be successful. The shutdown is an asynchronous process, and it can occur long after the API call has returned, or not at all. Even if the timeout value is zero, the shutdown can still be aborted by applications, services, or even the system. The non-zero return value indicates that the validation of the rights and parameters was successful and that the system accepted the shutdown request.

When this function is called, the caller must specify whether or not applications with unsaved changes should be forcibly closed. If the caller chooses not to force these applications to close and an application with unsaved changes is running on the console session, the shutdown will remain in progress until the user logged into the console session aborts the shutdown, saves changes, closes the application, or forces the application to close. During this period, the shutdown may not be aborted except by the console user, and another shutdown may not be initiated.

Calling this function with the value of the *uFlags* parameter set to EWX_FORCE avoids this situation. Remember that doing this may result in loss of data.

To set a shutdown priority for an application relative to other applications in the system, use the
[SetProcessShutdownParameters](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessshutdownparameters) function.

During a shutdown or log-off operation, running applications are allowed a specific amount of time to respond to the shutdown request. If this time expires before all applications have stopped, the system displays a user interface that allows the user to forcibly shut down the system or to cancel the shutdown request. If the EWX_FORCE value is specified, the system forces running applications to stop when the time expires.

If the EWX_FORCEIFHUNG value is specified, the system forces hung applications to close and does not display the dialog box.

Console processes receive a separate notification message, CTRL_SHUTDOWN_EVENT or CTRL_LOGOFF_EVENT, as the situation warrants. A console process routes these messages to its
[HandlerRoutine](https://learn.microsoft.com/windows/console/handlerroutine) function.
**ExitWindowsEx** sends these notification messages asynchronously; thus, an application cannot assume that the console notification messages have been handled when a call to
**ExitWindowsEx** returns.

To shut down or restart the system, the calling process must use the
[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges) function to enable the SE_SHUTDOWN_NAME privilege. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

#### Examples

For an example, see
[How to Shut Down the System](https://learn.microsoft.com/windows/desktop/Shutdown/how-to-shut-down-the-system).

## See also

[AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges)

[HandlerRoutine](https://learn.microsoft.com/windows/console/handlerroutine)

[Logging Off](https://learn.microsoft.com/windows/desktop/Shutdown/logging-off)

[SetProcessShutdownParameters](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessshutdownparameters)

[Shutting Down](https://learn.microsoft.com/windows/desktop/Shutdown/shutting-down)

[System Shutdown
Functions](https://learn.microsoft.com/windows/desktop/Shutdown/system-shutdown-functions)
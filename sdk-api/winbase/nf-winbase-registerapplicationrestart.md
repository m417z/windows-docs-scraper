# RegisterApplicationRestart function

## Description

Registers the active instance of an application for restart.

## Parameters

### `pwzCommandline` [in, optional]

A pointer to a Unicode string that specifies the command-line arguments for the application when it is restarted. The maximum size of the command line that you can specify is RESTART_MAX_CMD_LINE characters. Do not include the name of the executable in the command line; this function adds it for you.

If this parameter is **NULL** or an empty string, the previously registered command line is removed. If the argument contains spaces, use quotes around the argument.

### `dwFlags` [in]

This parameter can be 0 or one or more of the following values.

| Value | Meaning |
| --- | --- |
| **RESTART_NO_CRASH**<br><br>1 | Do not restart the process if it terminates due to an unhandled exception. |
| **RESTART_NO_HANG**<br><br>2 | Do not restart the process if it terminates due to the application not responding. |
| **RESTART_NO_PATCH**<br><br>4 | Do not restart the process if it terminates due to the installation of an update. |
| **RESTART_NO_REBOOT**<br><br>8 | Do not restart the process if the computer is restarted as the result of an update. |

## Return value

This function returns **S_OK** on success or one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Internal error. |
| **E_INVALIDARG** | The specified command line is too long. |

## Remarks

Your initial registration for restart must occur before the application encounters an unhandled exception or becomes unresponsive. You could then call this function from inside your recovery callback to update the command line.

For a Windows application that is being updated, the last opportunity to call this function is while processing the [WM_QUERYENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-queryendsession) message. For a console application that is being updated, the registration must occur before the installer tries to shutdown the application (you need to keep the registration current; you cannot call this function when handling the CTRL_C_EVENT notification).

If you register for restart and the application encounters an unhandled exception or is not responsive, the user is offered the opportunity to restart the application; the application is not automatically restarted without the user's consent. However, if the application is being updated and requires a restart, the application is restarted automatically.

To prevent cyclical restarts, the system will only restart the application if it has been
running for a minimum of 60 seconds.

Note that for an application to be restarted when the update requires a computer restart, the installer must call the [ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex) function with the EWX_RESTARTAPPS flag set or the [InitiateShutdown](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-initiateshutdowna) function with the SHUTDOWN_RESTARTAPPS flag set.

## See also

[UnregisterApplicationRestart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-unregisterapplicationrestart)
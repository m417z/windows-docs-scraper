# AbortSystemShutdownA function

## Description

Stops a system shutdown that has been initiated.

## Parameters

### `lpMachineName` [in, optional]

The network name of the computer where the shutdown is to be stopped. If *lpMachineName* is **NULL** or an empty string, the function stops the shutdown on the local computer.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
[InitiateSystemShutdown](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-initiatesystemshutdowna) and
[InitiateSystemShutdownEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-initiatesystemshutdownexa) functions display a dialog box that notifies the user that the system is shutting down. During the shutdown time-out period, the
**AbortSystemShutdown** function can prevent the system from shutting down.

**Windows Server 2003 and Windows XP with SP1:** If the computer to be shut down is a Terminal Services server, the system displays a dialog box to all local and remote users warning them that shutdown has been initiated. If shutdown is prevented by
**AbortSystemShutdown**, the system displays dialog box to the users informing them that the server is no longer shutting down.

To stop the local computer from shutting down, the calling process must have the SE_SHUTDOWN_NAME privilege. To stop a remote computer from shutting down, the calling process must have the SE_REMOTE_SHUTDOWN_NAME privilege on the remote computer. By default, users can enable the SE_SHUTDOWN_NAME privilege on the computer they are logged onto, and administrators can enable the SE_REMOTE_SHUTDOWN_NAME privilege on remote computers. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

Common reasons for failure include an invalid computer name, an inaccessible computer, or insufficient privilege.

#### Examples

For an example, see
[Displaying the Shutdown Dialog Box](https://learn.microsoft.com/windows/desktop/Shutdown/displaying-the-shutdown-dialog-box).

> [!NOTE]
> The winreg.h header defines AbortSystemShutdown as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[InitiateSystemShutdown](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-initiatesystemshutdowna)

[Shutting Down](https://learn.microsoft.com/windows/desktop/Shutdown/shutting-down)

[System Shutdown
Functions](https://learn.microsoft.com/windows/desktop/Shutdown/system-shutdown-functions)
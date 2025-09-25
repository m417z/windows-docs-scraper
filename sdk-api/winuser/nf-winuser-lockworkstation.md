# LockWorkStation function

## Description

Locks the workstation's display. Locking a workstation protects it from unauthorized use.

## Return value

If the function succeeds, the return value is nonzero. Because the function executes asynchronously, a nonzero return value indicates that the operation has been initiated. It does not indicate whether the workstation has been successfully locked.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**LockWorkStation** function is callable only by processes running on the interactive desktop. In addition, the user must be logged on, and the workstation cannot already be locked.

Common reasons the workstation might not be locked even if the function succeeds include the following: no user is logged on, the workstation is already locked, the process is not running on the interactive desktop, or the request is denied by the Graphical Identification and Authentication (GINA) DLL.

This function has the same result as pressing Ctrl+Alt+Del and clicking **Lock**. To unlock the workstation, the user must log in. There is no function you can call to determine whether the workstation is locked. To receive a notification when the user locks the workstation or logs in, use the [WTSRegisterSessionNotification](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsregistersessionnotification) function to receive [WM_WTSSESSION_CHANGE](https://learn.microsoft.com/windows/desktop/TermServ/wm-wtssession-change) messages. You can use session notifications to track the desktop state so you know whether it is possible to interact with the user.

#### Examples

For an example, see
[How to Lock the Workstation](https://learn.microsoft.com/windows/desktop/Shutdown/how-to-lock-the-workstation).

## See also

[System Shutdown Functions](https://learn.microsoft.com/windows/desktop/Shutdown/system-shutdown-functions)
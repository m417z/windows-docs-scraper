# CancelWaitableTimer function

## Description

Sets the specified waitable timer to the inactive state.

## Parameters

### `hTimer` [in]

A handle to the timer object. The
[CreateWaitableTimer](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createwaitabletimerw) or
[OpenWaitableTimer](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-openwaitabletimerw) function returns this handle. The handle must have the **TIMER_MODIFY_STATE** access right. For more information, see
[Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**CancelWaitableTimer** function does not change the signaled state of the timer. It stops the timer before it can be set to the signaled state and cancels outstanding APCs. Therefore, threads performing a wait operation on the timer remain waiting until they time out or the timer is reactivated and its state is set to signaled. If the timer is already in the signaled state, it remains in that state.

To reactivate the timer, call the
[SetWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setwaitabletimer) function.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0400 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[CreateWaitableTimer](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createwaitabletimerw)

[OpenWaitableTimer](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-openwaitabletimerw)

[SetWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setwaitabletimer)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Waitable Timer Objects](https://learn.microsoft.com/windows/desktop/Sync/waitable-timer-objects)
# UnregisterWait function

## Description

Cancels a registered wait operation issued by the
[RegisterWaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerwaitforsingleobject) function.

To use a completion event, call the
[UnregisterWaitEx](https://learn.microsoft.com/windows/desktop/Sync/unregisterwaitex) function.

## Parameters

### `WaitHandle` [in]

The wait handle. This handle is returned by the
[RegisterWaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerwaitforsingleobject) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If any callback functions associated with the timer have not completed when **UnregisterWait** is called, **UnregisterWait** unregisters the wait on the callback functions and fails with the **ERROR_IO_PENDING** error code. The error code does not indicate that the function has failed, and the function does not need to be called again. If your code requires an error code to set only when the unregister operation has failed, call [UnregisterWaitEx](https://learn.microsoft.com/windows/desktop/Sync/unregisterwaitex) instead.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[RegisterWaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerwaitforsingleobject)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Thread Pooling](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pooling)

[UnregisterWaitEx](https://learn.microsoft.com/windows/desktop/Sync/unregisterwaitex)
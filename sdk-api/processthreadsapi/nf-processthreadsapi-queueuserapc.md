# QueueUserAPC function

## Description

Adds a user-mode [asynchronous procedure call](https://learn.microsoft.com/windows/win32/sync/asynchronous-procedure-calls) (APC) object to the APC queue of the specified thread.

## Parameters

### `pfnAPC` [in]

A pointer to the application-supplied APC function to be called when the specified thread performs an alertable wait operation. For more information, see [PAPCFUNC callback function](https://learn.microsoft.com/windows/win32/api/winnt/nc-winnt-papcfunc).

### `hThread` [in]

A handle to the thread. The handle must have the **THREAD_SET_CONTEXT** access right. For more information, see [Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

### `dwData` [in]

A single value that is passed to the APC function pointed to by the *pfnAPC* parameter.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). **Windows Server 2003 and Windows XP:** There are no error values defined for this function that can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

See [QueueUserAPC2 function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-queueuserapc2) for information on special user-mode APCs.

The APC support provided in the operating system allows an application to queue an APC object to a thread. To ensure successful execution of functions used by the APC, APCs should be queued only to threads in the caller's process.

>[!NOTE]
> Queuing APCs to threads outside the caller's process is not recommended for a number of reasons. DLL rebasing can cause the addresses of functions used by the APC to be incorrect when the functions are executed outside the caller's process. Similarly, if a 64-bit process queues an APC to a 32-bit process or vice versa, addresses will be incorrect and the application will crash. Other factors can prevent successful function execution, even if the address is known.

Each thread has its own APC queue. The queuing of an APC is a request for the thread to call the APC function. The operating system issues a software interrupt to direct the thread to call the APC function.

When a user-mode APC is queued, the thread is not directed to call the APC function unless it is in an alertable state. After the thread is in an alertable state, the thread handles all pending APCs in first in, first out (FIFO) order, and the wait operation returns **WAIT_IO_COMPLETION**. A thread enters an alertable state by using [SleepEx function](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-sleepex), [SignalObjectAndWait function](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-signalobjectandwait), [WaitForSingleObjectEx function](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitforsingleobjectex), [WaitForMultipleObjectsEx function](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-waitformultipleobjectsex), or [MsgWaitForMultipleObjectsEx function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-msgwaitformultipleobjectsex).

If an application queues an APC before the thread begins running, the thread begins by calling the APC function. After the thread calls an APC function, it calls the APC functions for all APCs in its APC queue.

It is possible to sleep or wait for an object within the APC. If you perform an alertable wait inside an APC, it will recursively dispatch the APCs. This can cause a stack overflow.

When the thread is terminated using the [ExitThread function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitthread) or [TerminateThread function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-terminatethread) function, the APCs in its APC queue are lost. The APC functions are not called.

When the thread is in the process of being terminated, calling QueueUserAPC to add to the thread's APC queue will fail with **(31) ERROR_GEN_FAILURE**.

Note that the [ReadFileEx function](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfileex), [SetWaitableTimer function](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-setwaitabletimer), and [WriteFileEx function](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefileex) functions are implemented using an APC as the completion notification callback mechanism.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0400 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

- [PAPCFUNC callback function](https://learn.microsoft.com/windows/win32/api/winnt/nc-winnt-papcfunc)
- [Asynchronous Procedure Calls](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls)
- [Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)
# QueueUserWorkItem function

## Description

Queues a work item to a worker thread in the
[thread pool](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pooling).

## Parameters

### `Function` [in]

A pointer to the application-defined callback function of type **LPTHREAD_START_ROUTINE** to be executed by the thread in the thread pool. This value represents the starting address of the thread. This callback function must not call the
[TerminateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-terminatethread) function.

The return value of the callback function is not used.

For more information, see
[ThreadProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms686736(v=vs.85)).

### `Context` [in, optional]

A single parameter value to be passed to the thread function.

### `Flags` [in]

The flags that control execution. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **WT_EXECUTEDEFAULT**<br><br>0x00000000 | By default, the callback function is queued to a non-I/O worker thread.<br><br>The callback function is queued to a thread that uses I/O completion ports, which means they cannot perform an alertable wait. Therefore, if I/O completes and generates an APC, the APC might wait indefinitely because there is no guarantee that the thread will enter an alertable wait state after the callback completes. |
| **WT_EXECUTEINIOTHREAD**<br><br>0x00000001 | This flag is not used.<br><br>**Windows Server 2003 and Windows XP:** The callback function is queued to an I/O worker thread. This flag should be used if the function should be executed in a thread that waits in an alertable state. <br><br>I/O worker threads were removed starting with Windows Vista and Windows Server 2008. |
| **WT_EXECUTEINPERSISTENTTHREAD**<br><br>0x00000080 | The callback function is queued to a thread that never terminates. It does not guarantee that the same thread is used each time. This flag should be used only for short tasks or it could affect other timer operations. <br><br>This flag must be set if the thread calls functions that use APCs. For more information, see [Asynchronous Procedure Calls](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls).<br><br>Note that currently no worker thread is truly persistent, although worker threads do not terminate if there are any pending I/O requests. |
| **WT_EXECUTELONGFUNCTION**<br><br>0x00000010 | The callback function can perform a long wait. This flag helps the system to decide if it should create a new thread. |
| **WT_TRANSFER_IMPERSONATION**<br><br>0x00000100 | Callback functions will use the current access token, whether it is a process or impersonation token. If this flag is not specified, callback functions execute only with the process token.<br><br>**Windows XP:** This flag is not supported until Windows XP SP2 and Windows Server 2003. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If a function in a DLL is queued to a worker thread, be sure that the function has completed execution before the DLL is unloaded.

By default, the thread pool has a maximum of 512 threads per process. To raise the queue limit, use the **WT_SET_MAX_THREADPOOL_THREAD** macro defined in WinNT.h.

``` syntax
#define WT_SET_MAX_THREADPOOL_THREADS(Flags,Limit) \
    ((Flags)|=(Limit)<<16)
```

Use this macro in the call to **QueueUserWorkItem** to specify the *Flags* parameter. The macro parameters are the desired flags and the new limit, up to (2<<16)-1 threads. However, the size of the queue is limited by the size of the kernel nonpaged pool. Note that your application can improve its performance by keeping the number of worker threads low.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Thread Pooling](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pooling)

[ThreadProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms686736(v=vs.85))
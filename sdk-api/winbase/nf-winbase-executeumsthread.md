# ExecuteUmsThread function

## Description

Runs the specified UMS worker thread.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Parameters

### `UmsThread` [in, out]

A pointer to the UMS thread context of the worker thread to run.

## Return value

If the function succeeds, it does not return a value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_RETRY** | The specified UMS worker thread is temporarily locked by the system. The caller can retry the operation. |
| **ERROR_NOT_SUPPORTED** | UMS is not supported. |

## Remarks

The **ExecuteUmsThread** function loads the state of the specified UMS worker thread over the state of the calling UMS scheduler thread so that the worker thread can run. The worker thread runs until it yields by calling the [UmsThreadYield](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-umsthreadyield) function, blocks, or terminates.

When a worker thread yields or blocks, the system calls the scheduler thread's [UmsSchedulerProc](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-rtl_ums_scheduler_entry_point) entry point function. When a previously blocked worker thread becomes unblocked, the system queues the worker thread to the completion list specified with the [UpdateProcThreadAttribute](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-updateprocthreadattribute) function when the worker thread was created.

The **ExecuteUmsThread** function does not return unless an error occurs. If the function returns ERROR_RETRY, the error is transitory and the operation can be retried.

If the function returns an error other than ERROR_RETRY, the application's scheduler should check whether the thread is suspended or terminated by calling [QueryUmsThreadInformation](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryumsthreadinformation) with **UmsThreadIsSuspended** or **UmsThreadIsTerminated**, respectively. Other possible errors include calling the function on a thread that is not a UMS scheduler thread, passing an invalid UMS worker thread context, or specifying a worker thread that is already executing on another scheduler thread.

## See also

[UmsSchedulerProc](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-rtl_ums_scheduler_entry_point)

[UmsThreadYield](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-umsthreadyield)

[UpdateProcThreadAttribute](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-updateprocthreadattribute)
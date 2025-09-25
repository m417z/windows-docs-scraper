# EnterUmsSchedulingMode function

## Description

Converts the calling thread into a user-mode scheduling (UMS) scheduler thread.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Parameters

### `SchedulerStartupInfo` [in]

A pointer to a [UMS_SCHEDULER_STARTUP_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-ums_scheduler_startup_info) structure that specifies UMS attributes for the thread, including a completion list and a [UmsSchedulerProc](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-rtl_ums_scheduler_entry_point) entry point function.

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An application's UMS scheduler creates one UMS scheduler thread for each processor that will be used to run UMS threads. The scheduler typically sets the affinity of the scheduler thread for a single processor, effectively reserving the processor for the use of that scheduler thread. For more information about thread affinity, see [Multiple Processors](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-processors).

When a UMS scheduler thread is created, the system calls the [UmsSchedulerProc](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-rtl_ums_scheduler_entry_point) entry point function specified with the **EnterUmsSchedulingMode** function call. The application's scheduler is responsible for finishing any application-specific initialization of the scheduler thread and selecting a UMS worker thread to run.

The application's scheduler selects a UMS worker thread to run by calling [ExecuteUmsThread](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-executeumsthread) with the worker thread's UMS thread context. The worker thread runs until it yields control by calling [UmsThreadYield](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-umsthreadyield), blocks, or terminates. The scheduler thread is then available to run another worker thread.

A scheduler thread should continue to run until all of its worker threads reach a natural stopping point: that is, all worker threads have yielded, blocked, or terminated.

## See also

[ExecuteUmsThread](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-executeumsthread)

[Multiple Processors](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-processors)

[UMS_SCHEDULER_STARTUP_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-ums_scheduler_startup_info)

[UmsSchedulerProc](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-rtl_ums_scheduler_entry_point)

[User-Mode Scheduling](https://learn.microsoft.com/windows/desktop/ProcThread/user-mode-scheduling)
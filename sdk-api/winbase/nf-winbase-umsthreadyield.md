# UmsThreadYield function

## Description

Yields control to the user-mode scheduling (UMS) scheduler thread on which the calling UMS worker thread is running.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Parameters

### `SchedulerParam` [in]

A parameter to pass to the scheduler thread's [UmsSchedulerProc](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-rtl_ums_scheduler_entry_point) function.

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A UMS worker thread calls the **UmsThreadYield** function to cooperatively yield control to the UMS scheduler thread on which the worker thread is running. If a UMS worker thread never calls **UmsThreadYield**, the worker thread runs until it either blocks or is terminated.

When control switches to the UMS scheduler thread, the system calls the associated scheduler entry point function with the reason **UmsSchedulerThreadYield** and the *ScheduleParam* parameter specified by the worker thread in the **UmsThreadYield** call.

The application's scheduler is responsible for rescheduling the worker thread.

## See also

[UmsSchedulerProc](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-rtl_ums_scheduler_entry_point)
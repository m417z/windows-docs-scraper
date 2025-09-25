# UMS_SCHEDULER_STARTUP_INFO structure

## Description

Specifies attributes for a user-mode scheduling (UMS) scheduler thread. The [EnterUmsSchedulingMode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enterumsschedulingmode) function uses this structure.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Members

### `UmsVersion`

The UMS version for which the application was built. This parameter must be **UMS_VERSION**.

### `CompletionList`

A pointer to a UMS completion list to associate with the calling thread.

### `SchedulerProc`

A pointer to an application-defined [UmsSchedulerProc](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-rtl_ums_scheduler_entry_point) entry point function. The system calls this function when the calling thread has been converted to UMS and is ready to run UMS worker threads. Subsequently, it calls this function when a UMS worker thread running on the calling thread yields or blocks.

### `SchedulerParam`

An application-defined parameter to pass to the specified [UmsSchedulerProc](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-rtl_ums_scheduler_entry_point) function.
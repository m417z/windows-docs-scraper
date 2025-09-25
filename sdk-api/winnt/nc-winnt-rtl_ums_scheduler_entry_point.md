# RTL_UMS_SCHEDULER_ENTRY_POINT callback function

## Description

The application-defined user-mode scheduling (UMS) scheduler entry point function associated with a UMS completion list.

The **PUMS_SCHEDULER_ENTRY_POINT** type defines a pointer to this function. *UmsSchedulerProc* is a placeholder for the application-defined function name.

## Parameters

### `Reason` [in]

The reason the scheduler entry point is being called. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **UmsSchedulerStartup**<br><br>0 | A UMS scheduler thread was created. The entry point is called with this reason once each time [EnterUmsSchedulingMode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enterumsschedulingmode) is called. |
| **UmsSchedulerThreadBlocked**<br><br>1 | A UMS worker thread blocked. |
| **UmsSchedulerThreadYield**<br><br>2 | An executing UMS worker thread yielded control by calling the [UmsThreadYield](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-umsthreadyield) function. |

### `ActivationPayload` [in]

If the *Reason* parameter is **UmsSchedulerStartup**, this parameter is NULL.

If the *Reason* parameter is **UmsSchedulerThreadBlocked**, bit 0 of this parameter indicates the type of activity that was being serviced when the UMS worker thread blocked.

| Value | Meaning |
| --- | --- |
| **0** | The thread blocked on a trap (for example, a hard page fault) or an interrupt (for example, an asynchronous procedure call). |
| **1** | The thread blocked on a system call. |

If the *Reason* parameter is **UmsSchedulerThreadYield**, this parameter is a pointer to the UMS thread context of the UMS worker thread that yielded.

### `SchedulerParam` [in]

If the *Reason* parameter is **UmsSchedulerStartup**, this parameter is the **SchedulerParam** member of the [UMS_SCHEDULER_STARTUP_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-ums_scheduler_startup_info) structure passed to the [EnterUmsSchedulingMode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enterumsschedulingmode) function that triggered the entry point call.

If the *Reason* parameter is **UmsSchedulerThreadYield** this parameter is the SchedulerParam parameter passed to the [UmsThreadYield](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-umsthreadyield) function that triggered the entry point call.

If the *Reason* parameter is **UmsSchedulerThreadBlocked**, this parameter is NULL.

## Remarks

The *UmsSchedulerProc* function pointer type is defined as **PUMS_SCHEDULER_ENTRY_POINT** in WinBase.h. The underlying function type is defined as **RTL_UMS_SCHEDULER_ENTRY_POINT** in WinNT.h

Each UMS scheduler thread has an associated *UmsSchedulerProc* entry point function that is specified when the thread calls the [EnterUmsSchedulingMode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enterumsschedulingmode) function. The system calls the scheduler entry point function with a reason of **UmsSchedulerStartup** when the scheduler thread is converted for UMS.

Subsequently, when a UMS worker thread that is running on the scheduler thread yields or blocks, the system calls the scheduler thread's entry point function with a pointer to the UMS thread context of the worker thread.

The application's scheduler is responsible for selecting the next UMS worker thread to run. The scheduler implements all policies that influence execution of its UMS threads, including processor affinity and thread priority. For example, a scheduler might give priority to I/O-intensive threads, or it might run threads on a first-come, first-served basis. This logic can be implemented in the scheduler entry point function or elsewhere in the application.

When a blocked UMS worker thread becomes unblocked, the system queues the unblocked thread to the associated completion list and signals the completion list event. To retrieve UMS worker threads from the completion list, use the [DequeueUmsCompletionListItems](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-dequeueumscompletionlistitems) function.

## See also

[DequeueUmsCompletionListItems](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-dequeueumscompletionlistitems)

[EnterUmsSchedulingMode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enterumsschedulingmode)

[UmsThreadYield](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-umsthreadyield)
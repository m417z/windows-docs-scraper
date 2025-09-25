# CreateUmsCompletionList function

## Description

Creates a user-mode scheduling (UMS) completion list.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Parameters

### `UmsCompletionList` [out]

A **PUMS_COMPLETION_LIST** variable. On output, this parameter receives a pointer
to an empty UMS completion list.

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error values include the
following.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory is available to create the completion list. |
| **ERROR_NOT_SUPPORTED** | UMS is not supported. |

## Remarks

A completion list is associated with a UMS scheduler thread when the
[EnterUmsSchedulingMode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enterumsschedulingmode) function is called to
create the scheduler thread. The system queues newly created UMS worker threads to the completion list. It also
queues previously blocked UMS worker threads to the completion list when the threads are no longer blocked.

When an application's [UmsSchedulerProc](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-rtl_ums_scheduler_entry_point) entry
point function is called, the application's scheduler should retrieve items from the completion list by calling
[DequeueUmsCompletionListItems](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-dequeueumscompletionlistitems).

Each completion list has an associated completion list event which is signaled whenever the system queues
items to an empty list. Use the
[GetUmsCompletionListEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getumscompletionlistevent) to obtain a
handle to the event for a specified completion list.

When a completion list is no longer needed, use the
[DeleteUmsCompletionList](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deleteumscompletionlist) to release the list.
The list must be empty before it can be released.

## See also

[DequeueUmsCompletionListItems](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-dequeueumscompletionlistitems)

[EnterUmsSchedulingMode](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-enterumsschedulingmode)

[GetUmsCompletionListEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getumscompletionlistevent)
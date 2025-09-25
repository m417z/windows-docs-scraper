# IShellTaskScheduler::AddTask

## Description

Adds a task to the scheduler's background queue.

## Parameters

### `prt` [in]

Type: **[IRunnableTask](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-irunnabletask)***

A pointer to an instance of an [IRunnableTask](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-irunnabletask) interface representing the task to add to the queue.

### `rtoid` [in]

Type: **REFTASKOWNERID**

A GUID identifying the owner of the task. This information can be used to group tasks for later [counting](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelltaskscheduler-counttasks) or [removal](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelltaskscheduler-removetasks) by owner.

### `lParam` [in]

Type: **DWORD_PTR**

A pointer to a user-defined **DWORD** value allowing the task to be identified within the tasks owned by *rtoid*. This is used to identify single tasks or to subgroup them, for instance associating the task with a particular item such as an item in a ListView. This parameter can be zero.

### `dwPriority` [in]

Type: **DWORD**

One of the following values assigning the task's priority. Response to this priority depends on the cooperation of the other tasks being executed. New tasks are inserted in the queue in priority order. If a task of a low priority is currently under execution when a higher priority task is added, the scheduler attempts to suspend the task under execution. That lower priority task is resumed when the higher priority task(s) are completed.

#### ITSAT_DEFAULT_PRIORITY

Accept the default priority assigned to the task by the scheduler.

#### ITSAT_MAX_PRIORITY

High priority.

#### ITSAT_MIN_PRIORITY

Low priority.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
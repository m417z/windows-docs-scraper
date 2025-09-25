# ITaskFolder::GetTasks

## Description

Gets all the tasks in the folder.

## Parameters

### `flags` [in]

Specifies whether to retrieve hidden tasks. Pass in TASK_ENUM_HIDDEN to retrieve all tasks in the folder including hidden tasks, and pass in 0 to retrieve all the tasks in the folder excluding the hidden tasks.

### `ppTasks` [out]

An [IRegisteredTaskCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregisteredtaskcollection) collection of all the tasks in the folder.

Pass in a reference to a **NULL** [IRegisteredTaskCollection](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-iregisteredtaskcollection) interface pointer. Referencing a non-**NULL** pointer can cause a memory leak because the pointer will be overwritten.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITaskFolder](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itaskfolder)

[Task Scheduler](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-start-page)
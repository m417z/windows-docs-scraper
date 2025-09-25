# IShellTaskScheduler::RemoveTasks

## Description

Removes tasks from the scheduler's background queue.

## Parameters

### `rtoid` [in]

Type: **REFTASKOWNERID**

A GUID identifying the owner of the tasks to remove.

### `lParam` [in]

Type: **DWORD_PTR**

A pointer to a user-defined **DWORD** value that allows the task to be identified within the tasks owned by *rtoid*. Set this value to 0 to remove all tasks for the owner specified by *rtoid*.

### `bWaitIfRunning` [in]

Type: **BOOL**

**TRUE** if you want a currently running task to complete before removing it, **FALSE** otherwise.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
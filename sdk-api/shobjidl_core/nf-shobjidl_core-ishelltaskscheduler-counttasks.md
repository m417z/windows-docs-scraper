# IShellTaskScheduler::CountTasks

## Description

Counts tasks with the same owner ID in the scheduler's queue.

## Parameters

### `rtoid` [in]

Type: **REFTASKOWNERID**

A GUID identifying the owner of the tasks. Supplying a specific ID will count only those tasks tagged with that owner ID. To count all items in the queue, pass TOID_NULL.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
# RtwqLockSharedWorkQueue function

## Description

Obtains and locks a shared work queue.

## Parameters

### `usageClass` [in]

The name of the Multimedia Class Scheduler Service (MMCSS) task.

### `basePriority` [in]

The base priority of the work-queue threads. If the regular-priority queue is being used (`usageClass=""`), then the value 0 must be passed in.

### `taskId` [in, out]

The MMCSS task identifier. On input, specify an existing MCCSS task group ID, or use the value zero to create a new task group. If the regular priority queue is being used (`usageClass=""`), then **NULL** must be passed in. On output, receives the actual task group ID.

### `id` [out]

Receives an identifier for the new work queue. Use this identifier when queuing work items.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
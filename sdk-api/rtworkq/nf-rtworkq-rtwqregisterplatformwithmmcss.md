# RtwqRegisterPlatformWithMMCSS function

## Description

Registers the standard platform work queues with the Multimedia Class Scheduler Service (MMCSS).

## Parameters

### `usageClass` [in]

The name of the MMCSS task.

### `taskId` [in, out]

The MMCSS task identifier. On input, specify an existing MCCSS task group ID, or use the value zero to create a new task group. On output, receives the actual task group ID.

### `lPriority` [in]

The base priority of the work-queue threads.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
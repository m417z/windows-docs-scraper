# RtwqGetWorkQueueMMCSSTaskId function

## Description

Retrieves the Multimedia Class Scheduler Service (MMCSS) task identifier currently associated with this work queue.

## Parameters

### `workQueueId` [in]

Identifier for the work queue. The identifier is retrieved by the [RtwqAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqallocateworkqueue) function.

### `taskId` [out]

Receives the task identifier.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To associate a work queue with an MMCSS task, call [RtwqBeginRegisterWorkQueueWithMMCSSEx](https://learn.microsoft.com/windows/win32/api/rtworkq/nf-rtworkq-rtwqbeginregisterworkqueuewithmmcss).
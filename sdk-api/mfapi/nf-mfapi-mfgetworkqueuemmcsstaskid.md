# MFGetWorkQueueMMCSSTaskId function

## Description

Retrieves the Multimedia Class Scheduler Service (MMCSS) task identifier currently associated with this work queue.

## Parameters

### `dwWorkQueueId` [in]

Identifier for the work queue. The identifier is retrieved by the [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue) function.

### `pdwTaskId` [out]

Receives the task identifier.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

To associate a work queue with an MMCSS task, call [MFBeginRegisterWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfbeginregisterworkqueuewithmmcss).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)
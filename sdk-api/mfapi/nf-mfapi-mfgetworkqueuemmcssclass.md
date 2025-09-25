# MFGetWorkQueueMMCSSClass function

## Description

Retrieves the Multimedia Class Scheduler Service (MMCSS) class currently associated with this work queue.

## Parameters

### `dwWorkQueueId` [in]

Identifier for the work queue. The identifier is retrieved by the [MFAllocateWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateworkqueue) function.

### `pwszClass` [out]

Pointer to a buffer that receives the name of the MMCSS class. This parameter can be **NULL**.

### `pcchClass` [in, out]

On input, specifies the size of the *pwszClass* buffer, in characters. On output, receives the required size of the buffer, in characters. The size includes the terminating null character.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **MF_E_BUFFERTOOSMALL** | The *pwszClass* buffer is too small to receive the task name. |

## Remarks

If the work queue is not associated with an MMCSS task, the function retrieves an empty string.

To associate a work queue with an MMCSS task, call [MFBeginRegisterWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfbeginregisterworkqueuewithmmcss).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)
# IMFWorkQueueServicesEx::GetTopologyWorkQueueMMCSSPriority

## Description

Retrieves the Multimedia Class Scheduler Service (MMCSS) string associated with the given topology work queue.

## Parameters

### `dwTopologyWorkQueueId` [in]

The id of the topology work queue.

### `plPriority` [out]

Pointer to the buffer the work queue's MMCSS task id will be copied to.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFWorkQueueServicesEx](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfworkqueueservicesex)
# IMFWorkQueueServicesEx::GetPlatformWorkQueueMMCSSPriority

## Description

Gets the priority of the Multimedia Class Scheduler Service (MMCSS) priority associated with
the specified platform work queue.

## Parameters

### `dwPlatformWorkQueueId` [in]

Topology work queue id for which the info will be returned.

### `plPriority` [out]

## Return value

Pointer to a buffer allocated by the caller
that the work queue's MMCSS task id will be copied to.

## See also

[IMFWorkQueueServicesEx](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfworkqueueservicesex)
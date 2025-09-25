# IMFWorkQueueServices::GetPlatformWorkQueueMMCSSTaskId

## Description

Retrieves the Multimedia Class Scheduler Service (MMCSS) task identifier for a specified platform work queue.

## Parameters

### `dwPlatformWorkQueueId` [in]

Platform work queue to query. See [IMFWorkQueueServices::BeginRegisterPlatformWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfworkqueueservices-beginregisterplatformworkqueuewithmmcss).

### `pdwTaskId` [out]

Receives the task identifier.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFWorkQueueServices](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfworkqueueservices)
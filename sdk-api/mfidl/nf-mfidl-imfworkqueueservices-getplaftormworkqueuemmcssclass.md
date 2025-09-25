# IMFWorkQueueServices::GetPlaftormWorkQueueMMCSSClass

## Description

Retrieves the Multimedia Class Scheduler Service (MMCSS) class for a specified platform work queue.

## Parameters

### `dwPlatformWorkQueueId` [in]

Platform work queue to query. See [IMFWorkQueueServices::BeginRegisterPlatformWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfworkqueueservices-beginregisterplatformworkqueuewithmmcss).

### `pwszClass` [out]

Pointer to a buffer that receives the name of the MMCSS class. This parameter can be **NULL**.

### `pcchClass` [in, out]

On input, specifies the size of the pwszClass buffer, in characters. On output, receives the required size of the buffer, in characters. The size includes the terminating null character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_BUFFERTOOSMALL** | The *pwszClass* buffer is too small to receive the class name. |

## See also

[IMFWorkQueueServices](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfworkqueueservices)
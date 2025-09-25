# IMFWorkQueueServices::EndRegisterPlatformWorkQueueWithMMCSS

## Description

Completes an asynchronous request to associate a platform work queue with a Multimedia Class Scheduler Service (MMCSS) task.

## Parameters

### `pResult` [in]

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Pass in the same pointer that your callback object received in the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

### `pdwTaskId` [out]

The unique task identifier.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Call this function when the [IMFWorkQueueServices::BeginRegisterPlatformWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfworkqueueservices-beginregisterplatformworkqueuewithmmcss) method completes asynchronously.

To unregister the work queue from the MMCSS class, call [IMFWorkQueueServices::BeginUnregisterPlatformWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfworkqueueservices-beginunregisterplatformworkqueuewithmmcss).

## See also

[IMFWorkQueueServices](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfworkqueueservices)
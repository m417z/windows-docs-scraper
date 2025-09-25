# IMFWorkQueueServices::BeginRegisterPlatformWorkQueueWithMMCSS

## Description

Associates a platform work queue with a Multimedia Class Scheduler Service (MMCSS) task.

## Parameters

### `dwPlatformWorkQueue` [in]

The platform work queue to register with MMCSS. See [Work Queue Identifiers](https://learn.microsoft.com/windows/desktop/medfound/work-queue-identifiers).
To register all of the standard work queues to the same MMCSS task, set this parameter to **MFASYNC_CALLBACK_QUEUE_ALL**.

### `wszClass` [in]

The name of the MMCSS task to be performed.

### `dwTaskId` [in]

The unique task identifier. To obtain a new task identifier, set this value to zero.

### `pCallback` [in]

A pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `pState` [in]

A pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is asynchronous. When the operation completes, the callback object's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method is called. At that point, the application should call [IMFWorkQueueServices::EndRegisterPlatformWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfworkqueueservices-endregisterplatformworkqueuewithmmcss) to complete the asynchronous request.

To unregister the work queue from the MMCSS class, call [IMFWorkQueueServices::BeginUnregisterPlatformWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfworkqueueservices-beginunregisterplatformworkqueuewithmmcss).

## See also

[IMFWorkQueueServices](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfworkqueueservices)
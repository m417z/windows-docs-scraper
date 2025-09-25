# RtwqEndRegisterWorkQueueWithMMCSS function

## Description

Completes an asynchronous request to associate a work queue with a Multimedia Class Scheduler Service (MMCSS) task.

## Parameters

### `result` [in]

Pointer to the asynchronous result. Pass in the same pointer that your callback object received in the [IRtwqAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-irtwqasynccallback-invoke) method.

### `taskId` [out]

The unique task identifier.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this function when the [RtwqBeginRegisterWorkQueueWithMMCSSEx](https://learn.microsoft.com/windows/win32/api/rtworkq/nf-rtworkq-rtwqbeginregisterworkqueuewithmmcss) function completes asynchronously.

To unregister the work queue from the MMCSS class, call [RtwqBeginUnregisterWorkQueueWithMMCSS](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqbeginunregisterworkqueuewithmmcss).
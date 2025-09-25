# MFPutWaitingWorkItem function

## Description

Queues a work item that waits for an event to be signaled.

## Parameters

### `hEvent` [in]

A handle to an event object. To create an event object, call [CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) or [CreateEventEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventexa).

### `Priority` [in]

The priority of the work item. Work items are performed in order of priority.

### `pResult` [in]

A pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface of an asynchronous result object. To create the result object, call [MFCreateAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateasyncresult).

### `pKey` [out]

Receives a key that can be used to cancel the wait. To cancel the wait, call [MFCancelWorkItem](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcancelworkitem) and pass this key in the *Key* parameter.

This parameter can be **NULL**.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function enables a component to wait for an event without blocking the current thread.

The function puts a work item on the specified work queue. This work item waits for the event given in *hEvent* to be signaled. When the event is signaled, the work item invokes a callback. (The callback is contained in the result object given in *pResult*. For more information, see [MFCreateAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateasyncresult)).

The work item is dispatched on a work queue by the [IMFAsyncCallback::GetParameters](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-getparameters) method of the callback. The work queue can be any of the following:

* The default work queue (**MFASYNC_CALLBACK_QUEUE_STANDARD**).
* The platform multithreaded queue (**MFASYNC_CALLBACK_QUEUE_MULTITHREADED**).
* A multithreaded queue returned by the [MFLockSharedWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mflocksharedworkqueue) function.
* A serial queue created by the [MFAllocateSerialWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfallocateserialworkqueue) function.

Do not use any of the following work queues: **MFASYNC_CALLBACK_QUEUE_IO**, **MFASYNC_CALLBACK_QUEUE_LONG_FUNCTION**, **MFASYNC_CALLBACK_QUEUE_RT**, or **MFASYNC_CALLBACK_QUEUE_TIMER**.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queue and Threading Improvements](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-work-queue-and-threading-improvements)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)
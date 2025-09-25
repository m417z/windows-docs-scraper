# MFAllocateSerialWorkQueue function

## Description

Creates a work queue that is guaranteed to serialize work items. The serial work queue wraps an existing multithreaded work queue. The serial work queue enforces a first-in, first-out (FIFO) execution order.

## Parameters

### `dwWorkQueue` [in]

The identifier of an existing work queue. This must be either a multithreaded queue or another serial work queue. Any of the following can be used:

* The default work queue (**MFASYNC_CALLBACK_QUEUE_STANDARD**)
* The platform multithreaded queue (**MFASYNC_CALLBACK_QUEUE_MULTITHREADED**)
* A multithreaded queue returned by the [MFLockSharedWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mflocksharedworkqueue) function.
* A serial queue created by the **MFAllocateSerialWorkQueue** function.

### `pdwWorkQueue` [out]

Receives an identifier for the new serial work queue. Use this identifier when queuing work items.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_FAIL** | The application exceeded the maximum number of work queues. |
| **MF_E_SHUTDOWN** | The application did not call [MFStartup](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfstartup), or the application has already called [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown). |

## Remarks

When you are done using the work queue, call [MFUnlockWorkQueue](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfunlockworkqueue).

Multithreaded queues use a thread pool, which can reduce the total number of threads in the pipeline. However, they do not serialize work items. A serial work queue enables the application to get the benefits of the thread pool, without needing to perform manual serialization of its own work items.

### Reply Mode

A serializer queue can also work in "reply" mode. If the caller’s [IMFAsyncCallback::GetParameters](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-getparameters) method returns the **MFASYNC_REPLY_CALLBACK** flag, the serializer queue does not automatically advance to the next work item. Instead, the queue waits for a reply from the caller. The caller signals the reply by invoking the asynchronous result object that the work queue passes to the [Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method. The following code illustrates how the caller signals the work queue.

```cpp
HRESULT CCallback::Invoke(IMFAsyncResult *pResult)
{
    DoSomeWork();

    // Reply to the work queue that you are done.
    MFInvokeCallback(pResult);

    // Note: This call to MFInvokeCallback does not have to occur inside the
    // Invoke method. You could call MFInvokeCallback at a later time.

    return S_OK;
}
HRESULT CCallback::GetParameters(DWORD *pdwFlags, DWORD *pdwQueue)
{
    *pdwFlags = MFASYNC_REPLY_CALLBACK;
    *pdwQueue = m_QueueId;
    return S_OK;
}

```

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Work Queue and Threading Improvements](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-work-queue-and-threading-improvements)
# IMFRealTimeClientEx::RegisterThreadsEx

## Description

Notifies the object to register its worker threads with the Multimedia Class Scheduler Service (MMCSS).

## Parameters

### `pdwTaskIndex` [in, out]

The MMCSS task identifier. If the value is zero on input, the object should create a new MCCSS task group. See Remarks.

### `wszClassName` [in]

The name of the MMCSS task.

### `lBasePriority` [in]

The base priority of the thread.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the object does not create worker threads, the method should simply return S_OK and take no further action.

Otherwise, if the value of `*pdwTaskIndex` is zero on input, the object should perform the following steps:

1. A single worker thread calls [AvSetMmThreadCharacteristics](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avsetmmthreadcharacteristicsa) to create a new MMCSS task identifier. Store this value.
2. Any additional worker threads call [AvSetMmThreadCharacteristics](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avsetmmthreadcharacteristicsa) using the new task identifier.
3. Return the new task identifier to the caller, by setting `*pdwTaskIndex` equal to the task identifier.

If the value of `*pdwTaskIndex` is nonzero on input, the parameter contains an existing MMCSS task identifier. In that case, all worker threads of the object should register themselves for that task by calling [AvSetMmThreadCharacteristics](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avsetmmthreadcharacteristicsa).

## See also

[IMFRealTimeClientEx](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfrealtimeclientex)

[Work Queue and Threading Improvements](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-work-queue-and-threading-improvements)
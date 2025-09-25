# IMFRealTimeClient::RegisterThreads

## Description

Notifies the object to register its worker threads with the Multimedia Class Scheduler Service (MMCSS).

## Parameters

### `dwTaskIndex` [in]

The MMCSS task identifier.

### `wszClass` [in]

The name of the MMCSS task.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The object's worker threads should register themselves with MMCSS by calling [AvSetMmThreadCharacteristics](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avsetmmthreadcharacteristicsa), using the task name and identifier specified in this method.

## See also

[IMFRealTimeClient](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfrealtimeclient)
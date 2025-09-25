# IMFRealTimeClient::UnregisterThreads

## Description

Notifies the object to unregister its worker threads from the Multimedia Class Scheduler Service (MMCSS).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The object's worker threads should unregister themselves from MMCSS by calling [AvRevertMmThreadCharacteristics](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avrevertmmthreadcharacteristics).

## See also

[IMFRealTimeClient](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfrealtimeclient)
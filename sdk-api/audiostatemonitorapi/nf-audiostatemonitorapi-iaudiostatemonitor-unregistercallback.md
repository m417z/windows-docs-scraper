## Description

Unregisters an [AudioStateMonitorCallback](https://learn.microsoft.com/windows/win32/api/audiostatemonitorapi/nc-audiostatemonitorapi-audiostatemonitorcallback) previously registered with a call to [IAudioStateMonitor::RegisterCallback](https://learn.microsoft.com/windows/win32/api/audiostatemonitorapi/nf-audiostatemonitorapi-iaudiostatemonitor-registercallback).

## Parameters

### `registration`

The registration handle obtained from the *registration* output parameter to **RegisterCallback**.

## Remarks

If any callbacks are in progress, this method will block until the callbacks have completed. This method may be called from within the callback, and in this case it will not block.

## See also
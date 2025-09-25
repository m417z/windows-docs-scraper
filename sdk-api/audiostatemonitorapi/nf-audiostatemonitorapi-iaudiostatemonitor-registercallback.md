## Description

Registers an implementation of [AudioStateMonitorCallback](https://learn.microsoft.com/windows/win32/api/audiostatemonitorapi/nc-audiostatemonitorapi-audiostatemonitorcallback) that is called when the system changes the sound level of the audio streams being monitored by an [IAudioStateMonitor](https://learn.microsoft.com/windows/win32/api/audiostatemonitorapi/nn-audiostatemonitorapi-iaudiostatemonitor).

## Parameters

### `callback` [in]

A pointer to the **AudioStateMonitorCallback** function implementation.

### `context` [in, optional]

A optional void pointer that points to context information provided by the client in the call to [IAudioStateMonitor::RegisterCallback](https://learn.microsoft.com/windows/win32/api/audiostatemonitorapi/nf-audiostatemonitorapi-iaudiostatemonitor-registercallback).

### `registration` [out]

An Int64 representing the handle to a registration. Pass this handle to [IAudioStateMonitor::UnregisterCallback](https://learn.microsoft.com/windows/win32/api/audiostatemonitorapi/nf-audiostatemonitorapi-iaudiostatemonitor-unregistercallback) to unregister the callback.

## Return value

Returns an HRESULT including the following values.

| Value | Description |
|-------|-------------|
| S_OK | Success. |

## Remarks

## See also
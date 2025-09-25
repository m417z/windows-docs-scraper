## Description

Raised when an unrecoverable error occurs within the associated [IMFCameraControlMonitor](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameracontrolmonitor).

## Parameters

### `hrStatus`

The internal error code associated with the error. Possible error values include the following:

| Value | Description |
|-------|-------------|
| E_OUTOFMEMORY | There were insufficient resources available for the monitor to function properly. |
| MF_INVALID_STATE_ERR | A corruption of memory states has occurred. |

## Remarks

After the call to this function returns, the system will cleanup and remove the reference to the [IMFCameraControlNotify](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameracontrolnotify). Clients do not need to call [IMFCameraControlMonitor::Shutdown](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolmonitor-shutdown) after receiving an **OnError** notification.

To see a code example that implements this method, see [IMFCameraControlNotify](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameracontrolnotify).

## See also
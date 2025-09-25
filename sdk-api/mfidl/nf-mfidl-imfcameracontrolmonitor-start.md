## Description

Starts the camera control monitor, raising [IMFCameraControlNotify::OnChange](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolnotify-onchange) notifications for changes to controls registered with [IMFCameraControlMonitor::AddControlSubscription](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolmonitor-addcontrolsubscription).

## Return value

An HRESULT including the following:

| Value | Description |
|-------|-------------|
| S_OK | Success |
| MF_E_INVALIDREQUEST | The camera control monitor has already been started or has been shut down. |

## Remarks

To see a code example that implements this method, see [IMFCameraControlNotify](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameracontrolnotify).

## See also
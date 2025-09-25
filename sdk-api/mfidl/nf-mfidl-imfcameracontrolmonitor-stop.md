## Description

Stops the camera control monitor.

## Return value

An HRESULT including the following:

| Value | Description |
|-------|-------------|
| S_OK | Success |
| MF_E_INVALIDREQUEST | The camera control monitor has already been stopped or has been shut down. |

## Remarks

Stopping the camera control monitor pauses control change notifications through [IMFCameraControlNotify::OnChange](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolnotify-onchange). While the monitor is stopped, clients can add and remove control subscriptions with calls to [AddControlSubscription](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolmonitor-addcontrolsubscription) and [RemoveControlSubscription](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolmonitor-removecontrolsubscription).

To see a code example that implements this method, see [IMFCameraControlNotify](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameracontrolnotify).

## See also
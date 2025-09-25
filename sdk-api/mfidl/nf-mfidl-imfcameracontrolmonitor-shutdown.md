## Description

Shuts down the camera control monitor and cleans up associated resources.

## Remarks

Clients are not required to call [Stop](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolmonitor-stop) before calling **Shutdown**. After calling **Shutdown** subsequent calls to [Start](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolmonitor-start), [Stop](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolmonitor-stop), [AddControlSubscription](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolmonitor-addcontrolsubscription), or [RemoveControlSubscription](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontrolmonitor-addcontrolsubscription) will result in an error.

To see a code example that implements this method, see [IMFCameraControlNotify](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameracontrolnotify).

## See also
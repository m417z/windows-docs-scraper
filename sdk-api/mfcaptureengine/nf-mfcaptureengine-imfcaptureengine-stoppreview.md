# IMFCaptureEngine::StopPreview

## Description

Stops preview.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDREQUEST** | The capture engine is not currently previewing. |

## Remarks

This method is asynchronous. If the method returns a success code, the caller will receive an **MF_CAPTURE_ENGINE_PREVIEW_STOPPED** event through the [IMFCaptureEngineOnEventCallback::OnEvent](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengineoneventcallback-onevent) method. The operation can fail asynchronously after the method succeeds. If so, the error code is conveyed through the **OnEvent** method.

## See also

[IMFCaptureEngine](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengine)
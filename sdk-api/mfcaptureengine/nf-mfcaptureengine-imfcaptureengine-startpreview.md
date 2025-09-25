# IMFCaptureEngine::StartPreview

## Description

Starts preview.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDREQUEST** | The preview sink was not initialized. |

## Remarks

Before calling this method, configure the preview sink by calling [IMFCaptureSink::AddStream](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesink-addstream). To get a pointer to the preview sink, call [IMFCaptureEngine::GetSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengine-getsink).

This method is asynchronous. If the method returns a success code, the caller will receive an **MF_CAPTURE_ENGINE_PREVIEW_STARTED** event through the [IMFCaptureEngineOnEventCallback::OnEvent](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengineoneventcallback-onevent) method. The operation can fail asynchronously after the method succeeds. If so, the error code is conveyed through the **OnEvent** method.

After the preview sink is configured, you can stop and start preview by calling [IMFCaptureEngine::StopPreview](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengine-stoppreview) and **IMFCaptureEngine::StartPreview**.

## See also

[IMFCaptureEngine](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengine)
# IMFCaptureEngine::StartRecord

## Description

Starts recording audio and/or video to a file.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDREQUEST** | The recording sink was not initialized. |

## Remarks

Before calling this method, configure the recording sink by calling [IMFCaptureSink::AddStream](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesink-addstream). To get a pointer to the recording sink, call [IMFCaptureEngine::GetSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengine-getsink).

This method is asynchronous. If the method returns a success code, the caller will receive an **MF_CAPTURE_ENGINE_RECORD_STARTED** event through the [IMFCaptureEngineOnEventCallback::OnEvent](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengineoneventcallback-onevent) method. The operation can fail asynchronously after the method succeeds. If so, the error code is conveyed through the **OnEvent** method.

To stop recording, call [IMFCaptureEngine::StopRecord](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengine-stoprecord).

## See also

[IMFCaptureEngine](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengine)
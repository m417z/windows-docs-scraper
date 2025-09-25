# IMFCaptureEngine::TakePhoto

## Description

Captures a still image from the video stream.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Before calling this method, configure the photo sink by calling [IMFCaptureSink::AddStream](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesink-addstream). To get a pointer to the photo sink, call [IMFCaptureEngine::GetSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengine-getsink).

This method is asynchronous. If the method returns a success code, the caller will receive an **MF_CAPTURE_ENGINE_PHOTO_TAKEN** event through the [IMFCaptureEngineOnEventCallback::OnEvent](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengineoneventcallback-onevent) method. The operation can fail asynchronously after the method succeeds. If so, the error code is conveyed through the **OnEvent** method.

## See also

[IMFCaptureEngine](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcaptureengine)
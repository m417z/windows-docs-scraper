# IMFCaptureSink::Prepare

## Description

Prepares the capture sink by loading any required pipeline components, such as encoders, video processors, and media sinks.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDREQUEST** | Invalid request. |

## Remarks

Calling this method is optional. This method gives the application an opportunity to configure the pipeline components before they are used. The method is asynchronous. If the method returns a success code, the caller will receive an **MF_CAPTURE_SINK_PREPARED** event through the [IMFCaptureEngineOnEventCallback::OnEvent](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcaptureengineoneventcallback-onevent) method. After this event is received, call [IMFCaptureSink::GetService](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesink-getservice) to configure individual components.

Before calling this method, configure the capture sink by adding at least one stream. To add a stream, call [IMFCaptureSink::AddStream](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nf-mfcaptureengine-imfcapturesink-addstream).

The **Prepare** method fails if the capture sink is currently in use. For example, calling **Prepare** on the preview sink fails if the capture engine is currently previewing.

## See also

[IMFCaptureSink](https://learn.microsoft.com/windows/desktop/api/mfcaptureengine/nn-mfcaptureengine-imfcapturesink)
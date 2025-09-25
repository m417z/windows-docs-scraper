# IMFSampleGrabberSinkCallback::OnShutdown

## Description

Called when the sample-grabber sink is shut down.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is called when the sink's [IMFMediaSink::Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method is called.

The **OnShutdown** method should return quickly, or it might interfere with playback. Do not block the thread, wait on events, or perform other lengthy operations inside this method.

## See also

[IMFSampleGrabberSinkCallback](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsamplegrabbersinkcallback)
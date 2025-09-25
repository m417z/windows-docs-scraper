# IMFStreamSink::Flush

## Description

Causes the stream sink to drop any samples that it has received and has not rendered yet.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NOT_INITIALIZED** | The stream sink has not been initialized yet. You might need to set a media type. |
| **MF_E_SHUTDOWN** | The media sink's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method has been called. |
| **MF_E_STREAMSINK_REMOVED** | This stream was removed from the media sink and is no longer valid. |

## Remarks

If any samples are still queued from previous calls to the [IMFStreamSink::ProcessSample](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfstreamsink-processsample) method, the media sink immediately discards them, without processing them. This can cause a glitch in the rendered output. The running state of the sink (running, paused, or stopped) does not change.

Any pending marker events from the [IMFStreamSink::PlaceMarker](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfstreamsink-placemarker) method are dispatched immediately, with the status code E_ABORT.

This method is synchronous. It does not return until the sink has discarded all pending samples.

## See also

[IMFStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamsink)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)
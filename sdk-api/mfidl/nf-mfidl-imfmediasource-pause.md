# IMFMediaSource::Pause

## Description

Pauses all active streams in the media source.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALID_STATE_TRANSITION** | Invalid state transition. The media source must be in the started state. |
| **MF_E_SHUTDOWN** | The media source's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-shutdown) method has been called. |

## Remarks

This method is asynchronous. When the operation completes, the media source sends and [MESourcePaused](https://learn.microsoft.com/windows/desktop/medfound/mesourcepaused) event, and every active stream sends an [MEStreamPaused](https://learn.microsoft.com/windows/desktop/medfound/mestreampaused) event. If the method returns a failure code, no events are raised.

The media source must be in the started state. The method fails if the media source is paused or stopped.

While the source is paused, calls to [IMFMediaStream::RequestSample](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediastream-requestsample) succeed, but the streams will not deliver any samples until after the source is started again. Note that the source's event queue is not serialized with the stream event queues, so the client might receive some samples after the [MESourcePaused](https://learn.microsoft.com/windows/desktop/medfound/mesourcepaused) event, due to multi-threading issues. But the client will not receive any samples from a stream after the [MEStreamPaused](https://learn.microsoft.com/windows/desktop/medfound/mestreampaused) event.

Not every media source can pause. If a media source can pause, the [IMFMediaSource::GetCharacteristics](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-getcharacteristics) method returns the MFMEDIASOURCE_CAN_PAUSE flag.

## See also

[IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource)

[Media Sources](https://learn.microsoft.com/windows/desktop/medfound/media-sources)
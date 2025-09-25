# IMFMediaSource::Stop

## Description

Stops all active streams in the media source.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The media source's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-shutdown) method has been called. |

## Remarks

This method is asynchronous. When the operation completes, the media source sends and [MESourceStopped](https://learn.microsoft.com/windows/desktop/medfound/mesourcestopped) event, and every active stream sends an [MEStreamStopped](https://learn.microsoft.com/windows/desktop/medfound/mestreamstopped) event. If the method returns a failure code, no events are raised.

When a media source is stopped, its current position reverts to zero. After that, if the [Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-start) method is called with VT_EMPTY for the starting position, playback starts from the beginning of the presentation.

While the source is stopped, no streams produce data.

## See also

[IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource)

[Media Sources](https://learn.microsoft.com/windows/desktop/medfound/media-sources)
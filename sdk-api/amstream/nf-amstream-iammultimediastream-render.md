# IAMMultiMediaStream::Render

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The `Render` method renders the current filter graph.

## Parameters

### `dwFlags` [in]

Value that specifies how the filter graph renders the current multimedia stream. This value currently must be AMMSF_NOCLOCK.

## Return value

Returns S_OK if successful or E_INVALIDARG if the *dwFlags* parameter is invalid.

## Remarks

This method renders each of the source streams for a stream of type STREAMTYPE_WRITE. This can be called several times, for instance, each time a source stream is added, the stream is not set into running mode. Use the [IMultiMediaStream::SetState](https://learn.microsoft.com/windows/desktop/api/mmstream/nf-mmstream-imultimediastream-setstate) method to set the stream into running mode after calling this method.

The AMMSF_RENDERALLSTREAMS flag will create default rendering streams for video and audio if they do not exist.

## See also

[IAMMultiMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammultimediastream)
# IAMMediaTypeStream::SetFormat

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The `SetFormat` method sets the format of the stream.

## Parameters

### `pMediaType` [in]

Pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure that contains the stream format.

### `dwFlags` [in]

Reserved.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **MS_E_SAMPLEALLOC** | The stream has already allocated a sample with another media type. |
| **S_OK** | Success. |

## See also

[IAMMediaTypeStream Interface](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammediatypestream)
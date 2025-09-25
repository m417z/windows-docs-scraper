# IStreamSample::GetMediaStream

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Retrieves a pointer to the media stream object that created the current sample.

## Parameters

### `ppMediaStream` [in]

Address of a pointer to an [IMediaStream](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-imediastream) interface that will point to the media stream that created the current sample.

## Return value

Returns S_OK if successful or E_POINTER if *ppMediaStream* is invalid.

## Remarks

If successful, this method increments the reference count of the media stream specified by *ppMediaStream*.

## See also

[IStreamSample Interface](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-istreamsample)
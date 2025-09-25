# IMediaStream::GetMultiMediaStream

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Retrieves a pointer to the multimedia stream that contains the specified media stream.

## Parameters

### `ppMultiMediaStream` [out]

Address of a pointer to an [IMultiMediaStream](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-imultimediastream) interface object that will point to the multimedia stream from which the current media stream was created.

## Return value

Returns S_OK if successful or E_POINTER if *ppMultiMediaStream* is invalid.

## Remarks

This method increments the reference count of the retrieved object pointer.

## See also

[IMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-imediastream)
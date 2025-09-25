# IAMMediaStream::JoinAMMultiMediaStream

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The [IAMMultiMediaStream::AddMediaStream](https://learn.microsoft.com/windows/desktop/api/amstream/nf-amstream-iammultimediastream-addmediastream) method calls this method, which adds the specified media stream to the current multimedia stream.

## Parameters

### `pAMMultiMediaStream` [in]

Pointer to the [IAMMultiMediaStream](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammultimediastream) object to add the current media stream to.

## Return value

Returns S_OK if successful or MS_E_SAMPLEALLOC if the media stream already has allocated stream samples.

## Remarks

Don't increment the reference count of the supplied multimedia stream because it is already accounted for when created.

Applications should not call this method.

## See also

[IAMMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammediastream)
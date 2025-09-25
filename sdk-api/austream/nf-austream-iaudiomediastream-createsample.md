# IAudioMediaStream::CreateSample

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Creates an audio stream sample for use with the specified stream.

## Parameters

### `pAudioData` [in]

Pointer to an [IAudioData](https://learn.microsoft.com/windows/desktop/api/austream/nn-austream-iaudiodata) container. **IAudioData** objects can be referenced by samples in more than one stream.

### `dwFlags` [in]

Reserved for flag data. Must be zero.

### `ppSample` [out]

Address of a pointer to the new [IAudioStreamSample](https://learn.microsoft.com/windows/desktop/api/austream/nn-austream-iaudiostreamsample) interface.

## Return value

Returns S_OK if successful or E_POINTER if one or more of the required parameters are **NULL**.

## Remarks

The *pAudioData* object defines the data's format.

## See also

[IAudioMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/austream/nn-austream-iaudiomediastream)
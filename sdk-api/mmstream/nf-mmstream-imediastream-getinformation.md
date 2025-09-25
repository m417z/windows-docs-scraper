# IMediaStream::GetInformation

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Retrieves the stream's purpose ID and media type.

## Parameters

### `pPurposeId` [out]

Pointer to an **MSPID** value that will contain the stream's purpose ID (see [Multimedia Streaming Data Types](https://learn.microsoft.com/windows/desktop/DirectShow/multimedia-streaming-data-types)). If this parameter is **NULL** on entry, the method won't retrieve the purpose ID.

### `pType` [out]

Pointer to a [STREAM_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mmstream/ne-mmstream-stream_type) enumerated data type value that will contain the stream's media type. If this parameter is **NULL** on entry, the method won't retrieve the media type.

## Return value

Returns S_OK if successful or E_POINTER if one of the parameters is invalid.

## Remarks

The value retrieved in the *pPurposeId* parameter will usually be either MSPID_PrimaryVideo, which identifies the primary video stream, or MSPID_PrimaryAudio, which identifies the primary audio stream; however, you can define other values if necessary.

## See also

[IMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-imediastream)
# IMPEG2StreamIdMap::MapStreamId

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `MapStreamId` method maps the Stream ID of an elementary stream within an MPEG-2 program stream to a media content type and substream filtering information.

## Parameters

### `ulStreamId` [in]

The stream ID of the PES stream.

### `MediaSampleContent` [in]

Specifies the contents of the stream. Currently the only value supported is MPEG2_PROGRAM_ELEMENTARY_STREAM (defined as 0x00000001 in axextend.idl).

### `ulSubstreamFilterValue` [in]

Specifies which substream within this elementary stream to pass on to the downstream decoder. Only the low-order byte can contain a valid filter value. If *iDataOffset* = 0, this parameter is ignored.

### `iDataOffset` [in]

The byte offset into the payload at which the substream begins.

## Return value

Returns S_OK if successful. If the method fails, an error code is returned. If a Stream ID of MEDIA_PROGRAM_STREAM_MAP, MEDIA_PROGRAM_DIRECTORY_PES_PACKET or MEDIA_PROGRAM_PACK_HEADER is attempted, this method returns E_NOTIMPL.

## Remarks

The Stream ID mapped by this method is the stream ID in the PES header. Substream filtering is most commonly used to provide multiple channels on a single audio stream.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMPEG2StreamIdMap Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-impeg2streamidmap)
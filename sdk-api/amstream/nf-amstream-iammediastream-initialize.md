# IAMMediaStream::Initialize

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The `Initialize` method creates and initializes a new media stream with the specified stream type and purpose ID.

## Parameters

### `pSourceObject` [in]

Pointer to an **IUnknown** source object.

### `dwFlags` [in]

Value that modifies the media stream's behavior; it is a combination of one or more of the following values.

| Value | Description |
| --- | --- |
| AMMSF_ADDDEFAULTRENDERER | Add a default renderer. |
| AMMSF_CREATEPEER | Create a peer stream based on the same object as a *pStreamObject*. |
| AMMSF_NOSTALL | Run the stream even if [Update](https://learn.microsoft.com/windows/desktop/api/mmstream/nf-mmstream-istreamsample-update) is not called. |
| AMMSF_STOPIFNOSAMPLES | Terminates the stream if no samples were created or if the last sample is deleted. |

### `PurposeId` [in]

Purpose ID for the new media stream.

### `StreamType` [in]

[STREAM_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mmstream/ne-mmstream-stream_type) enumeration value that specifies the new media stream's media type.

## Return value

Returns S_OK if successful or E_POINTER if one or more of the required parameters are invalid.

## Remarks

If *dwFlags* specifies AMMSF_ADDDEFAULTRENDERER, then the default renderer for the given purpose ID is created, if possible. Currently, the only default renderer supported is for audio using DirectSound. In this case, the *pStreamObject* parameter must be **NULL** and any calls to the [IMultiMediaStream::GetMediaStream](https://learn.microsoft.com/windows/desktop/api/mmstream/nf-mmstream-imultimediastream-getmediastream) or [IMultiMediaStream::EnumMediaStreams](https://learn.microsoft.com/windows/desktop/api/mmstream/nf-mmstream-imultimediastream-enummediastreams) method will not recognize the stream.

If *dwFlags* specifies AMMSF_CREATEPEER, then a media stream is created using *pStreamObject* and added to the current multimedia stream. The *pStreamObject* parameter varies depending on the stream type. In general, *pStreamObject* can point to an [IMediaStream](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-imediastream) object, in which case a stream with the sample purpose ID and format is created. For **IDirectDraw** streams, it can also be a pointer to an **IDirectDraw** interface.

If *dwFlags* specifies AMMSF_STOPIFNOSAMPLES, then the stream is terminated.

If no flags are set, then *pStreamObject* can be one of the following.

| Value | Description |
| --- | --- |
| An [IAMMediaStream](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammediastream) object | This stream is then added to the streams in the multimedia stream. |
| **NULL** | In this case a default [IMediaStream](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-imediastream) object is added to the stream with a default underlying object, if required. |
| A pointer to an underlying object | This is used to construct default streams. For video streams, this can be an **IDirectDraw** pointer. |

## See also

[IAMMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammediastream)
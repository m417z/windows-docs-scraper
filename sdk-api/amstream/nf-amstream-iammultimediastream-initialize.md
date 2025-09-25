# IAMMultiMediaStream::Initialize

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The `Initialize` method initializes the multimedia stream object.

## Parameters

### `StreamType` [in]

Member of the [STREAM_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mmstream/ne-mmstream-stream_type) enumeration, specifying whether the streams are read-only, write-only, or read/write.

### `dwFlags` [in]

Must be one of the following values:

| Value | Description |
| --- | --- |
| Zero | Create a filter graph that runs on a separate thread. |
| AMMSF_NOGRAPHTHREAD | Create a filter graph that runs on the calling thread. |

### `pFilterGraph` [in]

[optional] Pointer to the [IGraphBuilder](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder) interface, or **NULL**. If this parameter is non-**NULL**, it specifies a filter graph that the multimedia stream object will use. Otherwise, the multimedia stream object creates a new filter graph.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## Remarks

If you specify AMMSF_NOGRAPHTHREAD in the *dwFlags* parameter, the calling thread must process window messages, and it must release all multimedia streaming objects before the thread exits. Otherwise, the application might deadlock.

## See also

[IAMMultiMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammultimediastream)
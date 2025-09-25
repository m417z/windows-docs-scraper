# IGraphBuilder::RenderFile

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `RenderFile` method builds a filter graph that renders the specified file.

## Parameters

### `lpcwstrFile` [in]

Specifies a wide-character string that contains the name of a media file.

### `lpcwstrPlayList` [in]

Reserved. Must be **NULL**.

## Return value

Returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_S_AUDIO_NOT_RENDERED** | Partial success; the audio was not rendered. |
| **VFW_S_DUPLICATE_NAME** | Success; the Filter Graph Manager modified the filter name to avoid duplication. |
| **VFW_S_PARTIAL_RENDER** | Some of the streams in this movie are in an unsupported format. |
| **VFW_S_VIDEO_NOT_RENDERED** | Partial success; some of the streams in this movie are in an unsupported format. |
| **E_ABORT** | Operation aborted. |
| **E_FAIL** | Failure. |
| **E_INVALIDARG** | Argument is invalid. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_CANNOT_CONNECT** | No combination of intermediate filters could be found to make the connection. |
| **VFW_E_CANNOT_LOAD_SOURCE_FILTER** | The source filter for this file could not be loaded. |
| **VFW_E_CANNOT_RENDER** | No combination of filters could be found to render the stream. |
| **VFW_E_INVALID_FILE_FORMAT** | The file format is invalid. |
| **VFW_E_NOT_FOUND** | An object or name was not found. |
| **VFW_E_UNKNOWN_FILE_TYPE** | The media type of this file is not recognized. |
| **VFW_E_UNSUPPORTED_STREAM** | Cannot play back the file: the format is not supported. |

## Remarks

If the *lpwstrFile* parameter specifies a media file, the method builds a filter graph for default playback. First it adds a source filter that can read the file, using the same process as the [IGraphBuilder::AddSourceFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-addsourcefilter) method. Then it renders the output pins on the source filter, adding intermediate filters if necessary. It tries filters in the same order as the [IGraphBuilder::Connect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-connect) method.

During the connection process, the Filter Graph Manager ignores pins on intermediate filters if the pin name begins with a tilde (~). For more information, see [PIN_INFO](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-pin_info).

Note that the `RenderFile` method does not remove any filters from the graph. If you call `RenderFile` twice, the second call simply adds more filters to the graph. When you run the graph, both sources will play at the same time.

#### Examples

The following example renders an AVI file for default playback:

| C++ |
| --- |
| ``` hr = pGraph->RenderFile(L"C:\\Media\\Example.avi", 0); ``` |

The following example downloads an AVI file over HTTP, using the [File Source (URL)](https://learn.microsoft.com/windows/desktop/DirectShow/file-source--url--filter) filter:

| C++ |
| --- |
| ``` hr = pGraph->RenderFile(L"http://example.microsoft.com/Example.avi", 0); ``` |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder)
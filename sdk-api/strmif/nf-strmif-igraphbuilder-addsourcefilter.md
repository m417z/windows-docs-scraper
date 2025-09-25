# IGraphBuilder::AddSourceFilter

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AddSourceFilter` method adds a source filter for a specified file to the filter graph.

## Parameters

### `lpcwstrFileName` [in]

Specifies the name of the file to load.

### `lpcwstrFilterName` [in]

Specifies a name for the source filter.

### `ppFilter` [out]

Receives a pointer to the filter's [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface. The caller must release the interface.

## Return value

Returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOINTERFACE** | The source filter does not support the [IFileSourceFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifilesourcefilter) interface. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_CANNOT_LOAD_SOURCE_FILTER** | The source filter for this file could not be loaded. |
| **VFW_E_NOT_FOUND** | File or object not found. |
| **VFW_E_UNKNOWN_FILE_TYPE** | The media type of this file was not recognized. |

## Remarks

This method searches for an installed filter that can read the specified file. If it finds one, the method adds it to the filter graph and returns a pointer to the filter's **IBaseFilter** interface. To determine the media type and compression scheme of the file, the Filter Graph Manager reads the first few bytes of the file, looking for specific patterns of bytes, as documented in the article [Registering a Custom File Type](https://learn.microsoft.com/windows/desktop/DirectShow/registering-a-custom-file-type).

The application is responsible for building the rest of the filter graph. To do so, call [IBaseFilter::EnumPins](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ibasefilter-enumpins) to enumerate the output pins on the source filter. Then use either the [IGraphBuilder::Connect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-connect) method or the [IGraphBuilder::Render](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-render) method.

If the method succeeds, the **IBaseFilter** interface has an outstanding reference count. The caller must release the interface.

To render a file for default playback, use the [IGraphBuilder::RenderFile](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-renderfile) method.

The Filter Graph Manager holds a reference count on the filter until the filter is removed from the graph or the Filter Graph Manager is released.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder)
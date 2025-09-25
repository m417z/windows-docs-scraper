# IFilterMapper::RegisterFilter

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IFilterMapper** interface is deprecated. Use [IFilterMapper2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltermapper2) instead.

Adds a filter to the registry; the filter can then be enumerated.

## Parameters

### `clsid` [in]

Globally unique identifier (**GUID**) of the filter.

### `Name` [in]

Descriptive name for the filter.

### `dwMerit` [in]

Position in the order of enumeration. Filters with higher merit are enumerated first.

## Return value

Returns an **HRESULT** value.

## Remarks

The merit (as defined by the *dwMerit* parameter) controls the order in which the filter graph manager tries filters when performing an operation as a result of a call to [IGraphBuilder::Connect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-connect), [IGraphBuilder::Render](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-render), or [IGraphBuilder::RenderFile](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-renderfile). The filter graph manager finds all filters registered with the correct media type and then tries the one with the highest merit, using other criteria in the registration to choose between filters with equal merit.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterMapper Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltermapper)
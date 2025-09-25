# IXMLGraphBuilder::BuildFromXML

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **BuildFromXML** method loads a filter graph from an XML element.

**Note** Support for this interface was removed in Windows 7. New applications should not use this interface.

## Parameters

### `pGraph` [in]

Pointer to the Filter Graph Manager's [IGraphBuilder](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder) interface. To create the [Filter Graph Manager](https://learn.microsoft.com/windows/desktop/DirectShow/filter-graph-manager), call **CoCreateInstance**. Do not add any filters to the graph before calling this method.

### `pxml` [in]

Pointer to the **IXMLElement** interface of an XML element object. The XML element object must contain the string returned by the [IXMLGraphBuilder::SaveToXML](https://learn.microsoft.com/windows/desktop/api/amxmlgraphbuilder/nf-amxmlgraphbuilder-ixmlgraphbuilder-savetoxml) method.

**Note** The **IXMLElement** interface is implemented in Microsoft XML Core Services (MSXML) version 1.0 but is not implemented in more recent versions of MSXML.

## Return value

Returns an **HRESULT** value.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IXMLGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/amxmlgraphbuilder/nn-amxmlgraphbuilder-ixmlgraphbuilder)
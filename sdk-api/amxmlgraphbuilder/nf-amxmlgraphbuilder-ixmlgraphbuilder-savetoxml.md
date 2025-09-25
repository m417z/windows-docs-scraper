# IXMLGraphBuilder::SaveToXML

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SaveToXML** method saves a filter graph to an XML element.

**Note** Support for this interface was removed in Windows 7. New applications should not use this interface.

## Parameters

### `pGraph` [in]

Pointer to the Filter Graph Manager's [IGraphBuilder](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder) interface.

### `pbstrxml` [out]

Pointer to a **BSTR** that receives the XML element. The caller must release the string by calling **SysFreeString**.

## Return value

Returns an **HRESULT** value.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IXMLGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/amxmlgraphbuilder/nn-amxmlgraphbuilder-ixmlgraphbuilder)
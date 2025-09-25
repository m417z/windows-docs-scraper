# IStreamBuilder::Backout

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Backout` method undoes steps taken in the [IStreamBuilder::Render](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-istreambuilder-render) method. This includes disconnecting and removing any filters that were added inside **Render**.

## Parameters

### `ppinOut` [in]

Pointer to the [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface of this pin.

### `pGraph` [in]

Pointer to the [IGraphBuilder](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder) interface of the Filter Graph Manager.

## Return value

Returns an **HRESULT** value. A return code of S_OK indicates to the graph builder that the disconnect was successful.

## Remarks

The following example shows how a filter would reverse the steps that are shown in the code example for the **IStreamBuilder::Render** method:

| C++ |
| --- |
| ``` STDMETHODIMP CMyOutputPin::BackOut(IPin *pPin, IGraphBuilder *pGraph) { CheckPointer(pPin, E_POINTER); CheckPointer(pGraph, E_POINTER);<br><br> HRESULT hr = S_OK; if (m_Connected != NULL) // Pointer to the pin we're connected to. { // Find the filter that owns the pin connected to us. FILTER_INFO fi; hr = m_Connected->QueryFilterInfo(&fi); if (SUCCEEDED(hr)) { if (fi.pFilter != NULL) { // Disconnect the pins. pGraph->Disconnect(m_Connected); pGraph->Disconnect(pPin); // Remove the filter from the graph. pGraph->RemoveFilter(fi.pFilter); fi.pFilter->Release(); } else { hr = E_UNEXPECTED; } } } return hr; } ``` |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IStreamBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-istreambuilder)
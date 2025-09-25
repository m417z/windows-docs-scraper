# IStreamBuilder::Render

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Render` method completes rendering of the stream originating with this pin. This can involve adding filters to the filter graph and connecting them.

## Parameters

### `ppinOut` [in]

Pointer to the [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface of this pin.

### `pGraph` [in]

Pointer to the [IGraphBuilder](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder) interface of the Filter Graph Manager.

## Return value

Returns an **HRESULT** value. A return code of S_OK indicates that the stream was successfully rendered.

## Remarks

The following code illustrates how to implement this method on an output pin. This example assumes that the filter requires a custom renderer downstream from it.

| C++ |
| --- |
| ``` STDMETHODIMP CMyOutputPin::Render(IPin *pPin, IGraphBuilder *pGraph) { CheckPointer(pPin, E_POINTER); CheckPointer(pGraph, E_POINTER);<br><br> // This filter needs a special renderer connected to it. IBaseFilter *pMyRenderer = NULL;<br><br> // Create the renderer. HRESULT hr = CoCreateInstance(CLSID_MyRenderer, NULL, CLSCTX_INPROC, IID_IBaseFilter, (void **)&pMyRenderer); if (FAILED(hr)) { return hr; } // Add my renderer to the filter graph. hr = pGraph->AddFilter(pMyRenderer, L"My Renderer"); if (FAILED(hr)) { pMyRenderer->Release(); return hr; }<br><br> IEnumPins *pEnumPins; IPin *pMyRendererInputPin = NULL; hr = pMyRenderer->EnumPins(&pEnumPins); if (SUCCEEDED(hr)) { if (S_OK != pEnumPins->Next(1, &pMyRendererInputPin, 0)) { hr = E_UNEXPECTED; } } if (SUCCEEDED(hr)) { // Connect my renderer to my output pin. hr = pGraph->ConnectDirect(pPin, pMyRendererInputPin); pMyRendererInputPin->Release(); } if (FAILED(hr)) { // Could not connect to my renderer. Remove it from the graph. pGraph->RemoveFilter(pMyRenderer); } pMyRenderer->Release(); return hr; } ``` |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IStreamBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-istreambuilder)
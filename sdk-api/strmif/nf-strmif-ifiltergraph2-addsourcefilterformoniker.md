# IFilterGraph2::AddSourceFilterForMoniker

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `AddSourceFilterForMoniker` method creates a source filter from an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) pointer and adds the filter to the graph. For example, you can obtain a moniker for a system device, such as a video capture device, and add a video capture filter for that device. (For more information about system device monikers, see the [ICreateDevEnum](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icreatedevenum) interface.)

## Parameters

### `pMoniker` [in]

Pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface.

### `pCtx` [in]

Pointer to an [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) bind context interface.

### `lpcwstrFilterName` [in]

Name for the filter.

### `ppFilter` [out]

Receives a pointer to the source filter's [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) pointer. The caller must release the interface.

## Return value

Returns and **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_S_DUPLICATE_NAME** | Success; but the specified name was a duplicate, so the Filter Graph Manager modified the name. |
| **E_FAIL** | Failure. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **VFW_E_DUPLICATE_NAME** | Failed to add a filter with a duplicate name. |
| **VFW_E_CANNOT_LOAD_SOURCE_FILTER** | The source filter for could not be loaded. |
| **VFW_E_UNKNOWN_FILE_TYPE** | The media type of this file is not recognized. |

## Remarks

The Filter Graph Manager holds a reference count on the filter until the filter is removed from the graph or the Filter Graph Manager is released.

#### Examples

| C++ |
| --- |
| ``` IBaseFilter *pSource = NULL; IMoniker *pMoniker = NULL;<br><br>// Use IEnumMonikers to get the IMoniker pointer. (Not shown.)<br><br>// Create a bind context for working with the moniker. IBindCtx *pContext=0; hr = CreateBindCtx(0, &pContext); if (SUCCEEDED(hr)) {     // Query the Filter Graph Manager for IFilterGraph2.     IFilterGraph2 *pFG2 = NULL;     hr = pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pFG2);     if (SUCCEEDED(hr))     {         // Create the source filter.         hr = pFG2->AddSourceFilterForMoniker(pMoniker, pContext,                  L"Source", &pSource);         pFG2->Release();     }     pContext->Release(); } pMoniker->Release(); ``` |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterGraph2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltergraph2)
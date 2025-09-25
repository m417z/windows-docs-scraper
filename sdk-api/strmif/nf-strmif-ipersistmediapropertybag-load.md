# IPersistMediaPropertyBag::Load

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Load` method loads properties from the media property bag into the filter.

## Parameters

### `pPropBag` [in]

Pointer to the [IMediaPropertyBag](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediapropertybag) interface of a media property bag created by the caller.

### `pErrorLog` [in]

Reserved. Set the value to **NULL**.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | **NULL** pointer argument. |
| **STG_E_ACCESSDENIED** | Access denied. |
| **VFW_E_WRONG_STATE** | Filter graph is not in a stopped state. |

## Remarks

Call this method on the [AVI Mux](https://learn.microsoft.com/windows/desktop/DirectShow/avi-mux-filter) filter to write the properties into the AVI stream. Call the method when the filter is stopped, before you run the filter graph to author the file. When the graph runs, the filter writes the INFO chunks into the AVI header.

The following code example adds an IART (author name) INFO chunk to a file:

| C++ |
| --- |
| ``` IPersistMediaPropertyBag *pPersist = NULL; IMediaPropertyBag *pBag = NULL; VARIANT val;<br><br>// Query the AVI Mux filter for IPersistMediaPropertyBag (not shown).<br><br>CoCreateInstance(CLSID_MediaPropertyBag, NULL, CLSCTX_INPROC,         IID_IMediaPropertyBag, (LPVOID *)&pBag);<br><br>val.vt = VT_BSTR; val.bstrVal = SysAllocString(OLESTR("Author Name")); pBag->Write(OLESTR("INFO/IART"), &val); pPersist->Load(pBag, NULL); VariantClear(&val); ``` |

The [AVI Splitter](https://learn.microsoft.com/windows/desktop/DirectShow/avi-splitter-filter) filter and the [WAVE Parser](https://learn.microsoft.com/windows/desktop/DirectShow/wave-parser-filter) do not support this method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPersistMediaPropertyBag Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipersistmediapropertybag)
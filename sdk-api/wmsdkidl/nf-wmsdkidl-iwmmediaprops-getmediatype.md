# IWMMediaProps::GetMediaType

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetMediaType** method retrieves a structure describing the media type.

## Parameters

### `pType` [out]

Pointer to a [WM_MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_media_type) structure. If this parameter is set to **NULL**, this method returns the size of the buffer required in the *pcbType* parameter.

### `pcbType` [in, out]

On input, the size of the *pType* buffer. On output, if *pType* is set to **NULL**, the value this points to is set to the size of the buffer needed to hold the media type structure.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pcbType* parameter is **NULL**. |
| **ASF_E_BUFFERTOOSMALL** | The *pcbType* parameter is not large enough. |

## Remarks

You must make two calls to **GetMediaType**. On the first call, pass **NULL** as *pType*. On return, the value of *pcbType* will be set to the buffer size required to hold the **WM_MEDIA_TYPE** structure. Then you can allocate a buffer of the required size and pass a pointer to it as *pType* on the second call.

## See also

[IWMMediaProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmmediaprops)

[IWMMediaProps::SetMediaType](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmediaprops-setmediatype)

[Media Types](https://learn.microsoft.com/windows/desktop/wmformat/media-types)
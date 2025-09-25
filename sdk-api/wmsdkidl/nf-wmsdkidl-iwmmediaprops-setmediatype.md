# IWMMediaProps::SetMediaType

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetMediaType** method specifies the media type.

## Parameters

### `pType` [in]

Pointer to the [WM_MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_media_type) structure describing the input, stream, or output.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pType* parameter is **NULL**, cbFormat is 0 or too large, or pbFormat is **NULL**. |
| **E_OUTOFMEMORY** | There is not enough available memory. |

## Remarks

It is possible to successfully set a media type in this method that will ultimately be rejected as invalid when the profile is set on the writer. For a list of tests that the writer performs on the profile, see [IWMWriter::SetProfile](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-setprofile).

## See also

[IWMMediaProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmmediaprops)

[IWMMediaProps::GetMediaType](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmediaprops-getmediatype)
# IWMHeaderInfo::AddMarker

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AddMarker** method adds a [marker](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary), consisting of a name and a specific time, to the header section of the ASF file.

## Parameters

### `pwszMarkerName` [in]

Pointer to a wide-character null-terminated string containing the marker name. Marker names are limited to 5120 wide characters.

### `cnsMarkerTime` [in]

The marker time in 100-nanosecond increments.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_STATE** | The object cannot currently be configured. |
| **E_POINTER** | *pwszMarkerName* is not a valid pointer. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

The writer does not support markers. When accessing **IWMheaderInfo** from the writer, calls to **AddMarker** will return E_NOTIMPL.

## See also

[IWMHeaderInfo Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo)

[IWMHeaderInfo2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo2)

[IWMHeaderInfo3](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)

[IWMHeaderInfo::GetMarker](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-getmarker)

[IWMHeaderInfo::RemoveMarker](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-removemarker)

[Markers](https://learn.microsoft.com/windows/desktop/wmformat/markers)
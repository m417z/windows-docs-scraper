# IWMHeaderInfo::GetMarker

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetMarker** method returns the name and time of a [marker](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary).

## Parameters

### `wIndex` [in]

**WORD** containing the index.

### `pwszMarkerName` [out]

Pointer to a wide-character **null**-terminated string containing the marker name.

### `pcchMarkerNameLen` [in]

On input, a pointer to a variable containing the length of the *pwszMarkerName* array in wide characters (2 bytes). On output, if the method succeeds, the variable contains the actual length of the name, including the terminating **null** character. To retrieve the length of the name, you must set this to zero and set *pwszMarkerName* and *pcnsMarkerTime* to **NULL**.

### `pcnsMarkerTime` [out]

Pointer to a variable specifying the marker time in 100-nanosecond increments.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ASF_E_BUFFERTOOSMALL** | The size specified by *pcchMarkerNameLen* is too small to receive the name. |
| **NS_E_INVALID_STATE** | The object is not in a configurable state. |
| **E_INVALIDARG** | *pcchMarkerNameLen* is **NULL**, or another parameter does not contain a valid value. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

The writer does not support markers, and returns E_NOTIMPL when this method is called.

## See also

[IWMHeaderInfo Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo)

[IWMHeaderInfo2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo2)

[IWMHeaderInfo3](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)

[IWMHeaderInfo::AddMarker](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-addmarker)

[IWMHeaderInfo::GetMarkerCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-getmarkercount)

[IWMHeaderInfo::RemoveMarker](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-removemarker)

[Markers](https://learn.microsoft.com/windows/desktop/wmformat/markers)
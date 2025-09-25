# IWMHeaderInfo::GetAttributeCount

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetAttributeCount** method returns the number of attributes defined in the header section of the ASF file. This method is replaced by [IWMHeaderInfo3::GetAttributeCountEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo3-getattributecountex) and [IWMHeaderInfo3::GetAttributeIndices](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo3-getattributeindices), and should no longer be used.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number. Pass zero for file-level attributes.

### `pcAttributes` [out]

Pointer to a count of the attributes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_REQUEST** | The object is not in a configurable state, or no profile has been set. |
| **E_INVALIDARG** | *wStreamNum* is not a valid stream number, or *pcAttributes* is **NULL**. |
| **E_POINTER** | *pcAttributes* is not a valid pointer. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |

## Remarks

Attributes in MP3 files cannot be specific to a particular stream. For MP3 files, always set the stream number to zero.

## See also

[Attributes](https://learn.microsoft.com/windows/desktop/wmformat/attributes)

[IWMHeaderInfo Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo)

[IWMHeaderInfo2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo2)

[IWMHeaderInfo3](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)

[IWMHeaderInfo::SetAttribute](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo-setattribute)
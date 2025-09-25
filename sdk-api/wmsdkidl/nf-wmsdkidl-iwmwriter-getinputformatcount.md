# IWMWriter::GetInputFormatCount

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetInputFormatCount** method retrieves the number of media format types supported by this input on the writer.

## Parameters

### `dwInputNumber` [in]

**DWORD** containing the input number.

### `pcFormats` [out]

Pointer to a count of formats.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pcFormats* parameter is **NULL**.<br><br>OR<br><br>*dwInputNumber* is too large. |

## See also

[IWMWriter Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriter)

[IWMWriter::GetInputFormat](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-getinputformat)

[To Enumerate Input Formats](https://learn.microsoft.com/windows/desktop/wmformat/to-enumerate-input-formats)
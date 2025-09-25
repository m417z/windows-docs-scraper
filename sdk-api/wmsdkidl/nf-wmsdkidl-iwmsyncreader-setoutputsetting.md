# IWMSyncReader::SetOutputSetting

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetOutputSetting** method specifies a named setting for a particular output.

## Parameters

### `dwOutputNum` [in]

**DWORD** containing the output number.

### `pszName` [in]

Pointer to a **null**-terminated string containing the name of the setting. For a list of global constants representing setting names, see [Output Settings](https://learn.microsoft.com/windows/desktop/wmformat/output-settings).

### `Type` [in]

Member of the [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) enumeration type. This value specifies the type of data in the buffer at *pValue*.

### `pValue` [in]

Pointer to a byte array containing the value of the setting. The type of data stored in this buffer is specified by *Type*.

### `cbLength` [in]

Size of *pValue* in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pszName* or *pValue* is **NULL**.<br><br>OR<br><br>*dwOutputNum* specifies an invalid output number. |
| **E_UNEXPECTED** | No file is open in the synchronous reader. |
| **NS_E_INVALID_REQUEST** | *pszName* specifies an unsupported setting. |

## See also

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)

[IWMSyncReader::GetOutputSetting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-getoutputsetting)
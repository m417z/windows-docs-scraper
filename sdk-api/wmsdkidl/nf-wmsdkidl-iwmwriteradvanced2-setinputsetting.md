# IWMWriterAdvanced2::SetInputSetting

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetInputSetting** method specifies a named setting for a particular input.

## Parameters

### `dwInputNum` [in]

**DWORD** containing the input number.

### `pszName` [in]

Pointer to a wide-character **null**-terminated string containing the setting name. For a list of valid settings, see [Input Settings](https://learn.microsoft.com/windows/desktop/wmformat/input-settings).

### `Type` [in]

Pointer to a value from the [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) enumeration type.

### `pValue` [in]

Pointer to a byte array containing the setting.

### `cbLength` [in]

Size of *pValue*, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_NOT_CONFIGURED** | The input profile has not yet been set. |
| **E_INVALIDARG** | *dwInputNum* is larger than the number of existing inputs<br><br>OR<br><br>*pValue* or *pszName* is **NULL**. |
| **NS_E_INVALID_REQUEST** | This setting cannot be changed while the writer is running. |
| **E_UNEXPECTED** | Unspecified error. |

## Remarks

The encoding settings set with this method are not persisted in the output file. If you want your custom player to have access to this information, you must save the values as custom metadata attributes in the file header.

Only g_wszDeinterlaceMode, g_wszInitialPatternForInverseTelecine, g_wszInterlacedCoding, and g_wszJPEGCompressionQuality can be set after [IWMWriter::BeginWriting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-beginwriting) has been called.

## See also

[IWMWriterAdvanced2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriteradvanced2)

[IWMWriterAdvanced2::GetInputSetting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced2-getinputsetting)

[Input Formats, Input Settings, and Data Unit Extensions](https://learn.microsoft.com/windows/desktop/wmformat/input-formats-input-settings-and-data-unit-extensions)

[To Set Input Settings](https://learn.microsoft.com/windows/desktop/wmformat/to-set-input-settings)
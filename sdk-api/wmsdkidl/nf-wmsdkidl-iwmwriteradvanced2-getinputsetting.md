# IWMWriterAdvanced2::GetInputSetting

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetInputSetting** method retrieves a setting for a particular input by name.

## Parameters

### `dwInputNum` [in]

**DWORD** containing the input number.

### `pszName` [in]

Pointer to a wide-character **null**-terminated string containing the setting name. For a list of valid settings, see [Input Settings](https://learn.microsoft.com/windows/desktop/wmformat/input-settings).

### `pType` [out]

Pointer to a value from the [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) enumeration type.

### `pValue` [out]

Pointer to a byte array containing the setting. The type of date is determined by *pType*. Pass **NULL** to retrieve the size of array required.

### `pcbLength` [in, out]

On input, pointer to the length of *pValue*. On output, pointer to a count of the bytes in *pValue* filled in by this method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_NOT_CONFIGURED** | The input profile has not yet been set. |
| **E_INVALIDARG** | *dwInputNum* is larger than the number of existing inputs<br><br>OR<br><br>*pType*, *pcbLength*, or *pszName* is **NULL**. |

## Remarks

You should make two calls to **GetInputSetting** for each setting you want to retrieve. On the first call, pass **NULL** as *pValue*. On return, the value pointed to by *pcbLength* is set to the buffer size required to hold the setting value. Then you can allocate the required amount of memory for the buffer and pass a pointer to it as *pValue* on the second call.

## See also

[IWMWriterAdvanced2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriteradvanced2)

[IWMWriterAdvanced2::SetInputSetting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced2-setinputsetting)

[Input Formats, Input Settings, and Data Unit Extensions](https://learn.microsoft.com/windows/desktop/wmformat/input-formats-input-settings-and-data-unit-extensions)

[To Set Input Settings](https://learn.microsoft.com/windows/desktop/wmformat/to-set-input-settings)
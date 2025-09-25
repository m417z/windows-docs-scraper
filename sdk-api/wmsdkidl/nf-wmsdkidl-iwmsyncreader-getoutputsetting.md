# IWMSyncReader::GetOutputSetting

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetOutputSetting** method retrieves a setting for a particular output by name.

## Parameters

### `dwOutputNum` [in]

**DWORD** containing the output number.

### `pszName` [in]

Pointer to a wide-character **null**-terminated string containing the name of the setting for which you want the value. For a list of global constants representing setting names, see [Output Settings](https://learn.microsoft.com/windows/desktop/wmformat/output-settings).

### `pType` [out]

Pointer to a variable that receives one value from the [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) enumeration type. The value received specifies the type of data in *pValue*.

### `pValue` [out]

Pointer to a byte buffer containing the value. Pass **NULL** to retrieve the length of the buffer required.

### `pcbLength` [in, out]

On input, pointer to a variable containing the length of *pValue*. On output, the variable contains the number of bytes in *pValue* used.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *dwOutputNum* specifies an invalid output number.<br><br>OR<br><br>*pszName* or *pType* or *pcbLength* is **NULL**.<br><br>OR<br><br>*pszName* specifies an invalid setting name. |
| **E_UNEXPECTED** | No file is open in the synchronous reader. |
| **ASF_E_BUFFERTOOSMALL** | The buffer size passed as *pcbLength* is not large enough to contain the setting value. |
| **NS_E_INVALID_REQUEST** | *pszName* specifies an unsupported setting. |

## Remarks

You should make two calls to **GetOutputSetting** for each setting you want to retrieve. On the first call, pass **NULL** as *pValue*. On return, the value of *pcbLength* is set to the buffer size required to hold the value of the specified setting. Then you can allocate the required amount of memory for the buffer and pass a pointer to it as *pValue* on the second call.

If you pass a buffer as *pValue* that is not large enough to contain the data, an error code of ASF_E_BUFFERTOOSMALL is returned. When returning this error code, the method still sets the value of *pcbLength* to the correct size of the value.

## See also

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)

[IWMSyncReader::SetOutputSetting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-setoutputsetting)
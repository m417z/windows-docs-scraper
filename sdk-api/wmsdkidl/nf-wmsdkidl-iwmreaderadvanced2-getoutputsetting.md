# IWMReaderAdvanced2::GetOutputSetting

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetOutputSetting** method retrieves a setting for a particular output by name.

## Parameters

### `dwOutputNum` [in]

**DWORD** containing the output number.

### `pszName` [in]

Pointer to a wide-character **null**-terminated string containing the setting name. For a list of global constants representing setting names, see [Output Settings](https://learn.microsoft.com/windows/desktop/wmformat/output-settings).

### `pType` [out]

Pointer to a member of the [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) enumeration type that specifies the type of the value.

### `pValue` [out]

Pointer to a byte buffer containing the value. Pass **NULL** to retrieve the length of the buffer required.

### `pcbLength` [in, out]

On input, pointer to a variable containing the length of *pValue*. On output, the variable contains the number of bytes in *pValue*.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

You should make two calls to **GetOutputSetting**. On the first call, pass **NULL** for *pValue*. On return, the value pointed to by *pcbLength* is set to the buffer size required to hold the setting value. Then you can allocate the required amount of memory for the buffer and pass a pointer to it as *pValue* on the second call.

## See also

[IWMReaderAdvanced2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced2)
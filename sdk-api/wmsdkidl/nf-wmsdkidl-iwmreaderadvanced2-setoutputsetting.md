# IWMReaderAdvanced2::SetOutputSetting

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetOutputSetting** method specifies a named setting for a particular output.

## Parameters

### `dwOutputNum` [in]

**DWORD** containing the output number.

### `pszName` [in]

Pointer to a wide-character null-terminated string containing the name. For a list of global constants that represent setting names, see [Output Settings](https://learn.microsoft.com/windows/desktop/wmformat/output-settings).

### `Type` [in]

Member of the [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) enumeration type that specifies the type of the value.

### `pValue` [in]

Pointer to a byte array containing the value.

### `cbLength` [in]

Size of *pValue*.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[IWMReaderAdvanced2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced2)

[IWMReaderAdvanced2::GetOutputSetting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced2-getoutputsetting)
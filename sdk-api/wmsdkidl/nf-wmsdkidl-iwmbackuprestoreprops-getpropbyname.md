# IWMBackupRestoreProps::GetPropByName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**GetPropByName** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **GetPropByName** method retrieves the value of a property by name.

This method is not implemented.

## Parameters

### `pszName` [in]

Pointer to a wide-character **null**-terminated string containing the name.

### `pType` [out]

Pointer to a variable containing one member of the **WMT_ATTR_DATATYPE** enumeration type.

### `pValue` [out]

Pointer to a byte array containing the value of the property.

### `pcbLength` [in, out]

On input, contains the length of *pValue*. On output, points to a count of the bytes in *pValue* that are used.

## Return value

The method returns E_NOTIMPL.

## Remarks

You should make two calls to **GetPropByName**. On the first call, pass **NULL** as *pValue*. On return, the value pointed to by *pcbLength* is set to the buffer size required to hold the property value. Then you can allocate the required amount of memory for the buffer and pass a pointer to it as *pValue* on the second call.

## See also

[IWMBackupRestoreProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmbackuprestoreprops)

[IWMBackupRestoreProps::SetProp](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmbackuprestoreprops-setprop)

[WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype)
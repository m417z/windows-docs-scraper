# IWMBackupRestoreProps::GetPropByIndex

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**GetPropByIndex** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **GetPropByIndex** method retrieves the name and value of a property by index.

This method is not implemented.

## Parameters

### `wIndex` [in]

**WORD** containing the index of the property.

### `pwszName` [out]

Pointer to a wide-character **null**-terminated string containing the name.

### `pcchNameLen` [in, out]

On input, contains the length of *pwszName*. On output, points to a variable containing the number of characters in *pwszName*, including the terminating **null** character.

### `pType` [out]

Pointer to a variable containing one member of the [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) enumeration type.

### `pValue` [out]

Pointer to a byte array containing the value of the property.

### `pcbLength` [in, out]

On input, contains the length of *pValue*. On output, points to a count of the bytes in *pValue* that are used.

## Return value

The method returns E_NOTIMPL.

## Remarks

You should make two calls to **GetPropByIndex**. On the first call, pass **NULL** for *pwszName* and *pValue*. On return, the value pointed to by *pcchNameLen* is set to the length in wide characters of the property name (including the terminating **null** character) and the value pointed to by *pcbLength* is set to the number of bytes required to hold the property value. You can then allocate buffers of the appropriate sizes to hold the values *pwszName* and *pValue* and pass pointers to them on the second call.

## See also

[IWMBackupRestoreProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmbackuprestoreprops)

[IWMBackupRestoreProps::SetProp](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmbackuprestoreprops-setprop)
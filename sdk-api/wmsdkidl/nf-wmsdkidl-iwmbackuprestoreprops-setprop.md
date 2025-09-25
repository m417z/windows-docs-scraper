# IWMBackupRestoreProps::SetProp

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**SetProp** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **SetProp** method adds a property, and specifies its name and value.

## Parameters

### `pszName` [in]

Pointer to a null-terminated string containing the name.

### `Type` [in]

Pointer to a variable containing one member of the [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) enumeration type. The current implementation of this method accepts only WMT_TYPE_STRING. Specifying a different type causes the method to return E_INVALIDARG.

### `pValue` [in]

Pointer to a byte array containing the value of the property.

### `cbLength` [in]

Length of *pValue*, in bytes.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

This method is used to set properties that are needed by the other backup restorer object interfaces.

The following table lists the predefined properties.

| Property name | Type | Description |
| --- | --- | --- |
| **BackupPath** | **String** | Full path to the location where the backup files must be saved. |
| **RestorePath** | **String** | Full path to the location where the backup files can be found and used to restore data. |

## See also

[IWMBackupRestoreProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmbackuprestoreprops)

[IWMLicenseBackup Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmlicensebackup)

[IWMLicenseRestore Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmlicenserestore)
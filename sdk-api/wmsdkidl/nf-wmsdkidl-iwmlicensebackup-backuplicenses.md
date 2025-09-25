# IWMLicenseBackup::BackupLicenses

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**BackupLicenses** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **BackupLicenses** method saves copies of the licenses.

## Parameters

### `dwFlags` [in]

**DWORD** containing the flags.

| Flag | Description |
| --- | --- |
| WM_BACKUP_OVERWRITE | Indicates that any existing backup file should be overwritten. If this is not set, and a backup file exists, the NS_E_DRM_BACKUP_EXISTS error code is returned. |

### `pCallback` [in]

Pointer to an object that implements the [IWMStatusCallback](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstatuscallback) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pCallback* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Not enough memory available to perform the task. |

## Remarks

For more information on how to specify the location of the backup file (there are predefined properties for the backup path and restore path for this purpose), see [IWMBackupRestoreProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmbackuprestoreprops).

This method operates asynchronously, and an **IWMStatusCallback** object can be used to track progress.

## See also

[IWMBackupRestoreProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmbackuprestoreprops)

[IWMLicenseBackup Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmlicensebackup)
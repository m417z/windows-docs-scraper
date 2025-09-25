# WMCreateBackupRestorer function

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMCreateBackupRestorer** function creates a backup restorer object.

## Parameters

### `pCallback` [in]

Pointer to an [IWMStatusCallback](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstatuscallback) interface containing the **OnStatus** callback method to be used by the new backup restorer object.

### `ppBackup` [out]

Pointer to a pointer to the [IWMLicenseBackup](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmlicensebackup) interface of the newly created backup restorer object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_OUTOFMEMORY** | The function is unable to allocate memory for the new object. |

## Remarks

Use **IWMLicenseBackup::QueryInterface** to obtain a pointer to the [IWMBackupRestoreProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmbackuprestoreprops) interface.

## See also

[Backup Restorer Object](https://learn.microsoft.com/windows/desktop/wmformat/backup-restorer-object)

[Functions](https://learn.microsoft.com/windows/desktop/wmformat/functions)
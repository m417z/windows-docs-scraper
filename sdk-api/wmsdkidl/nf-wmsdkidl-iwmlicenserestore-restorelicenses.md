# IWMLicenseRestore::RestoreLicenses

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**RestoreLicenses** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **RestoreLicenses** method restores licenses that were previously backed up.

## Parameters

### `dwFlags` [in]

**DWORD** containing the flags.

| Flag | Description |
| --- | --- |
| WM_RESTORE_INDIVIDUALIZE | Indicates that the application has received permission from the user to individualize their computer. (See [Individualizing DRM Applications](https://learn.microsoft.com/windows/desktop/wmformat/individualizing-drm-applications) section.) |

### `pCallback` [in]

Pointer to an [IWMStatusCallback](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstatuscallback) interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

For more information on how to specify the location of the backup file (there are predefined properties for the backup path and restore path for this purpose), see [IWMBackupRestoreProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmbackuprestoreprops).

The operation of this method is asynchronous, and an **IWMStatusCallback** interface can be used to track progress.

## See also

[IWMLicenseRestore Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmlicenserestore)
# WM\_BACKUP\_RESTORE\_STATUS structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WM\_BACKUP\_RESTORE\_STATUS** structure holds information about a pending license backup or restore operation.

## Members

**eStatus**

Member of the [**MSDRM\_STATUS**](https://learn.microsoft.com/windows/win32/wmformat/msdrm-status) enumeration specifying the status.

**bstrError**

String containing the error.

## Remarks

This structure is received when you call the [**IWMDRMLicenseBackupRestoreStatus::GetStatus**](https://learn.microsoft.com/windows/win32/wmformat/iwmdrmlicensebackuprestorestatus-getstatus) method. It contains the status of the pending backup or restore operation at the time of the call.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)


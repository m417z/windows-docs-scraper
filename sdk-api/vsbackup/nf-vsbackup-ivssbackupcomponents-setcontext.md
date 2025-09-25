# IVssBackupComponents::SetContext

## Description

The **SetContext** method sets the context
for subsequent shadow copy-related operations.

## Parameters

### `lContext` [in]

The context to be set. The context must be one of the supported values of
[_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context) or a supported bit mask (or
bitwise OR) of
[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes) with a
valid **_VSS_SNAPSHOT_CONTEXT**.

## Return value

The default return value of this method is S_OK. The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the context. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The default context for VSS shadow copies is VSS_CTX_BACKUP.

**Windows XP:** The only supported context is the default context, VSS_CTX_BACKUP. Therefore, calling
**SetContext** under Windows XP returns
E_NOTIMPL.

**SetContext** can be called only once,
and it must be called prior to calling most VSS functions.

For details on how the context set by
**IVssBackupComponents::SetContext** affects
how a shadow copy is created and managed, see
[Implementation Details for
Creating Shadow Copies](https://learn.microsoft.com/windows/desktop/VSS/implementation-details-for-creating-shadow-copies).

For a complete discussion of the permitted shadow copy contexts, see
[_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context) and
[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes).

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset)

[IVssBackupComponents::StartSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-startsnapshotset)

[_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context)

[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes)
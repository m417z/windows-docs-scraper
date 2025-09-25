# IVssComponent::SetBackupStamp

## Description

The
**SetBackupStamp** method sets a string containing information indicating when a backup took place.

A writer can call this method only during a backup operation.

This method cannot be called while handling a
[BackupComplete](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-b) ([CVssWriter::OnBackupComplete](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupcomplete)) or [BackupShutdown](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-b) ([CVssWriter::OnBackupShutdown](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupshutdown)) event.

## Parameters

### `wszBackupStamp` [in]

Null-terminated wide character string information indicating when a backup took place.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the backup time stamp. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | This method was not called by a writer or, if called by a writer, it either was not called during a backup operation or was called while handling a BackupComplete or BackupShutdown event. |

## Remarks

For more information about backup stamps, see [Writer Role in Backing Up Complex Stores](https://learn.microsoft.com/windows/desktop/VSS/writer-role-in-backing-up-complex-stores).

The backup stamp set by
**SetBackupStamp** applies to all files in the component and any nonselectable subcomponents it has.

Writers typically call
**SetBackupStamp** while handling a [PostSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) event in
[CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot).

Requesters merely store the backup stamp in the Backup Components Document. They do not make direct use of the backup stamp or have to know how to interpret it.

The only use of the backup stamp that a requester makes, during a restore operation, is to make the stored time-stamp string available to a writer by using the
[IVssBackupComponents::SetPreviousBackupStamp](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setpreviousbackupstamp) method.

For this reason, there are no format restrictions on the content of the backup stamp. It may contain time and date information, logical sequence numbers, or any other information that will allow a writer of the same class to determine when the last backup has taken place.

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::GetBackupStamp](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getbackupstamp)
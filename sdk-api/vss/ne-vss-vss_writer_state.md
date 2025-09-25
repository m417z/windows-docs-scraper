# VSS_WRITER_STATE enumeration

## Description

The **VSS_WRITER_STATE** enumeration indicates the current
state of the writer.

## Constants

### `VSS_WS_UNKNOWN:0`

The writer's state is not known.

This indicates an error on the part of the writer.

### `VSS_WS_STABLE`

The writer has completed processing current shadow copy events and is ready to proceed, or
[CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot) has not yet
been called.

### `VSS_WS_WAITING_FOR_FREEZE`

The writer is waiting for the freeze state.

### `VSS_WS_WAITING_FOR_THAW`

The writer is waiting for the thaw state.

### `VSS_WS_WAITING_FOR_POST_SNAPSHOT`

The writer is waiting for the
[PostSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) state.

### `VSS_WS_WAITING_FOR_BACKUP_COMPLETE`

The writer is waiting for the requester to finish its backup operation.

### `VSS_WS_FAILED_AT_IDENTIFY`

The writer vetoed the shadow copy creation process at the writer identification state.

### `VSS_WS_FAILED_AT_PREPARE_BACKUP`

The writer vetoed the shadow copy creation process during the backup preparation state.

### `VSS_WS_FAILED_AT_PREPARE_SNAPSHOT`

The writer vetoed the shadow copy creation process during the [PrepareForSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) state.

### `VSS_WS_FAILED_AT_FREEZE`

The writer vetoed the shadow copy creation process during the freeze state.

### `VSS_WS_FAILED_AT_THAW`

The writer vetoed the shadow copy creation process during the thaw state.

### `VSS_WS_FAILED_AT_POST_SNAPSHOT`

The writer vetoed the shadow copy creation process during the
[PostSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) state.

### `VSS_WS_FAILED_AT_BACKUP_COMPLETE`

The shadow copy has been created and the writer failed during the
[BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete) state. A writer
should save information about this failure to the error log. For additional information on logging, see
[Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).

### `VSS_WS_FAILED_AT_PRE_RESTORE`

The writer failed during the
[PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore) state.

### `VSS_WS_FAILED_AT_POST_RESTORE`

The writer failed during the
[PostRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-postrestore) state.

### `VSS_WS_FAILED_AT_BACKUPSHUTDOWN`

The writer failed during the shutdown of the backup application.

### `VSS_WS_COUNT`

Reserved value.

## Remarks

A requester determines the state of a writer through
[IVssBackupComponents::GetWriterStatus](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getwriterstatus).

## See also

[CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot)

[IVssBackupComponents::GetWriterStatus](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getwriterstatus)
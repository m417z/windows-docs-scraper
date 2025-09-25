# VSS_BACKUP_TYPE enumeration

## Description

The **VSS_BACKUP_TYPE** enumeration indicates the
type of backup to be performed using VSS writer/requester coordination.

## Constants

### `VSS_BT_UNDEFINED:0`

The backup type is not known.

This value indicates an application error.

### `VSS_BT_FULL`

Full backup: all files, regardless of whether they have been marked as backed up or not, are saved. This is
the default backup type and schema, and all writers support it.

Each file's backup history will be updated to reflect that it was backed up.

### `VSS_BT_INCREMENTAL`

Incremental backup: files created or changed since the last full or incremental backup are saved. Files are
marked as having been backed up.

A requester can implement this sort of backup on a particular writer only if it supports the
**VSS_BS_INCREMENTAL** schema.

If a requester's backup type is **VSS_BT_INCREMENTAL** and a particular writer's
backup schema does not support that sort of backup, the requester will always perform a full
(**VSS_BT_FULL**) backup on that writer's data.

### `VSS_BT_DIFFERENTIAL`

Differential backup: files created or changed since the last full backup are saved. Files are not marked as
having been backed up.

A requester can implement this sort of backup on a particular writer only if it supports the
**VSS_BS_DIFFERENTIAL** schema.

If a requester's backup type is **VSS_BT_DIFFERENTIAL** and a particular writer's
backup schema does not support that sort of backup, the requester will always perform a full
(**VSS_BT_FULL**) backup on that writer's data.

### `VSS_BT_LOG`

The log file of a writer is to participate in backup or restore operations.

A requester can implement this sort of backup on a particular writer only if it supports the
**VSS_BS_LOG** schema.

If a requester's backup type is **VSS_BT_LOG** and a particular writer's backup
schema does not support that sort of backup, the requester will always perform a full
(**VSS_BT_FULL**) backup on that writer's data.

### `VSS_BT_COPY`

Files on disk will be copied to a backup medium regardless of the state of each file's backup history, and
the backup history will not be updated.

A requester can implement this sort of backup on a particular writer only if it supports the
**VSS_BS_COPY** schema.

If a requester's backup type is **VSS_BT_COPY** and a particular writer's backup
schema does not support that sort of backup, the requester will always perform a full
(**VSS_BT_FULL**) backup on that writer's data.

### `VSS_BT_OTHER`

Backup type that is not full, copy, log, incremental, or differential.

## Remarks

An implementation of a backup type defined by a
**VSS_BACKUP_TYPE** value must be done using the VSS API.

This is particularly true in the case of incremental (**VSS_BT_INCREMENTAL**) and
differential (**VSS_BT_DIFFERENTIAL**) backups. In these cases, requesters and writers
work together using the file backup specification masks
([VSS_FILE_SPEC_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_file_spec_backup_type)), and designations of
files as being part of partial and differenced file operations to select which files must be backed up.

A requester may also use other more traditional techniques to implement an incremental or differential
restore, but it must not override the information provided through the VSS interfaces.

If a requester, when processing a given backup type, encounters a writer that does not support that backup
type, the requester performs backup or restore operations for that particular writer's data as if the backup type
was **VSS_BT_FULL**.

Requesters set the backup type with a call to
[IVssBackupComponents::SetBackupState](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setbackupstate).

Writers use
[CVssWriter::GetBackupType](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-getbackuptype) to determine the
backup type.

## See also

[CVssWriter::GetBackupType](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-getbackuptype)

[IVssBackupComponents::SetBackupState](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setbackupstate)
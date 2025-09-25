# VSS_BACKUP_SCHEMA enumeration

## Description

The **VSS_BACKUP_SCHEMA** enumeration is used by
a writer to indicate the types of backup operations it can participate in. The supported kinds of
backup are expressed as a bit mask (or bitwise OR) of
**VSS_BACKUP_SCHEMA** values.

## Constants

### `VSS_BS_UNDEFINED:0`

The writer supports a simple full backup and restoration of entire files (as defined by a
[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type) value of
**VSS_BT_FULL**). This backup scheme can be used as the basis of an incremental or
differential backup. This is the default value.

### `VSS_BS_DIFFERENTIAL:0x1`

The writer supports differential backups (corresponding to the
[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type) value
**VSS_BT_DIFFERENTIAL**). Files created or changed since the last full backup are saved.
Files are not marked as having been backed up.

This setting does not preclude mixing of incremental and differential backups.

This value is not supported for express writers.

### `VSS_BS_INCREMENTAL:0x2`

The writer supports incremental backups (corresponding to the
[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type) value
**VSS_BT_INCREMENTAL**). Files created or changed since the last full or incremental
backup are saved. Files are marked as having been backed up.

This setting does not preclude mixing of incremental and differential backups.

This value is not supported for express writers.

### `VSS_BS_EXCLUSIVE_INCREMENTAL_DIFFERENTIAL:0x4`

The writer supports both differential and incremental backup schemas, but only exclusively: for example,
you cannot follow a differential backup with an incremental one. A writer cannot support this schema if it does
not support both incremental and differential schemas (**VSS_BS_DIFFERENTIAL** |
**VSS_BS_INCREMENTAL**).

This value is not supported for express writers.

### `VSS_BS_LOG:0x8`

The writer supports backups that involve only the log files it manages (corresponding to a
[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type) value of
**VSS_BT_LOG**). This schema requires a writer to have added at least one file to at
least one component using the
[IVssCreateWriterMetadata::AddDataBaseLogFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabaselogfiles)
method. Requesters retrieve log file information using the
[IVssWMComponent::GetDatabaseLogFile](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getdatabaselogfile)
method.

### `VSS_BS_COPY:0x10`

Similar to the default backup schema (**VSS_BT_UNDEFINED**), the writer supports
copy backup operations (corresponding to **VSS_BT_COPY**) where file access information
(such as information as to when a file was last backed up) will not be updated either in the writer's own state
information or in the file system information. This type of backup cannot be used as the basis of an incremental
or differential backup.

### `VSS_BS_TIMESTAMPED:0x20`

A writer supports using the VSS time-stamp mechanism when evaluating if a file should be included in
differential or incremental operations (corresponding to **VSS_BT_DIFFERENTIAL** and
**VSS_BT_INCREMENTAL**, respectively) using the
[IVssComponent::GetBackupStamp](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getbackupstamp),
[IVssComponent::GetPreviousBackupStamp](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getpreviousbackupstamp),
[IVssComponent::SetBackupStamp](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setbackupstamp), and
[IVssBackupComponents::SetPreviousBackupStamp](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setpreviousbackupstamp)
methods.

A writer cannot support this schema if it does not support either differential or incremental backup schemas
(**VSS_BS_DIFFERENTIAL** or **VSS_BS_INCREMENTAL**).

This value is not supported for express writers.

### `VSS_BS_LAST_MODIFY:0x40`

When implementing incremental or differential backups with differenced files, a writer can provide last
modification time information for files (using
[IVssComponent::AddDifferencedFilesByLastModifyTime](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-adddifferencedfilesbylastmodifytime)).
A requester then can use
[IVssComponent::GetDifferencedFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getdifferencedfile) to
obtain candidate files and information about their last modification data. The requester can use this
information (along with any records about previous backup operations it maintains) to decide if a file should be
included in incremental and differential backups.

This scheme does not apply to partial file implementations of incremental and differential backup
operations.

A writer cannot support this schema if it does not support either incremental or differential backup schemas
(**VSS_BS_DIFFERENTIAL** or **VSS_BS_INCREMENTAL**).

This value is not supported for express writers.

### `VSS_BS_LSN:0x80`

Reserved for system use.

### `VSS_BS_WRITER_SUPPORTS_NEW_TARGET:0x100`

The writer supports a requester changing the target for file restoration using
[IVssBackupComponents::AddNewTarget](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addnewtarget).
(See [Non-Default Backup And Restore
Locations](https://learn.microsoft.com/windows/desktop/VSS/non-default-backup-and-restore-locations) for more information.)

This value is not supported for express writers.

### `VSS_BS_WRITER_SUPPORTS_RESTORE_WITH_MOVE:0x200`

The writer supports running multiple writer instances with the same class ID, and it supports a requester moving a component to a different writer instance at restore time using [IVssBackupComponentsEx::SetSelectedForRestoreEx](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex-setselectedforrestoreex).

This value is not supported for express writers.

**Windows Server 2003:** This value is not supported until Windows Server 2003 with SP1.

### `VSS_BS_INDEPENDENT_SYSTEM_STATE:0x400`

The writer supports backing up data that is part of the system state, but that can also be backed up independently of the system state.

**Windows Server 2003:** This value is not supported until Windows Vista.

### `VSS_BS_ROLLFORWARD_RESTORE:0x1000`

The writer supports a requester setting a roll-forward restore point using [IVssBackupComponentsEx2::SetRollForward](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex2-setrollforward).

This value is not supported for express writers.

**Windows Server 2003:** This value is not supported until Windows Vista.

### `VSS_BS_RESTORE_RENAME:0x2000`

The writer supports a requester setting a restore name using [IVssBackupComponentsEx2::SetRestoreName](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex2-setrestorename).

This value is not supported for express writers.

**Windows Server 2003:** This value is not supported until Windows Vista.

### `VSS_BS_AUTHORITATIVE_RESTORE:0x4000`

The writer supports a requester setting authoritative restore using [IVssBackupComponentsEx2::SetAuthoritativeRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex2-setauthoritativerestore).

This value is not supported for express writers.

**Windows Server 2003:** This value is not supported until Windows Vista.

### `VSS_BS_WRITER_SUPPORTS_PARALLEL_RESTORES:0x8000`

The writer supports multiple unsynchronized restore events.

This value is not supported for express writers.

**Windows Vista and Windows Server 2003:** This value is not supported until Windows Server 2008.

## Remarks

Writer set their backup schemas with calls to
[IVssCreateWriterMetadata::SetBackupSchema](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-setbackupschema).

Requesters use
[IVssExamineWriterMetadata::GetBackupSchema](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getbackupschema)
to determine the backup schema that a writer supports.

For a specific kind of backup operation to be supported, the writer must support the corresponding schema, and
the requester must set the corresponding backup type.

For example, to involve a writer in an incremental backup operation, the requester must set the backup type to
**VSS_BT_INCREMENTAL**, and the writer should have a backup schema that includes **VSS_BS_INCREMENTAL**.

A writer that does not support the backup schema corresponding to a requester's backup type should treat the backup operation that is being performed as if it were a default (full) backup. If the desired backup type is not supported by the writer's backup schema, the requester can either perform a full backup for this writer or exclude the writer from the backup operation. A requester can exclude a writer by selecting none of the writer's components (see
[Working with Selectability and
Logical Paths](https://learn.microsoft.com/windows/desktop/VSS/working-with-selectability-and-logical-paths)), or by disabling the writer (see
[IVssBackupComponents::DisableWriterClasses](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-disablewriterclasses) or
[IVssBackupComponents::DisableWriterInstances](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-disablewriterinstances)).

## See also

[IVssBackupComponents::SetBackupState](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setbackupstate)

[IVssBackupComponentsEx2::SetAuthoritativeRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex2-setauthoritativerestore)

[IVssBackupComponentsEx2::SetRestoreName](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex2-setrestorename)

[IVssBackupComponentsEx2::SetRollForward](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex2-setrollforward)

[IVssBackupComponentsEx::SetSelectedForRestoreEx](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex-setselectedforrestoreex)

[IVssComponent::AddDifferencedFilesByLastModifyTime](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-adddifferencedfilesbylastmodifytime)

[IVssComponent::AddPartialFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-addpartialfile)

[IVssCreateWriterMetadata::SetBackupSchema](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-setbackupschema)

[IVssExamineWriterMetadata::GetBackupSchema](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getbackupschema)

[Incremental and Differential Backups](https://learn.microsoft.com/windows/desktop/VSS/incremental-and-differential-backups)

[VSS_COMPONENT_FLAGS](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_flags)

[VSS_USAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_usage_type)
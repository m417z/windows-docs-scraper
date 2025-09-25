# VSS_FILE_SPEC_BACKUP_TYPE enumeration

## Description

The **VSS_FILE_SPEC_BACKUP_TYPE** enumeration is
used by writers to indicate their support of certain backup
operations—such as incremental or differential backup—on the
basis of file sets (a specified file or files).

File sets stored in the Writer Metadata Document are tagged with a bit mask (or bitwise OR) of
**VSS_FILE_SPEC_BACKUP_TYPE** values indicating the
following:

* Whether the writer and the requester have to evaluate a given file set for participation in the specified
  type of backup operations
* Whether backing up the specified file will require a shadow copy

## Constants

### `VSS_FSBT_FULL_BACKUP_REQUIRED:0x1`

A file set tagged with this value must be involved in all types of backup operations.

A writer tags a file set with this value to indicate to the requester that it expects a copy of the current
version of the file set to be available following the restore of any backup operation with a
[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type) of
**VSS_BT_FULL**.

### `VSS_FSBT_DIFFERENTIAL_BACKUP_REQUIRED:0x2`

A writer tags a file set with this value to indicate to the requester that it expects a copy of the current
version of the file set to be available following the restore of any backup operation with a
[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type) of
**VSS_BT_DIFFERENTIAL**.

This value is not supported for express writers.

### `VSS_FSBT_INCREMENTAL_BACKUP_REQUIRED:0x4`

A writer tags a file set with this value to indicate to the requester that it expects a copy of the current
version of the file set to be available following the restore of any backup operation with a
[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type) of
**VSS_BT_INCREMENTAL**.

This value is not supported for express writers.

### `VSS_FSBT_LOG_BACKUP_REQUIRED:0x8`

A writer tags a file set with this value to indicate to the requester that it expects a copy of the current
version of the file set to be available following the restore of any backup operation with a
[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type) of
**VSS_BT_LOG**.

This value is not supported for express writers.

### `VSS_FSBT_FULL_SNAPSHOT_REQUIRED:0x100`

A file set tagged with this value must be backed up from a shadow copy of a volume (and never from the
original volume) when participating in a backup operation with a
[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type) of
**VSS_BT_FULL**.

### `VSS_FSBT_DIFFERENTIAL_SNAPSHOT_REQUIRED:0x200`

A file set tagged with this value must be backed up from a shadow copy of a volume (and never from the
original volume) when participating in a backup operation with a
[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type) of
**VSS_BT_DIFFERENTIAL**.

### `VSS_FSBT_INCREMENTAL_SNAPSHOT_REQUIRED:0x400`

A file set tagged with this value must be backed up from a shadow copy of a volume (and never from the
original volume) when participating in a backup operation with a
[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type) of
**VSS_BT_INCREMENTAL**.

### `VSS_FSBT_LOG_SNAPSHOT_REQUIRED:0x800`

A file set tagged with this value must be backed up from a shadow copy of a volume (and never from the
original volume) when participating in a backup operation with a
[VSS_BACKUP_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_type) of
**VSS_BT_LOG**).

### `VSS_FSBT_CREATED_DURING_BACKUP:0x10000`

A writer tags a file set with this value to indicate to the requester that they expect the file to be created during the snapshot sequence.

### `VSS_FSBT_ALL_BACKUP_REQUIRED:0xf`

The default file backup specification type. A file set tagged with this value must always participate in
backup and restore operations.

### `VSS_FSBT_ALL_SNAPSHOT_REQUIRED:0xf00`

The shadow copy requirement for backup. A file set tagged with this value must always be backed up from a
shadow copy of a volume (and never from the original volume) when participating in a backup operation.

## Remarks

When a writer sets a backup-required value of the
**VSS_FILE_SPEC_BACKUP_TYPE** enumeration, it is
indicating that the requester perform the backup in such a way that, when the backup is restored, the current
version of the file set is restored. Typically, this means that the file set is copied as part of the backup.

This setting can be overridden if a file is added to the Backup Components Document as a differenced file
(using
[IVssComponent::AddDifferencedFilesByLastModifyTime](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-adddifferencedfilesbylastmodifytime))
or as a partial file (using
[IVssComponent::AddPartialFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-addpartialfile)).

If a file is added as a differenced file, the writer establishes criteria by which the requester should decide
whether or not to actually copy a file to a backup medium. A writer typically adds differenced files to the Backup
Components Document for inclusion in a backup
[PostSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) event (see
[CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot)). See
[Incremental and Differential Backups](https://learn.microsoft.com/windows/desktop/VSS/incremental-and-differential-backups)
for details.

When a writer sets a shadow copy-required value of the
**VSS_FILE_SPEC_BACKUP_TYPE** enumeration, it
indicates that the file set should be backed up from a shadow-copied volume. File sets not tagged with a
shadow copy-required value can be backed up from the original volume.

Writers set **VSS_FILE_SPEC_BACKUP_TYPE** values
while handling an [Identify](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-i) event (see
[CVssWriter::OnIdentify](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onidentify)).

A bit mask (or bitwise OR) of
**VSS_FILE_SPEC_BACKUP_TYPE** values can be applied
to a file set when adding it to a component using the
[IVssCreateWriterMetadata::AddFilesToFileGroup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addfilestofilegroup),
[IVssCreateWriterMetadata::AddDatabaseFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabasefiles), or
[IVssCreateWriterMetadata::AddDatabaseLogFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabaselogfiles)
method.

If no explicit file specification backup type is supplied during the addition of a file specification to a
component, the specification is tagged with the default
**VSS_FILE_SPEC_BACKUP_TYPE** value:
(VSS_FSBT_ALL_BACKUP_REQUIRED | VSS_FSBT_ALL_SNAPSHOT_REQUIRED).

Requesters or writers can recover a file set's file specification backup type by using the
[IVssWMFiledesc::GetBackupTypeMask](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsswmfiledesc-getbackuptypemask)
method.

## See also

[IVssComponent::AddDifferencedFilesByLastModifyTime](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-adddifferencedfilesbylastmodifytime)

[IVssComponent::AddPartialFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-addpartialfile)

[IVssCreateWriterMetadata::AddDatabaseFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabasefiles)

[IVssCreateWriterMetadata::AddDatabaseLogFiles](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-adddatabaselogfiles)

[IVssCreateWriterMetadata::AddFilesToFileGroup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addfilestofilegroup)

[IVssWMFiledesc::GetBackupTypeMask](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsswmfiledesc-getbackuptypemask)

[Incremental and Differential Backups](https://learn.microsoft.com/windows/desktop/VSS/incremental-and-differential-backups)
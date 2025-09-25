# VSS_RESTOREMETHOD_ENUM enumeration

## Description

The **VSS_RESTOREMETHOD_ENUM** enumeration is
used by a writer at backup time to specify through its Writer Metadata Document the default file restore
method to be used with all the files in all the components it manages.

The restore method is writer-wide and is also referred to as the original restore target and indicated by a
[VSS_RESTORE_TARGET](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restore_target) value of
**VSS_RT_ORIGINAL**.

## Constants

### `VSS_RME_UNDEFINED:0`

No restore method is defined.

This indicates an error on the part of the writer.

This value is not supported for express writers.

### `VSS_RME_RESTORE_IF_NOT_THERE`

The requester should restore the files of a selected component or component set only if there are no versions of
those files currently on the disk.

Unless alternate location mappings are defined for file restoration, if a version of any file managed by a
selected component or component set is currently on the disk, none of the files managed by the selected
component or component set should be restored.

If a file's alternate location mapping is defined, and a version of the files is present on disk at the
original location, files should be written to the alternate location only if no version of the file exists at
the alternate location.

### `VSS_RME_RESTORE_IF_CAN_REPLACE`

The requester should restore files of a selected component or component set only if the files currently on the disk can be overwritten.

Unless alternate location mappings are defined for file restoration, if there is a version of any file that
cannot be overwritten of the selected component or component set on the disk, none of the files managed by the
component or component set should be restored.

If a file's alternate location mapping is defined, files should be written to the alternate location.

### `VSS_RME_STOP_RESTORE_START`

The requester should perform the restore operation as follows:

1. Send the [PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore) event and wait for all writers to process it.
2. Stop the service.
3. Restore the files to their original locations.
4. Restart the service.
5. Send the [PostRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-postrestore) event and wait for all writers to process it.

The service to be stopped is specified the writer beforehand when it calls the [IVssCreateWriterMetadata::SetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-setrestoremethod) method. The requester can obtain the name of the service by calling the [IVssExamineWriterMetadata::GetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getrestoremethod) method.

Note that if the writer is hosted in the service that is being stopped, that writer will not receive the [PostRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-postrestore) event, because the writer instance ID changes when the service is stopped and restarted.

### `VSS_RME_RESTORE_TO_ALTERNATE_LOCATION`

The requester should restore the files of the selected component or component set to the location specified by the
alternate location mapping specified in the writer component metadata file. (See
[IVssCreateWriterMetadata::AddAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addalternatelocationmapping),
[IVssComponent::GetAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getalternatelocationmapping),
[IVssExamineWriterMetadata::GetAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getalternatelocationmapping),
and [IVssWMFiledesc::GetAlternateLocation](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsswmfiledesc-getalternatelocation).)

This value is not supported for express writers.

### `VSS_RME_RESTORE_AT_REBOOT`

The requester should restore the files of a selected component or component set after the computer is restarted.

The files to be restored should be copied to a temporary location, and the requester should use
[MoveFileEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefileexa) with the
**MOVEFILE_DELAY_UNTIL_REBOOT** flag to complete the restoration of these files to their
proper location after the computer is restarted.

### `VSS_RME_RESTORE_AT_REBOOT_IF_CANNOT_REPLACE`

If possible, the requester should restore the files of the selected component or component set to their correct
location immediately.

If there are versions of any of the files managed by the selected component or component set on the disk that
cannot be overwritten, then all the files managed by the selected component or component set should be restored
after the computer is restarted.

In this case, files to be restored should be copied to a temporary location on disk, and the requester should
use [MoveFileEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefileexa) with the
**MOVEFILE_DELAY_UNTIL_REBOOT** flag to complete the restoration of these files to their
proper location after the computer is restarted.

### `VSS_RME_CUSTOM`

The requester should use a custom restore method to restore the files that are managed by the selected
component or component set.

A custom restore may use file retrieval API functions or protocols that are private to a given writer
application. Such a restore need not use the information in the writer component metadata file. (See
[Custom Backups and Restores](https://learn.microsoft.com/windows/desktop/VSS/custom-backups-and-restores) for more
information.)

This value is not supported for express writers.

### `VSS_RME_RESTORE_STOP_START`

The requester should perform the restore operation as follows:

1. Send the [PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore) event and wait for all writers to process it.
2. Restore the files to their original locations.
3. Send the [PostRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-postrestore) event and wait for all writers to process it.
4. Stop the service.
5. Restart the service.

The service to be stopped is specified by the writer beforehand when it calls the [IVssCreateWriterMetadata::SetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-setrestoremethod) method. The requester can obtain the name of the service by calling the [IVssExamineWriterMetadata::GetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getrestoremethod) method.

## Remarks

A writer sets the restore method in the Writer Metadata Document by calling
[IVssCreateWriterMetadata::SetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-setrestoremethod)
during backup to specify its desired restore method in its metadata.

A requester retrieves a writer's requested restore method by calling
[IVssExamineWriterMetadata::GetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getrestoremethod)
and acts accordingly.

The restore method applies to all files in all components of a given writer.

The restore method may be overridden on a component-by-component basis at restore time if a writer sets a
[VSS_RESTORE_TARGET](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restore_target) value other than
**VSS_RT_ORIGINAL** with
[IVssComponent::SetRestoreTarget](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setrestoretarget).

A restore method of **VSS_RME_RESTORE_TO_ALTERNATE_LOCATION** without an alternate
location mapping defined constitutes a writer error, and the requester should report it as such.

When a restore method requires a check on the status of files currently on disk
(**VSS_RME_RESTORE_IF_NOT_THERE**,
**VSS_RME_RESTORE_IF_CAN_REPLACE**, or
**VSS_RME_RESTORE_AT_REBOOT_IF_CANNOT_REPLACE**), ideally, you should use file I/O
operations to verify that an entire component can be restored before actually proceeding with the restore.

The safest way to do this would be to open exclusively (no-sharing) all the target files with
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) prior to the restore.

In the case of **VSS_RME_RESTORE_IF_NOT_THERE**, a creation disposition flag of
**CREATE_NEW** should also be set.

If the open operations succeed, the restore can proceed and should use the handles returned by
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) to actually write restored data to disk.

If not, an error can be returned—depending on the method—or
alternate location mapping checked and (if it is available) used, or the components files staged for restore at
the next reboot.

This may be a problem for very large components (some of which may have thousands of files), due to system
overhead.

In this case, an available though less reliable option is to do the following:

1. Copy all files currently on disk and to be restored to a temporary cache.
2. Attempt to replace the files currently on disk with the backed-up files (which could be either on disk in a
   second temporary area, or on a backup medium).
3. If any files fail to restore, then terminate the restore operation and copy the original files back from
   their temporary location and proceed with alternate location mapping or restore on reboot operations.

For more information on backup and restore file locations under VSS, see
[Non-Default Backup And Restore
Locations](https://learn.microsoft.com/windows/desktop/VSS/non-default-backup-and-restore-locations).

## See also

[IVssBackupComponents::AddAlternativeLocationMapping](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addalternativelocationmapping)

[IVssComponent::GetAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getalternatelocationmapping)

[IVssCreateWriterMetadata::AddAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addalternatelocationmapping)

[IVssCreateWriterMetadata::SetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-setrestoremethod)

[IVssExamineWriterMetadata::GetAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getalternatelocationmapping)

[IVssExamineWriterMetadata::GetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getrestoremethod)

[IVssWMFiledesc::GetAlternateLocation](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsswmfiledesc-getalternatelocation)

[VSS_WRITERRESTORE_ENUM](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_writerrestore_enum)
# VSS_WRITERRESTORE_ENUM enumeration

## Description

The **VSS_WRITERRESTORE_ENUM** enumeration is used by
a writer to indicate to a requester the conditions under which it will handle events generated during a
restore operation.

## Constants

### `VSS_WRE_UNDEFINED:0`

It is not known whether the writer will perform special operations during the restore operation.

This state indicates a writer error.

### `VSS_WRE_NEVER`

The writer does not require restore events.

### `VSS_WRE_IF_REPLACE_FAILS`

Indicates that the writer always expects to handle a
[PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore)
([CvssWriter::OnPreRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onprerestore)) event, but expects
to handle a [PostRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-postrestore) event
([CvssWriter::OnPostRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostrestore)) only if a restore
fails when implementing either a **VSS_RME_RESTORE_IF_NOT_THERE** or
**VSS_RME_RESTORE_IF_CAN_REPLACE** restore method
([VSS_RESTOREMETHOD_ENUM](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restoremethod_enum)).

### `VSS_WRE_ALWAYS`

The writer always performs special operations during the restore operation.

## Remarks

A writer passes a value of
**VSS_WRITERRESTORE_ENUM** to
[IVssCreateWriterMetadata::SetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-setrestoremethod)
to indicate through its metadata how it interacts with requesters during a restore operation.

A requester retrieves information about a writer's participation by calling
[IVssExamineWriterMetadata::GetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getrestoremethod).

## See also

[IVssCreateWriterMetadata::SetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-setrestoremethod)

[IVssExamineWriterMetadata::GetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getrestoremethod)

[VSS_RESTOREMETHOD_ENUM](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restoremethod_enum)
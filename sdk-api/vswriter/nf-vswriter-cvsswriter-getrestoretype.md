# CVssWriter::GetRestoreType

## Description

The
**GetRestoreType** method returns the type of restore a writer is participating in.

**GetRestoreType** is a protected method implemented by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class.

## Return value

This method returns the type of restore operation a writer is participating in, in terms of values of the
[VSS_RESTORE_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_restore_type) enumeration.

If
**GetRestoreType** is called during a backup operation, the return value is undefined.

## Remarks

This method should be called only during restore operations.

The default restore type is VSS_RTYPE_UNDEFINED. However, writers should treat this restore type as if it were VSS_RTYPE_BY_COPY.

A requester can set the restore type by calling the
[IVssBackupComponents::SetRestoreState](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setrestorestate) method.

A requester can call [IVssBackupComponents::SetRestoreState](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setrestorestate) anytime prior to its generation of a
[PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore) event with the
**IVssBackupComponents::PreRestore** method. Therefore, to obtain the correct restore type, a writer should not call
**GetRestoreType** prior to handling the
**PreRestore** event in
[CVssWriter::OnPreRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onprerestore).

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::OnPreRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onprerestore)

[IVssBackupComponents::PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore)

[IVssBackupComponents::SetRestoreState](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setrestorestate)

[VSS_RESTORE_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_restore_type)
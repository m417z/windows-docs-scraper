# VSS_FILE_RESTORE_STATUS enumeration

## Description

The **VSS_FILE_RESTORE_STATUS** enumeration
defines the set of statuses of a file restore operation performed on the files managed by a
selected component or component set (see
[Working with Selectability and
Logical Paths](https://learn.microsoft.com/windows/desktop/VSS/working-with-selectability-and-logical-paths) for information on selecting components).

## Constants

### `VSS_RS_UNDEFINED:0`

The restore state is undefined.

This value indicates an error, or indicates that a restore operation has not yet started.

This value is not supported for components that are owned by express writers.

### `VSS_RS_NONE`

No files were restored.

This value indicates an error in restoration that did not leave any restored files on disk.

### `VSS_RS_ALL`

All files were restored. This value indicates success and should be set for each component that was
restored successfully.

### `VSS_RS_FAILED`

The restore process failed.

This value indicates an error in restoration that did leave some restored files on disk. This means the
components on disk are now corrupt.

## Remarks

If any files managed by a component or, if it defines a component set, any of its subcomponents cannot be
restored, the value of **VSS_FILE_RESTORE_STATUS**
must indicate an error.

Both the values **VSS_RS_FAILED** and **VSS_RS_NONE** indicate
that a restore operation did not complete successfully:

* **VSS_RS_NONE** indicates a restore failed gracefully: no files from the component
  or its subcomponents were restored to disk.
* **VSS_RS_FAIL** indicates a restore failed gracelessly, leaving some files restored
  to disk and some files unrestored.

Requesters must set a restore status (using
[IVssBackupComponents::SetFileRestoreStatus](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setfilerestorestatus))
for every component (and its component set, if it defines one) explicitly added for restore to the Backup
Components Document (using either
[IVssBackupComponents::SetSelectedForRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setselectedforrestore) or
[IVssBackupComponents::AddRestoreSubcomponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addrestoresubcomponent)).

Writers and requesters can query the status of the restoration of a component or a component set defined by a
selectable component with calls to
[IVssComponent::GetFileRestoreStatus](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getfilerestorestatus). If
this method is called for a component that was not selected, the value returned is undefined.

## See also

[IVssBackupComponents::SetFileRestoreStatus](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setfilerestorestatus)

[IVssComponent::GetFileRestoreStatus](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getfilerestorestatus)
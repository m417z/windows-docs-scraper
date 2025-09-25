# VSS_RESTORE_TARGET enumeration

## Description

The **VSS_RESTORE_TARGET** enumeration is used
by a writer at restore time to indicate how all the files included in a selected component, and all the files in
any component set it defines, are to be restored. (See
[Working with Selectability and
Logical Paths](https://learn.microsoft.com/windows/desktop/VSS/working-with-selectability-and-logical-paths) for information on selecting components.)

Setting a restore target modifies or overrides the restore method set during backup (see
[VSS_RESTOREMETHOD_ENUM](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restoremethod_enum)).

## Constants

### `VSS_RT_UNDEFINED:0`

No target is defined.

This value indicates an error on the part of the writer.

This value is not supported for express writers.

### `VSS_RT_ORIGINAL`

This is the default restore target.

This value indicates that the restoration of the files included in a selected component (or the component set
defined by that component) should proceed according to the original restore method specified at backup time by
a [VSS_RESTOREMETHOD_ENUM](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restoremethod_enum) value.

### `VSS_RT_ALTERNATE`

The files are restored to a location determined from an existing alternate location mapping.

The restore target should be set to **VSS_RT_ALTERNATE** only when alternate location
mappings have been set for all the files managed by a selected component or component set.

This value is not supported for express writers.

### `VSS_RT_DIRECTED`

Use directed targeting by the writer at restore time to restore a file.

Directed targeting allows a writer to control, on a file-by-file basis, how a file is
restored—indicating how much of a file is to be restored and into which files the
backed-up file is to be restored.

This value is not supported for express writers.

### `VSS_RT_ORIGINAL_LOCATION`

The files are restored to the location at which they were at backup time, even if the original
restore method that was specified at backup time was
**VSS_RME_RESTORE_TO_ALTERNATE_LOCATION**.

**Windows Server 2003 and Windows XP:** This value is not supported.

This value is not supported for express writers.

## Remarks

A target of **VSS_RT_UNDEFINED** indicates an error state.

At backup time, writers set the default restore behavior by indicating a restore method
([VSS_RESTOREMETHOD_ENUM](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restoremethod_enum)) set with
[IVssCreateWriterMetadata::SetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-setrestoremethod).

If a writer does not explicitly set the restore target of a component and any component set it defines, by
default it is set to **VSS_RT_ORIGINAL**.

At restore time, a **VSS_RESTORE_TARGET** value other
than **VSS_RT_ORIGINAL** overrides the value of the originally specified restore method
specified by [VSS_RESTOREMETHOD_ENUM](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restoremethod_enum) and set by
[IVssCreateWriterMetadata::SetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-setrestoremethod).

Only writers (using
[IVssComponent::SetRestoreTarget](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setrestoretarget)) can set
a restore target (**VSS_RESTORE_TARGET**) and change how
files are restored overriding the restore method).

Requesters and writers can access the current restore target through
[IVssComponent::GetRestoreTarget](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getrestoretarget).

A restore target of **VSS_RT_ORIGINAL** does not mean that files should be restored to
their original location, but that the originally specified restore method
([VSS_RESTOREMETHOD_ENUM](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restoremethod_enum)) must be
respected. For instance, if a writer set a restore method of
**VSS_RME_RESTORE_TO_ALTERNATE_LOCATION** for a selected component and the restore target
is **VSS_RT_ORIGINAL**, files should be restored to the alternate location defined by the
writer.

(In this example, if a writer has failed to define alternate location mappings, then it is a writer error, and
the requester should report it.)

A restore target of **VSS_RT_ALTERNATE** without an alternate location mapping defined
constitutes a writer error, and the requester should report it as such.

See [Non-Default Backup And Restore
Locations](https://learn.microsoft.com/windows/desktop/VSS/non-default-backup-and-restore-locations) for more information.

## See also

[IVssComponent::GetRestoreTarget](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getrestoretarget)

[IVssComponent::SetRestoreTarget](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setrestoretarget)

[VSS_RESTOREMETHOD_ENUM](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restoremethod_enum)
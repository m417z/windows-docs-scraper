# VSS_RESTORE_TYPE enumeration

## Description

The **VSS_RESTORE_TYPE** enumeration is used by a
requester to indicate the type of restore operation it is about to perform.

## Constants

### `VSS_RTYPE_UNDEFINED:0`

No restore type is defined.
This is the default restore type. However, writers should treat this restore type as if it were VSS_RTYPE_BY_COPY.

This indicates an error on the part of the requester.

### `VSS_RTYPE_BY_COPY`

A requester restores backed-up data to the original volume from a backup
medium.

### `VSS_RTYPE_IMPORT`

A requester does not copy data from a backup medium, but imports a transportable shadow copy and uses this
imported volume for operations such as data mining.

**Windows Server 2003, Standard Edition and Windows Server 2003, Web Edition:** This value is not supported. All editions of Windows Server 2003 with SP1 support this value.

### `VSS_RTYPE_OTHER`

A restore type not currently enumerated. This value indicates an application error.

## Remarks

A requester can optionally set the type of a restore operation using
[IVssBackupComponents::SetRestoreState](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setrestorestate).

A writer can retrieve the type of a restore operation by calling
[CVssWriter::GetRestoreType](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-getrestoretype).

## See also

[CVssWriter::GetRestoreType](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-getrestoretype)

[IVssBackupComponents::SetRestoreState](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setrestorestate)
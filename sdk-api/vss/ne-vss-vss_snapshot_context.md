# VSS_SNAPSHOT_CONTEXT enumeration

## Description

The **_VSS_SNAPSHOT_CONTEXT** enumeration
enables a requester using
[IVssBackupComponents::SetContext](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setcontext) to
specify how a shadow copy is to be created, queried, or deleted and the degree of writer
involvement.

## Constants

### `VSS_CTX_BACKUP:0`

The standard backup context. Specifies an auto-release, nonpersistent shadow copy in which writers are
involved in the creation.

### `VSS_CTX_FILE_SHARE_BACKUP`

Specifies an auto-release, nonpersistent shadow copy created without writer involvement.

### `VSS_CTX_NAS_ROLLBACK`

Specifies a persistent, non-auto-release shadow copy without writer involvement. This context should be
used when there is no need for writer involvement to ensure that files are in a consistent state at the time
of the shadow copy.

Lightweight automated file rollback mechanisms or persistent shadow copies of file shares or data volumes
that are not expected to contain any system-related files or databases might run under this context. For
example, a requester could use this context for creating a shadow copy of a NAS volume hosting documents and
simple user shares. Those types of data do not need writer involvement to create a consistent shadow copy.

### `VSS_CTX_APP_ROLLBACK`

Specifies a persistent, non-auto-release shadow copy with writer involvement. This context is designed
to be used when writers are needed to ensure that files are in a well-defined state prior to shadow copy.

Automated file rollback mechanisms of system volumes and shadow copies to be used in data mining or restore
operations might run under this context. This context is similar to **VSS_CTX_BACKUP**
but allows a requester more control over the persistence of the shadow copy.

### `VSS_CTX_CLIENT_ACCESSIBLE`

Specifies a read-only, [client-accessible shadow copy](https://learn.microsoft.com/windows/win32/vss/vssgloss-c) that supports Shadow Copies for Shared Folders and is created without writer involvement. Only the system provider (the default provider available on the system) can create this type of shadow copy.

Most requesters will want to use the **VSS_CTX_NAS_ROLLBACK** context for persistent, non-auto-release shadow copies without writer involvement.

### `VSS_CTX_CLIENT_ACCESSIBLE_WRITERS`

Specifies a read-only, [client-accessible shadow copy](https://learn.microsoft.com/windows/win32/vss/vssgloss-c) that is created with writer involvement. Only the system provider (the default provider available on the system) can create this type of shadow copy.

Most requesters will want to use the **VSS_CTX_APP_ROLLBACK** context for persistent, non-auto-release shadow copies with writer involvement.

**Windows Server 2003 and Windows XP:** This context is not supported by Windows Server 2003 and Windows XP.

### `VSS_CTX_ALL:0xffffffff`

All types of currently live shadow copies are available for administrative operations, such as shadow copy
queries (see [IVssBackupComponents::Query](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-query)).
**VSS_CTX_ALL** is a valid context for all VSS interfaces except
[IVssBackupComponents::StartSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-startsnapshotset)
and
[IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset).

## Remarks

The data type to be used with values of
**_VSS_SNAPSHOT_CONTEXT** is
**LONG**.

The default context for VSS shadow copies is **VSS_CTX_BACKUP**.

**Windows XP:** The only supported context is the default, **VSS_CTX_BACKUP**. Calling
[IVssBackupComponents::SetContext](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setcontext) will
return **E_NOTIMPL**.

For details on how to use VSS shadow copies contexts, see
[Implementation Details for
Creating Shadow Copies](https://learn.microsoft.com/windows/desktop/VSS/implementation-details-for-creating-shadow-copies).

Shadow copy behavior can be further controlled by using a bitwise OR to combine a supported
[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes) with valid
**_VSS_SNAPSHOT_CONTEXT** values as an argument to the
[IVssBackupComponents::SetContext](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setcontext)
method.

Currently, the only supported modifications are the bitwise OR of a
**_VSS_SNAPSHOT_CONTEXT** value with the
**VSS_VOLSNAP_ATTR_TRANSPORTABLE** and either the
**VSS_VOLSNAP_ATTR_DIFFERENTIAL** or the **VSS_VOLSNAP_ATTR_PLEX**
value of the
[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes)
enumeration.

However, these values cannot be used to modify **VSS_CTX_CLIENT_ACCESSIBLE**
context.

The use of **VSS_VOLSNAP_ATTR_TRANSPORTABLE** is limited to systems running
Windows Server 2008 Enterprise, Windows Server 2008 Datacenter, Windows Server 2003, Enterprise Edition, or Windows Server 2003, Datacenter Edition.

## See also

[IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset)

[IVssBackupComponents::ExposeSnapshot](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-exposesnapshot)

[IVssBackupComponents::SetContext](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setcontext)

[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop)

[VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop)

[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes)
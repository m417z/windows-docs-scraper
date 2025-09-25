# VSS_VOLUME_SNAPSHOT_ATTRIBUTES enumeration

## Description

Allows additional attributes to be specified for a shadow copy. The context of a shadow copy (as
set by the
[IVssBackupComponents::SetContext](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setcontext) method)
may be modified by a bitmask that contains a valid combination of
**_VSS_VOLUME_SNAPSHOT_ATTRIBUTES** and
[_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context) enumeration values.

## Constants

### `VSS_VOLSNAP_ATTR_PERSISTENT:0x1`

The shadow copy is persistent across reboots.

This attribute is automatically set for
[_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context) contexts of
**VSS_CTX_APP_ROLLBACK**, **VSS_CTX_CLIENT_ACCESSIBLE**,
**VSS_CTX_CLIENT_ACCESSIBLE_WRITERS**, and
**VSS_CTX_NAS_ROLLBACK**.

This attribute should not be used explicitly by requesters when setting the context of a shadow copy.

### `VSS_VOLSNAP_ATTR_NO_AUTORECOVERY:0x2`

[Auto-recovery](https://learn.microsoft.com/windows/win32/vss/vssgloss-a) is disabled for the shadow copy.

A requester can modify a shadow copy context with a bitwise OR of this attribute. By doing this, the requester instructs VSS to make the shadow copy read-only immediately after it is created, without allowing writers or other applications to update components in the shadow copy.

Disabling auto-recovery can cause the shadow copy to be in an inconsistent state if any of its components are involved in transactional database operations, such as transactional read and write operations managed by Transactional NTFS (TxF). This is because disabling auto-recovery prevents incomplete transactions from being rolled back.

Disabling auto-recovery also prevents writers from excluding files from the shadow copy. When auto-recovery is disabled, a writer can still call the [IVssCreateWriterMetadataEx::AddExcludeFilesFromSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadataex-addexcludefilesfromsnapshot) method, but the writer's [CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot) method cannot delete the files from the shadow copy.

**Windows Server 2003 and Windows XP:** This value is not supported until Windows Vista.

### `VSS_VOLSNAP_ATTR_CLIENT_ACCESSIBLE:0x4`

The specified shadow copy is a [client-accessible shadow copy](https://learn.microsoft.com/windows/win32/vss/vssgloss-c) that supports Shadow Copies for Shared Folders, and should not be exposed.

This attribute is automatically set for **VSS_CTX_CLIENT_ACCESSIBLE** and **VSS_CTX_CLIENT_ACCESSIBLE_WRITERS**.

This attribute should not be used explicitly by requesters when setting the context of a shadow copy.

### `VSS_VOLSNAP_ATTR_NO_AUTO_RELEASE:0x8`

The shadow copy is not automatically deleted when the shadow copy requester process ends. The shadow copy
can be deleted only by a call to
[IVssBackupComponents::DeleteSnapshots](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-deletesnapshots).

This attribute is automatically set for
[_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context) contexts of
**VSS_CTX_APP_ROLLBACK**, **VSS_CTX_CLIENT_ACCESSIBLE**,
**VSS_CTX_CLIENT_ACCESSIBLE_WRITERS**, and
**VSS_CTX_NAS_ROLLBACK**.

This attribute should not be used explicitly by requesters when setting the context of a shadow copy.

### `VSS_VOLSNAP_ATTR_NO_WRITERS:0x10`

No writers are involved in creating the shadow copy.

This attribute is automatically set for
[_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context) contexts of
**VSS_CTX_NAS_ROLLBACK**, **VSS_CTX_FILE_SHARE_BACKUP**, and
**VSS_CTX_CLIENT_ACCESSIBLE**.

This attribute should not be used explicitly by requesters when setting the context of a shadow copy.

### `VSS_VOLSNAP_ATTR_TRANSPORTABLE:0x20`

The shadow copy is to be transported and therefore should not be surfaced locally.

This attribute can be used explicitly by requesters when setting the context of a shadow copy, if the
provider for shadow copy supports transportable shadow copies.

**Windows Server 2003, Standard Edition, Windows Server 2003, Web Edition and Windows XP:** This attribute is not supported. All editions of Windows Server 2003 with SP1 support this attribute.

See [Importing Transportable
Shadow Copied Volumes](https://learn.microsoft.com/windows/desktop/VSS/importing-transportable-shadow-copied-volumes) for more information.

### `VSS_VOLSNAP_ATTR_NOT_SURFACED:0x40`

The shadow copy is not currently exposed.

Unless the shadow copy is explicitly exposed or mounted, this attribute is set for all shadow copies.

This attribute should not be used explicitly by requesters when setting the context of a shadow copy.

### `VSS_VOLSNAP_ATTR_NOT_TRANSACTED:0x80`

The shadow copy is not transacted.

A requester can modify a shadow copy context with a bitwise OR of this attribute. By doing this, the requester instructs VSS to disable built-in integration between VSS and transaction and resource managers.

Setting this attribute guarantees that the requester will not receive VSS_E_TRANSACTION_FREEZE_TIMEOUT errors. However, it may cause unwanted consequences, such as the loss of transactional integrity or even data loss.

**Windows Server 2003 and Windows XP:** This value is not supported until Windows Vista.

### `VSS_VOLSNAP_ATTR_HARDWARE_ASSISTED:0x10000`

Indicates that a given provider is a hardware provider.

This attribute is automatically set for hardware providers.

This enumeration value cannot be used to manually set the context (using the
[IVssBackupComponents::SetContext](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setcontext)
method) of a shadow copy by a bit mask (or bitwise OR) of this enumeration value and a valid shadow copy
context value from
[_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context).

### `VSS_VOLSNAP_ATTR_DIFFERENTIAL:0x20000`

Indicates that a given provider uses differential data or a copy-on-write mechanism to implement shadow copies.

A requester can modify a shadow copy context with a bitwise OR of this attribute. By doing this, the
requester instructs providers to create a shadow copy using a differential implementation. If no shadow copy
provider installed on the system supports the requested attributes, a VSS_E_VOLUME_NOT_SUPPORTED error will be
returned to
[IVssBackupComponents::AddToSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addtosnapshotset).

### `VSS_VOLSNAP_ATTR_PLEX:0x40000`

Indicates that a given provider uses a PLEX or mirrored split mechanism to implement shadow copies.

A requester can modify a shadow copy context with a bitwise OR of this attribute. By doing this, the
requester instructs the providers to create a shadow copy using a PLEX implementation. If no shadow copy
provider installed on the system supports the requested attributes, a VSS_E_VOLUME_NOT_SUPPORTED error will be
returned to
[IVssBackupComponents::AddToSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addtosnapshotset).

### `VSS_VOLSNAP_ATTR_IMPORTED:0x80000`

The shadow copy of the volume was imported onto this machine using the
[IVssBackupComponents::ImportSnapshots](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-importsnapshots)
method rather than created using the
[IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset)
method.

This attribute is automatically set if a shadow copy is imported.

This attribute should not be used explicitly by requesters when setting the context of a shadow copy.

### `VSS_VOLSNAP_ATTR_EXPOSED_LOCALLY:0x100000`

The shadow copy is locally exposed. If this bit flag and the VSS_VOLSNAP_ATTR_EXPOSED_REMOTELY bit flag are
not set, the shadow copy is hidden.

The attribute is automatically added to a shadow copy context upon calling the
[IVssBackupComponents::ExposeSnapshot](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-exposesnapshot)
method to expose a shadow copy locally.

This attribute should not be used explicitly by requesters when setting the context of a shadow copy.

### `VSS_VOLSNAP_ATTR_EXPOSED_REMOTELY:0x200000`

The shadow copy is remotely exposed. If this bit flag and the VSS_VOLSNAP_ATTR_EXPOSED_LOCALLY bit flag are
not set, the shadow copy is hidden.

The attribute is automatically added to a shadow copy context upon calling the
[IVssBackupComponents::ExposeSnapshot](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-exposesnapshot)
method to expose a shadow copy locally.

This attribute should not be used explicitly by requesters when setting the context of a shadow copy.

### `VSS_VOLSNAP_ATTR_AUTORECOVER:0x400000`

Indicates that the writer will need to [auto-recover](https://learn.microsoft.com/windows/win32/vss/vssgloss-a) the component in [CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot).

This attribute should not be used explicitly by requesters when setting the context of a shadow copy.

### `VSS_VOLSNAP_ATTR_ROLLBACK_RECOVERY:0x800000`

Indicates that the writer will need to [auto-recover](https://learn.microsoft.com/windows/win32/vss/vssgloss-a) the component in [CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot) if the shadow copy is being used for rollback (for data mining, for example).

A requester would set this flag in the shadow copy context to indicate that the shadow copy is being created for a non-backup purpose such as data mining.

### `VSS_VOLSNAP_ATTR_DELAYED_POSTSNAPSHOT:0x1000000`

Reserved for system use.

**Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008.

### `VSS_VOLSNAP_ATTR_TXF_RECOVERY:0x2000000`

Indicates that TxF recovery should be enforced during shadow copy creation.

**Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008.

### `VSS_VOLSNAP_ATTR_FILE_SHARE:0x4000000`

## Remarks

The default context for VSS shadow copies is VSS_CTX_BACKUP.

A requester sets the context for a shadow copy about to be created by passing the member of the
[_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context) enumeration to the
[IVssBackupComponents::SetContext](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setcontext)
method.

Requesters can modify this context by using a bitwise OR of the
[_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context) value with a
supported value from the
**_VSS_VOLUME_SNAPSHOT_ATTRIBUTES**
enumeration as an argument to
[IVssBackupComponents::SetContext](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setcontext).

Unless specifically requested to support a given mechanism, providers are free to use any type of mechanism
to implement a shadow copy. Therefore, in the case where a shadow copy method is not specified, the provider is
free to choose a differential mechanism (**VSS_VOLSNAP_ATTR_DIFFERENTIAL**), a PLEX
mechanism (**VSS_VOLSNAP_ATTR_PLEX**), or any other mechanism to support the shadow
copy.

While a provider can support both mechanisms, they are mutually exclusive for a given shadow copy. Requesters
should not use both **VSS_VOLSNAP_ATTR_DIFFERENTIAL** and
**VSS_VOLSNAP_ATTR_PLEX** to modify a specific shadow copy context.

Currently, **VSS_VOLSNAP_ATTR_DIFFERENTIAL**,
**VSS_VOLSNAP_ATTR_PLEX**, and **VSS_VOLSNAP_ATTR_TRANSPORTABLE**
are the only values of the
**_VSS_VOLUME_SNAPSHOT_ATTRIBUTES**
enumeration that can be used to modify any context.

In addition, it cannot be used to modify a **VSS_CTX_CLIENT_ACCESSIBLE** context.

A requester can obtain information about a specific shadow copy (identified by
[VSS_ID](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types)) by unpacking the
[VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure from the
[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop) structure returned by a call to
[IVssBackupComponents::GetSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getsnapshotproperties).

A requester can also obtain a [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop)
structure for each of multiple shadow copies by calling
[IVssBackupComponents::Query](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-query) and using
[IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject) to iterate the returns.

The shadow copies' context and attributes are found as a bit mask contained in the
**m_lSnapshotAttributes** member of the
[VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure.

## See also

[IVssBackupComponents::DeleteSnapshots](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-deletesnapshots)

[IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset)

[IVssBackupComponents::ExposeSnapshot](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-exposesnapshot)

[IVssBackupComponents::GetSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getsnapshotproperties)

[IVssBackupComponents::ImportSnapshots](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-importsnapshots)

[IVssBackupComponents::SetContext](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setcontext)

[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop)

[VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop)

[_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context)
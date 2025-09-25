# VssFreeSnapshotPropertiesInternal function

## Description

The **VssFreeSnapshotProperties** function is
used to free the contents of a [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop)
structure as part of managing its life cycle. The
**VSS_SNAPSHOT_PROP** structure is typically obtained by
using the
[IVssBackupComponents::GetSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getsnapshotproperties) method or the [IVssSoftwareSnapshotProvider::GetSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsssoftwaresnapshotprovider-getsnapshotproperties) method.

This function can also be used to initialize a
[VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure before use or before
freeing the structure.

**Note** This function is exported as **VssFreeSnapshotPropertiesInternal**, but you should call **VssFreeSnapshotProperties**, not **VssFreeSnapshotPropertiesInternal**.

## Parameters

### `pProp` [in]

Pointer to a valid [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop)
object.

## See also

[IVssBackupComponents::GetSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getsnapshotproperties)

[IVssSoftwareSnapshotProvider::GetSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsssoftwaresnapshotprovider-getsnapshotproperties)

[VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop)
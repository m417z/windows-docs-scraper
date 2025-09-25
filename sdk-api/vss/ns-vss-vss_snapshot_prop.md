# VSS_SNAPSHOT_PROP structure

## Description

The **VSS_SNAPSHOT_PROP** structure contains the
properties of a shadow copy or shadow copy set.

## Members

### `m_SnapshotId`

A [VSS_ID](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types) (GUID) uniquely
identifying the shadow copy identifier.

### `m_SnapshotSetId`

A [VSS_ID](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types) (GUID)
uniquely identifying the shadow copy set containing the shadow copy.

### `m_lSnapshotsCount`

Number of volumes included with the shadow copy in the shadow copy set when it was created. Because it is
possible for applications to release individual shadow copies without releasing the shadow copy set, at any
given time the number of shadow copies in the shadow copy set may be less than
**m_LSnapshotsCount**.

The maximum number of shadow-copied volumes permitted in a shadow copy set is 64.

### `m_pwszSnapshotDeviceObject`

Null-terminated wide character string containing the name of the device object for the shadow copy of the
volume. The device object can be thought of as the root of a shadow copy of a volume. Requesters will use this
device name when accessing files on a shadow-copied volume that it needs to work with.

The device name does not contain a trailing "\".

### `m_pwszOriginalVolumeName`

Null-terminated wide character string containing the name of the volume that had been shadow copied.

### `m_pwszOriginatingMachine`

Null-terminated wide character string containing the name of the machine containing the original
volume.

### `m_pwszServiceMachine`

Null-terminated wide character string containing the name of the machine running the Volume Shadow Copy
Service that created the shadow copy.

### `m_pwszExposedName`

Null-terminated wide character string containing the name of the shadow copy when it is exposed. This is a
drive letter or mounted folder (if the shadow copy is exposed as a local volume), or a share name. Corresponds to
the *wszExpose* parameter of the
[IVssBackupComponents::ExposeSnapshot](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-exposesnapshot)
method.

### `m_pwszExposedPath`

Null-terminated wide character string indicating the portion of the shadow copy of a volume made available
if it is exposed as a share. Corresponds to the *wszPathFromRoot* parameter of the
[IVssBackupComponents::ExposeSnapshot](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-exposesnapshot)
method.

### `m_ProviderId`

A [VSS_ID](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types) (GUID)
uniquely identifying the provider used to create this shadow copy.

### `m_lSnapshotAttributes`

The attributes of the shadow copy expressed as a bit mask (or bitwise OR) of members of the
[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes)
enumeration.

### `m_tsCreationTimestamp`

Time stamp indicating when the shadow copy was created. The exact time is determined by the provider. See
[VSS_TIMESTAMP](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types) for
information about the time-stamp format.

### `m_eStatus`

Current shadow copy creation status. See
[VSS_SNAPSHOT_STATE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_state).

## Remarks

Requesters typically obtain a pointer to a **VSS_SNAPSHOT_PROP** structure by using the [IVssBackupComponents::GetSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getsnapshotproperties) method or the [IVssSoftwareSnapshotProvider::GetSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsssoftwaresnapshotprovider-getsnapshotproperties) method. When this structure is no longer needed, the caller is responsible for freeing it by using the [VssFreeSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-vssfreesnapshotproperties) function.

The shadow copy device object contained in **m_pwszSnapshotDeviceObject** is used to
address files on the shadow copy of the volume. For instance, if the original volume has a file with a path of
"\topleveldir\File.html", then the path to the shadow copy of the file is
"**m_pwszSnapshotDeviceObject**"+"\topleveldir\File.html".

When a shadow copy is exposed as a share, the value of
**m_pwszExposedName** will be the share name. When the shadow copy is exposed as a drive letter or mounted folder, the shadow copy **m_pwszExposedName** is a
drive letter followed by a colon—for example, "X:" or a mounted folder path
(for example, "Y:\MountX").

If a shadow copy is exposed as a drive letter or mounted folder, then (as with mounting
any device) the entire shadow copy starting at its root will be exposed at the mount point. In this case,
**m_pwszExposedPath** will be null.

If the shadow copy is exposed as a share, the value of
**m_pwszExposedPath** will be the path to the portion of the volume that is shared.

## See also

[IVssBackupComponents::ExposeSnapshot](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-exposesnapshot)

[IVssBackupComponents::GetSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getsnapshotproperties)

[IVssSoftwareSnapshotProvider::GetSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsssoftwaresnapshotprovider-getsnapshotproperties)

[VSS_SNAPSHOT_STATE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_state)

[VSS_TIMESTAMP](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types)

[VssFreeSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-vssfreesnapshotproperties)

[_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context)

[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes)
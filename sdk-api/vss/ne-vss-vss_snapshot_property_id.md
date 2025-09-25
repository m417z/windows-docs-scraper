# VSS_SNAPSHOT_PROPERTY_ID enumeration

## Description

Specifies the property to be set for a shadow copy.

## Constants

### `VSS_SPROPID_UNKNOWN:0`

The property is not known.

This value indicates an application error.

### `VSS_SPROPID_SNAPSHOT_ID:0x1`

The shadow copy identifier. For more information, see the **m_SnapshotId** member of the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure.

### `VSS_SPROPID_SNAPSHOT_SET_ID:0x2`

The shadow copy set identifier. For more information, see the **m_SnapshotSetId** member of the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure.

### `VSS_SPROPID_SNAPSHOTS_COUNT:0x3`

The number of volumes included with the shadow copy in the shadow copy set when it was created. For more
information, see the **m_lSnapshotsCount** member of the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure.

### `VSS_SPROPID_SNAPSHOT_DEVICE:0x4`

Null-terminated wide character string that specifies the name of the device object for the shadow copy of the
volume. For more information, see the **m_pwszSnapshotDeviceObject** member of the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure.

### `VSS_SPROPID_ORIGINAL_VOLUME:0x5`

A null-terminated wide character string that specifies the name of the original volume. For more information, see the **m_pwszOriginalVolumeName** member of the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure.

### `VSS_SPROPID_ORIGINATING_MACHINE:0x6`

A null-terminated wide character string that specifies the name of the machine that contains the original
volume. For more information, see the **m_pwszOriginatingMachine** member of the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure.

### `VSS_SPROPID_SERVICE_MACHINE:0x7`

A null-terminated wide character string that specifies the name of the machine that is running the Volume Shadow Copy
Service that created the shadow copy. For more information, see the **m_pwszServiceMachine** member of the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure.

### `VSS_SPROPID_EXPOSED_NAME:0x8`

A null-terminated wide character string that specifies the name of the shadow copy when it is exposed. For more information, see the **m_pwszExposedName** member of the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure.

### `VSS_SPROPID_EXPOSED_PATH:0x9`

A null-terminated wide character string that specifies the portion of the volume that is made available
when the shadow copy is exposed as a file share. For more information, see the **m_pwszExposedPath** member of the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure.

### `VSS_SPROPID_PROVIDER_ID:0xa`

The provider identifier. For more information, see the **m_ProviderId** member of the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure.

### `VSS_SPROPID_SNAPSHOT_ATTRIBUTES:0xb`

A bitmask of [_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes) values that specify the properties of the shadow copy. For more information, see the **m_lSnapshotAttributes** member of the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure.

### `VSS_SPROPID_CREATION_TIMESTAMP:0xc`

A time stamp that specifies when the shadow copy was created. For more information, see the **m_tsCreationTimestamp** member of the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure.

### `VSS_SPROPID_STATUS:0xd`

The status of the current shadow copy creation operation. For more information, see the **m_eStatus** member of the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure.

## See also

[IVssSoftwareSnapshotProvider::SetSnapshotProperty](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsssoftwaresnapshotprovider-setsnapshotproperty)
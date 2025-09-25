# VDS_VOLUME_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of a [volume object](https://learn.microsoft.com/windows/desktop/VDS/volume-object).

## Members

### `id`

The GUID of the volume.

### `type`

A [VDS_VOLUME_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_type) enumeration value that specifies the type of the volume. Volume types are simple, spanned, striped (RAID-0), mirrored, or striped with parity (RAID-5).

### `status`

A [VDS_VOLUME_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_status) enumeration value that specifies the status of the volume.

### `health`

A [VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) enumeration value that specifies the health state of the volume.

### `TransitionState`

A [VDS_TRANSITION_STATE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_transition_state) enumeration value that specifies the transition state of the volume.

### `ullSize`

The size of the volume, in bytes.

### `ulFlags`

A bitmask of [VDS_VOLUME_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_flag) enumeration values that describe the volume.

### `RecommendedFileSystemType`

A [VDS_FILE_SYSTEM_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_file_system_type) enumeration value that specifies the preferred file system for the volume. Must be one of the following: VDS_FST_NTFS, VDS_FST_FAT, VDS_FST_FAT32, VDS_FST_UDF, VDS_FST_CDFS, or VDS_FST_UNKNOWN.

### `pwszName`

The name used to open a handle for the volume with the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function. For example, \\?\GLOBALROOT\Device\HarddiskVolume1.

## Remarks

The [IVdsVolume::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-getproperties) method returns this structure to report the properties of a [volume object](https://learn.microsoft.com/windows/desktop/VDS/volume-object).

When a volume is offline, the **VDS_VF_PERMANENTLY_DISMOUNTED** flag is set in the **ulFlags** member of the **VDS_VOLUME_PROP** structure, and the **VDS_VS_OFFLINE** volume status value is also set in the **status** member of this structure.

## See also

[IVdsVolume::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-getproperties)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_FILE_SYSTEM_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_file_system_type)

[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health)

[VDS_TRANSITION_STATE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_transition_state)

[VDS_VOLUME_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_flag)

[VDS_VOLUME_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop2)

[VDS_VOLUME_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_status)

[VDS_VOLUME_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_type)
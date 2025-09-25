# VDS_VOLUME_PROP2 structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties of a [volume object](https://learn.microsoft.com/windows/desktop/VDS/volume-object). This structure is identical to the [VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop) structure, except that it also includes the volume GUIDs.

## Members

### `id`

The GUID of the volume.

### `type`

A [VDS_VOLUME_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_type) enumeration value that specifies the volume type. Volume types are simple, spanned, striped (RAID-0), mirrored, or striped with parity (RAID-5).

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

### `cbUniqueId`

The length of the byte array that the **pUniqueId** member points to.

### `pwszName`

The name that was used to open a handle for the volume with the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function. For example, \\?\GLOBALROOT\Device\HarddiskVolume1.

### `pUniqueId`

A byte array that contains the unique identifier for the volume.

## Remarks

The [IVdsVolume2::GetProperties2](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume2-getproperties2) method returns this structure to report the properties of a [volume object](https://learn.microsoft.com/windows/desktop/VDS/volume-object).

When a volume is offline, the **VDS_VF_PERMANENTLY_DISMOUNTED** flag is set in the **ulFlags** member of the **VDS_VOLUME_PROP2** structure, and the **VDS_VS_OFFLINE** volume status value is also set in the **status** member of this structure.

For GPT and dynamic volumes, the unique identifier that the **pUniqueId** member points to is globally unique.

For removable media drives, the volume exists and has its own unique identifier even if there is no media in the device. If a volume is formatted on removable media, that volume has its own unique identifier. For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://msdn.microsoft.com/library/ms802377.aspx).

The format of the unique identifier may vary among different types of devices and volumes. For basic volumes on MBR disks, the unique identifier is based on the disk signature and partition offset. Because the disk signature and partition offset are DWORD values, the unique identifier cannot be guaranteed to be globally unique across computers.

If the disk signature changes, the volume's unique identifier also changes. Disk signature changes usually occur as a result of a collision during disk cloning.

Note that a unique identifier is not the same as a volume GUID path. To find the volume GUID paths for a volume, use the [IVdsVolumeMF3::QueryVolumeGuidPathnames](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf3-queryvolumeguidpathnames) method.

## See also

[IVdsVolume2::GetProperties2](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume2-getproperties2)

[MOUNTDEV_UNIQUE_ID](https://msdn.microsoft.com/library/ms810149.aspx)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_FILE_SYSTEM_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_file_system_type)

[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health)

[VDS_TRANSITION_STATE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_transition_state)

[VDS_VOLUME_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_flag)

[VDS_VOLUME_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_status)

[VDS_VOLUME_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_type)
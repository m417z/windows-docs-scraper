# VDS_DISK_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties
of a [disk object](https://learn.microsoft.com/windows/desktop/VDS/disk-object).

## Members

### `id`

The GUID of the disk object.

### `status`

The availability of a physical disk enumerated by
[VDS_DISK_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_disk_status).
If the VDS service cannot open a handle to the disk, it sets this member to **VDS_DS_UNKNOWN**.

**Note** This member can be VDS_DS_ONLINE, even if the status of the containing pack is VDS_PS_OFFLINE.

### `ReserveMode`

This member is reserved for future use.

### `health`

A
[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) enumeration value that specifies the health state of the disk. The following are the valid values for this member.

#### VDS_H_UNKNOWN (0)

#### VDS_H_HEALTHY (1)

#### VDS_H_FAILING (4)

#### VDS_H_FAILED (8)

### `dwDeviceType`

The device type defined in Winioctl.h, which includes the following types among others:

### `dwMediaType`

A media type enumerated by [STORAGE_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_media_type).
Basic and dynamic disks map to the **FixedMedia** enumerator. For more information, see
[STORAGE_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_media_type).

### `ullSize`

The size of the disk in bytes. To determine the maximum volume size for a disk, call
[IVdsDisk3::QueryFreeExtents](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk3-queryfreeextents) and add the sizes of all
free extents.

### `ulBytesPerSector`

The number of bytes in each sector.

### `ulSectorsPerTrack`

The number of sectors in each track.

### `ulTracksPerCylinder`

The number of tracks in each cylinder.

### `ulFlags`

A bitmask of
[VDS_DISK_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_disk_flag) enumeration values that specify various disk attributes.

### `BusType`

The input/output bus types enumerated by
[VDS_STORAGE_BUS_TYPE](https://learn.microsoft.com/windows/desktop/api/vdslun/ne-vdslun-vds_storage_bus_type).

### `PartitionStyle`

A
[VDS_PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_partition_style) enumeration value that specifies the partition type. This member is the
discriminant for the union.

### `dwSignature`

Used if **PartitionStyle** is **VDS_PST_MBR** (1). The signature
for the MBR partition. This value is not guaranteed to be unique.

### `DiskGuid`

Used if **PartitionStyle** is **VDS_PST_GPT** (2). The
GUID for the disk. In addition, each GPT partition has its own GUID. (See [VDS_PARTITION_INFO_GPT](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_info_gpt).)

### `pwszDiskAddress`

The address of a SCSI-like disk in
Port*NNN*Path*NNN*Target*NNN*Lun*NNN*
format, where *NNN* is one or more digits.

SCSI disks, IDE disks, and Fibre Channel disks can have such an address. USB and 1394 disks have different
address formats and are not stored.

This member is optional and can be **NULL** if no value is available. If it is not **NULL**, its length must be greater than or equal to 22 WCHAR and less than or equal to 64 WCHAR, including the required **NULL** terminator. Applications that receive the **VDS_DISK_PROP** structure by calling [IVdsDisk::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-getproperties) must check whether this member is **NULL**.

### `pwszName`

The name used to open a handle to an object created using the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)
function. For example: `\\?\PhysicalDrive2`

### `pwszFriendlyName`

The name returned by the Plug and Play Manager. This name is maintained in the Windows registry by the
Plug and Play Manager, for example: "SEAGATE ST34573N SCSI Disk Device".

### `pwszAdaptorName`

The name of the adapter to which this disk is attached. The Plug and Play Manager returns the name, which
is maintained in the Windows registry, for example: "Adaptec AHA-2940U2W - Ultra2 SCSI".

### `pwszDevicePath`

The string returned by the Plug and Play Manager. The Plug and Play Manager uses the device path to
uniquely identify a device on a computer. For more information, see
[**SP_DEVICE_INTERFACE_DETAIL_DATA_W**](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_detail_data_w).

## Remarks

The [IVdsDisk::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-getproperties) method returns
the value of this structure to report the properties of a [disk object](https://learn.microsoft.com/windows/desktop/VDS/disk-object).

## See also

[IVdsDisk::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-getproperties)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_DISK_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_disk_flag)

[VDS_DISK_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop2)

[VDS_DISK_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_disk_status)

[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health)

[VDS_PARTITION_INFO_GPT](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_info_gpt)

[VDS_PARTITION_INFO_MBR](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_info_mbr)

[VDS_PARTITION_STYLE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_partition_style)

[VDS_STORAGE_BUS_TYPE](https://learn.microsoft.com/windows/desktop/api/vdslun/ne-vdslun-vds_storage_bus_type)
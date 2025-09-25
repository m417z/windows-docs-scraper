# VDS_DISK_OFFLINE_REASON enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of reasons for a disk to be offline.

## Constants

### `VDSDiskOfflineReasonNone:0`

The reason is unknown.

### `VDSDiskOfflineReasonPolicy:1`

The disk is offline because of the current [SAN policy](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_san_policy).

### `VDSDiskOfflineReasonRedundantPath:2`

The disk is offline because it has a path that is the same as that of another device. This value is used when multipathing is physically enabled, but the MPIO software is not installed or is not functioning properly. (When the MPIO software is functioning properly, it exposes only one disk device.)

### `VDSDiskOfflineReasonSnapshot:3`

The disk is offline because it contains a volume shadow copy volume. In this case, the disk is a clone of another disk that is online.

### `VDSDiskOfflineReasonCollision:4`

If the disk is an MBR disk, it is offline because its disk signature is the same as that of another disk that is online. The disk signature is found in the **dwSignature** member of the [VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop) and [VDS_DISK_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop2) structures and in the **Signature** member of the [DRIVE_LAYOUT_INFORMATION_MBR](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-drive_layout_information_mbr) structure.

If it is a GPT disk, it is offline for one of the following reasons:

* Its disk identifier is the same as that of another disk that is offline. The disk identifier is found in the **DiskGuid** member of the [VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop) and [VDS_DISK_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop2) structures and in the **DiskId** member of the [DRIVE_LAYOUT_INFORMATION_GPT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-drive_layout_information_gpt) structure.
* One of the partitions has the same partition GUID as another partition on the same disk.

### `VDSDiskOfflineReasonResourceExhaustion:5`

### `VDSDiskOfflineReasonWriteFailure:6`

### `VDSDiskOfflineReasonDIScan:7`

### `VDSDiskOfflineReasonLostDataPersistence:8`

## See also

[VDS_DISK_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop2)
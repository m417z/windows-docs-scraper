# VDS_INPUT_DISK structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the details of an input disk.

## Members

### `diskId`

The GUID of the disk. This field is required.

### `ullSize`

Disk size in bytes. This field is required. The provider policy determines the offset, length, and number of disk extents allocated for an input disk.

### `plexId`

When extending a volume, the GUID for the plex to which the disk belongs. VDS ignores this member when creating a volume or repairing a RAID-5 volume.

**Note** Callers can extend a volume only by extending all members of all plexes in the same operation.

### `memberIdx`

The member index of the disk to which the extent belongs. Either specify a **memberIdx** for all disks or specify it for none. VDS uses disks with the same **memberIdx** in the order they appear in the array. For example, the first disk in the array is always used first.

**Note** Do not specify **memberIdx** when repairing a RAID-5 volume.

## Remarks

A disk cannot contribute more than one plex to the same volume; however, a disk can contribute to multiple volumes.

Callers can specify a member index for all disks or use the default member index for all disks. Never mix specified and default member indexes for the disks included in the same array. Avoid using a default member index in conjunction with the [IVdsVolume::Extend](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-extend) method, unless the volume has only one plex with only one member.

The [IVdsPack::CreateVolume](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-createvolume), [IVdsVolume::Extend](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-extend), and [IVdsVolumePlex::Repair](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumeplex-repair) methods pass this structure as an argument to specify disk input information.

## See also

[IVdsPack::CreateVolume](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-createvolume)

[IVdsVolume::Extend](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-extend)

[IVdsVolumePlex::Repair](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumeplex-repair)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)
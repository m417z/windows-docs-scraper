# VDS_DRIVE_EXTENT structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the
properties of a drive extent.

## Members

### `id`

The **VDS_OBJECT_ID** of the drive.

### `LunId`

The **VDS_OBJECT_ID** of the LUN that is associated with the drive extent.

### `ullSize`

The size of the extent, in bytes.

### `bUsed`

If **TRUE**, the extent is allocated to a LUN plex. If **FALSE**, the extent is unallocated.

## Remarks

The [IVdsDrive::QueryExtents](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsdrive-queryextents)
method returns this structure to report the properties of a drive extent. It is also returned by the
[IVdsLunPlex::QueryExtents](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunplex-queryextents) method to report
the details of a drive extent that is allocated to a plex.

A disk extent is a contiguous set of blocks on a single disk or LUN handled by a software provider. A drive
extent is not required to be a contiguous set of blocks.

## See also

[Drive Object](https://learn.microsoft.com/windows/desktop/VDS/drive-object)

[IVdsDrive::QueryExtents](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsdrive-queryextents)

[IVdsLunPlex::QueryExtents](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunplex-queryextents)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)
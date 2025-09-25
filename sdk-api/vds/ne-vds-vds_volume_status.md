# VDS_VOLUME_STATUS enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of object status values for a volume.

## Constants

### `VDS_VS_UNKNOWN:0`

The status of the volume is unknown. This value does not apply to dynamic volumes.

### `VDS_VS_ONLINE:1`

The volume is available.

### `VDS_VS_NO_MEDIA:3`

The volume is removable media, such as a CD-ROM.

### `VDS_VS_FAILED:5`

The volume is unavailable.

### `VDS_VS_OFFLINE:4`

The volume is offline.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported. If the volume is offline, the **VDS_VF_PERMANENTLY_DISMOUNTED** flag is set in the **ulFlags** member of the [VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop) or [VDS_VOLUME_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop2) structure.

## Remarks

When the [IVdsPack::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-getproperties) method returns a [VDS_PACK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_pack_prop) structure whose **status** member is VDS_PS_OFFLINE, VDS sets the status for all the volumes in the pack to VDS_VS_FAILED. VDS sets the status for specific volume types to VDS_VS_FAILED under the following conditions:

* For simple, spanned, and striped volumes—whenever a disk is missing.
* For mirrored volumes—when any disk, except the last disk, is missing or has write errors that the plex transitions to a detached condition. Likewise, if it is the last (non-stale) plex and the disk is missing.
* For stripe with parity (RAID-5)—when the second disk is missing, or if one column becomes detached (because the disk is missing or the column has write errors), and a second disk is missing.

The [VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop) structure includes a **VDS_VOLUME_STATUS** value as a member to indicate the status of a volume.

**Note** Additional constants might be added to the **VDS_VOLUME_STATUS** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_VOLUME_STATUS** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_PACK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_pack_prop)

[VDS_PACK_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_pack_status)

[VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop)
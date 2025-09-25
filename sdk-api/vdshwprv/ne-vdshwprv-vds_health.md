# VDS_HEALTH enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of
health state values for a VDS object.

## Constants

### `VDS_H_UNKNOWN:0`

The health of the object cannot be determined.

### `VDS_H_HEALTHY:1`

The object indicates online status. This health state value means that the object is fully operational and is operating properly, but it does not imply that the object is available for use. For example, if the object is a disk, the disk is not missing, log and
configuration files are synchronized, and the disk is free of I/O errors. If the object is a LUN or
volume, all plexes (mirrored, simple, spanned, and striped) and columns (RAID-5) are available and free of I/O errors. The status value associated with this health state must not be FAILED, UNKNOWN, or MISSING.

### `VDS_H_REBUILDING:2`

Either a mirrored LUN or volume is resynching all plexes, or a striped with parity (RAID-5) plex is
regenerating the parity.

### `VDS_H_STALE:3`

The object configuration is stale. The status value must not be FAILED or UNKNOWN.

### `VDS_H_FAILING:4`

The object is failing, but still working. For example, a LUN or volume with failing health might be
producing occasional input/output errors from which it is still able to recover. The status value must not be FAILED or UNKNOWN.

### `VDS_H_FAILING_REDUNDANCY:5`

One or more plexes have errors, but the object is working and all plexes are online. This value is valid only for volumes and LUNs.

### `VDS_H_FAILED_REDUNDANCY:6`

One or more plexes have failed, but at least one plex is working. This value is valid only for volumes and LUNs.

### `VDS_H_FAILED_REDUNDANCY_FAILING:7`

The last working plex is failing. This value is valid only for volumes and LUNs.

### `VDS_H_FAILED:8`

The object has failed. Any object with a failed health status also has a failed object status. Therefore, the status value must be FAILED.

### `VDS_H_REPLACED:9`

This value is reserved. Do not use it.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_H_PENDING_FAILURE:10`

The object is not failing, but it is expected to fail according to analysis done on the object's attributes. For example, a disk may be set to VDS_H_PENDING_FAILURE based on S.M.A.R.T. data.

The status value must not be FAILED or UNKNOWN.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_H_DEGRADED:11`

The object has not completely failed but is experiencing failures.

If the object is a subsystem object, the firmware may be reporting errors, or the drive, controller, port, or path sub-object may have failed or be failing.

If the object is a controller object, the firmware may be reporting errors, or the port or path sub-object may have failed or be failing.

If the object is a storage pool object, one or more drives may have failed or be failing.

The status value must not be UNKNOWN.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

## Remarks

Health enumeration values apply to the VDS objects as shown in the following table. Y indicates that the value
applies to the object, and N indicates that the value does not apply to the object. A pack object does not
report health status.

| Health enumeration value | Disk | Subsystem | Controller | Drive | LUN | LUN plex | Storage pool | Volume | Volume plex |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| **VDS_H_UNKNOWN** | Y | Y | Y | Y | Y | Y | Y | Y | Y |
| **VDS_H_HEALTHY** | Y | Y | Y | Y | Y | Y | Y | Y | Y |
| **VDS_H_REBUILDING** | N | N | N | N | Y | Y | N | Y | Y |
| **VDS_H_STALE** | N | N | N | N | N | N | N | Y | Y |
| **VDS_H_FAILING** | Y | N | N | N | Y | Y | N | Y | Y |
| **VDS_H_FAILING_REDUNDANCY** | N | N | N | N | Y | Y | N | Y | Y |
| **VDS_H_FAILED_REDUNDANCY** | N | N | N | N | Y | Y | N | Y | Y |
| **VDS_H_FAILED_REDUNDANCY_FAILING** | N | N | N | N | Y | Y | N | Y | Y |
| **VDS_H_FAILED** | Y | Y | Y | Y | Y | Y | N | Y | Y |
| **VDS_H_REPLACED** | N | N | Y | Y | N | N | N | N | N |
| **VDS_H_PENDING_FAILURE** | N | N | N | Y | N | N | N | N | N |
| **VDS_H_DEGRADED** | N | Y | Y | N | N | N | Y | N | N |

The property structure for each object listed in the table includes the value of the
**VDS_HEALTH** enumeration as a member.

**Note** Additional constants might be added to the **VDS_HEALTH** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_HEALTH** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_CONTROLLER_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_controller_prop)

[VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop)

[VDS_DISK_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop2)

[VDS_DRIVE_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_prop)

[VDS_DRIVE_PROP2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_prop2)

[VDS_LUN_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_plex_prop)

[VDS_LUN_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_prop)

[VDS_STORAGE_POOL_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_storage_pool_prop)

[VDS_SUB_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop)

[VDS_SUB_SYSTEM_PROP2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop2)

[VDS_VOLUME_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_plex_prop)

[VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop)

[VDS_VOLUME_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop2)
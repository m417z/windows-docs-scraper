# VDS_PACK_STATUS enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of object status values for a pack.

## Constants

### `VDS_PS_UNKNOWN:0`

This value is reserved.

### `VDS_PS_ONLINE:1`

The pack is available.

### `VDS_PS_OFFLINE:4`

The pack is unavailable; the disks in the pack are not accessible.

## Remarks

The [VDS_PACK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_pack_prop) structure includes a **VDS_PACK_STATUS** value as a member to indicate the current status of a pack.

**Note** Additional constants might be added to the **VDS_PACK_STATUS** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_PACK_STATUS** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_PACK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_pack_prop)
# VDS_RAID_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set enumeration values that can be used to specify the underlying RAID type of a [storage pool](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object). These values are used in the **raidType** member of the [VDS_POOL_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_pool_attributes) structure.

## Constants

### `VDS_RT_UNKNOWN:0`

The RAID level is unknown.

### `VDS_RT_RAID0:10`

RAID level 0.

### `VDS_RT_RAID1:11`

RAID level 1.

### `VDS_RT_RAID2:12`

RAID level 2.

### `VDS_RT_RAID3:13`

RAID level 3.

### `VDS_RT_RAID4:14`

RAID level 4.

### `VDS_RT_RAID5:15`

RAID level 5.

### `VDS_RT_RAID6:16`

RAID level 6.

### `VDS_RT_RAID01:17`

RAID level 0+1.

### `VDS_RT_RAID03:18`

RAID level 0+3.

### `VDS_RT_RAID05:19`

RAID level 0+5.

### `VDS_RT_RAID10:20`

RAID level 1+0.

### `VDS_RT_RAID15:21`

RAID level 1+5.

### `VDS_RT_RAID30:22`

RAID level 3+0.

### `VDS_RT_RAID50:23`

RAID level 5+0.

### `VDS_RT_RAID51:24`

RAID level 5+1.

### `VDS_RT_RAID53:25`

RAID level 5+3.

### `VDS_RT_RAID60:26`

RAID level 6+0.

### `VDS_RT_RAID61:27`

RAID level 6+1.

## Remarks

A subsystem uses a **VDS_RAID_TYPE** enumeration value to specify the underlying RAID type of a storage pool.

A storage pool does not necessarily have a single underlying RAID type. For example,

The underlying RAID type of of the storage pool is different from the RAID type of a LUN that can be created from the storage pool.

**Note** Additional constants might be added to the **VDS_RAID_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_RAID_TYPE** enumeration constant.

## See also

[VDS_POOL_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_pool_attributes)
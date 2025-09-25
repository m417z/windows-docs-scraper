# VDS_PACK_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid flags for a pack object.

## Constants

### `VDS_PKF_FOREIGN:0x1`

If set, an external pack is eligible for online status.

### `VDS_PKF_NOQUORUM:0x2`

If set, a dynamic pack lacks the required quorum. A quorum is the minimum number of disks in a dynamic pack (n/2 + 1) required to enable online status. This flag prevents the caller from granting online status to the same pack on multiple computers.

### `VDS_PKF_POLICY:0x4`

If set, the pack policy prevents online eligibility. This flag applies exclusively to packs managed by the Windows Server 2003 version of VDS, which allows only one pack at a time to maintain online status.

### `VDS_PKF_CORRUPTED:0x8`

If set, a pack contains a disk with a corrupted database.

### `VDS_PKF_ONLINE_ERROR:0x10`

If set, a pack with sufficient disk quorum failed to achieve online status due to an error.

## Remarks

Pack flags apply to packs managed by the dynamic provider only. The provider sets these flags on offline packs to report the reason for the offline status.

This enumeration provides the values for the *ulFlags* member of the [VDS_PACK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_pack_prop) structure.

**Note** Additional constants might be added to the **VDS_PACK_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_PACK_FLAG** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_PACK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_pack_prop)
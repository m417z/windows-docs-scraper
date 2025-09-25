# VDS_INTERCONNECT_ADDRESS_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of the valid address types of a physical interconnect.

## Constants

### `VDS_IA_UNKNOWN:0`

This value is reserved.

### `VDS_IA_FCFS:1`

The address type is FCFS.

### `VDS_IA_FCPH:2`

The address type is FCPH.

### `VDS_IA_FCPH3:3`

The address type is FCPH3.

### `VDS_IA_MAC:4`

The address type is MAC.

### `VDS_IA_SCSI:5`

The address type is SCSI.

## Remarks

The [VDS_INTERCONNECT](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_interconnect) structure includes a **VDS_INTERCONNECT_ADDRESS_TYPE** value as a member to indicate an interconnect address type.

**Note** Additional constants might be added to the **VDS_INTERCONNECT_ADDRESS_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_INTERCONNECT_ADDRESS_TYPE** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_INTERCONNECT](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_interconnect)
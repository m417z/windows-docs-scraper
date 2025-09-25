# VDS_INTERCONNECT structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the address
data of a physical interconnect.

## Members

### `m_addressType`

The interconnect address type enumerated by
[VDS_INTERCONNECT_ADDRESS_TYPE](https://learn.microsoft.com/windows/desktop/api/vdslun/ne-vdslun-vds_interconnect_address_type).

### `m_cbPort`

The size of the interconnect address data for the LUN port (**m_pbPort**), in bytes.

### `m_pbPort`

Pointer to the interconnect address data for the LUN port.

### `m_cbAddress`

The size of the interconnect address data for the LUN (**m_pbAddress**), in bytes.

### `m_pbAddress`

Pointer to the interconnect address data for the LUN.

## Remarks

The [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information) structure includes this
structure as a member to specify an interconnect by which a LUN can be accessed.

## See also

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_INTERCONNECT_ADDRESS_TYPE](https://learn.microsoft.com/windows/desktop/api/vdslun/ne-vdslun-vds_interconnect_address_type)

[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information)
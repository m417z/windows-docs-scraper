# VDS_HBAPORT_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the
properties of an HBA port.

## Members

### `id`

The GUID assigned to the HBA port. This ID is used by the VDS service only; hardware providers should
ignore this field.

### `wwnNode`

The node WWN of the HBA port.

### `wwnPort`

The port WWN of the HBA port.

### `type`

The type of the HBA port enumerated by
[VDS_HBAPORT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_hbaport_type).

### `status`

The status of the HBA port enumerated by
[VDS_HBAPORT_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_hbaport_status).

### `ulPortSpeed`

The speed of the HBA port enumerated by
[VDS_HBAPORT_SPEED_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_hbaport_speed_flag).

### `ulSupportedPortSpeed`

The set of supported speeds of the HBA port, one bit set for each of the supported speeds enumerated by
[VDS_HBAPORT_SPEED_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_hbaport_speed_flag).

## See also

[VDS_HBAPORT_SPEED_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_hbaport_speed_flag)

[VDS_HBAPORT_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_hbaport_status)

[VDS_HBAPORT_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_hbaport_type)

[VDS_WWN](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_wwn)
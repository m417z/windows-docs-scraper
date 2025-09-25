# VDS_PORT_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the properties
of a port on a controller object.

## Members

### `id`

The **VDS_OBJECT_ID** assigned to the port.

### `pwszFriendlyName`

The name of the port; a zero-terminated, human-readable string.

### `pwszIdentification`

The port identifier or address, typically a world wide name (WWN); a zero-terminated, human-readable
string.

For Fibre Channel networks, this member should be the WWN for the port, formatted as a hexadecimal string (16 characters long), most significant byte first. For example, a WWN address of 01:23:45:67:89:AB:CD:EF should be represented as "0123456789ABCDEF".

### `status`

The status of the port enumerated by
[VDS_PORT_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_port_status).

## Remarks

The
[IVdsController::GetPortProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdscontroller-getportproperties)
method returns this structure to report the property details of a port on a controller object.

## See also

[IVdsController::GetPortProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdscontroller-getportproperties)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_PORT_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_port_status)
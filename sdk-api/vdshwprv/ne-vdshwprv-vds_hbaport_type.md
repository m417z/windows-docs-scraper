# VDS_HBAPORT_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the
set of valid types for an HBA port. These types correspond to the HBA_PORTTYPE values in the HBA API.

## Constants

### `VDS_HPT_UNKNOWN:1`

The port type is unknown.

HBA_PORTTYPE_UNKNOWN

### `VDS_HPT_OTHER:2`

The port type is another (undefined) type.

HBA_PORTTYPE_OTHER

### `VDS_HPT_NOTPRESENT:3`

The port type is not present.

HBA_PORTTYPE_NOTPRESENT

### `VDS_HPT_NPORT:5`

The port type is a fabric.

HBA_PORTTYPE_NPORT

### `VDS_HPT_NLPORT:6`

The port type is a public loop.

HBA_PORTTYPE_NLPORT

### `VDS_HPT_FLPORT:7`

The port type is a fabric on a loop.

HBA_PORTTYPE_FLPORT

### `VDS_HPT_FPORT:8`

The port type is a fabric port.

HBA_PORTTYPE_FPORT

### `VDS_HPT_EPORT:9`

The port type is a fabric expansion port.

### `VDS_HPT_GPORT:10`

The port type is a generic fabric port.

### `VDS_HPT_LPORT:20`

The port type is a private loop.

HBA_PORTTYPE_LPORT

### `VDS_HPT_PTP:21`

The port type is point-to-point.

HBA_PORTTYPE_PTP

## Remarks

**Note** Additional constants might be added to the **VDS_HBAPORT_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_HBAPORT_TYPE** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)
# VDS_IPADDRESS_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid types for an IP address. These values are used in the
**type** member of the
[VDS_IPADDRESS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_ipaddress) structure.

## Constants

### `VDS_IPT_TEXT:0`

The address is a text address that is either a DNS address, an IPv4 dotted address, or an IPv6 hex
address.

### `VDS_IPT_IPV4:1`

The address is an IPv4 address in binary format.

### `VDS_IPT_IPV6:2`

The address is an IPv6 address in binary format.

### `VDS_IPT_EMPTY:3`

The address is empty.

## Remarks

**Note** Additional constants might be added to the **VDS_IPADDRESS_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_IPADDRESS_TYPE** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_IPADDRESS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_ipaddress)
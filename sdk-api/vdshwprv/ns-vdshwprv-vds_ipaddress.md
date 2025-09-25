# VDS_IPADDRESS structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines an IP
address and port.

## Members

### `type`

The type of address as enumerated by
[VDS_IPADDRESS_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_ipaddress_type).

### `ipv4Address`

If the **type** member is **VDS_IPT_IPV4**, then this contains
the binary IPv4 address in network byte order. The field 3 byte value is contained in bits 0 through 7. The field 2 byte value is
contained in bits 8 through 15. The field 1 byte value is contained in bits 16 through 23. The field 0 byte
value is contained in bits 24 through 31.

### `ipv6Address`

If the **type** member is **VDS_IPT_IPV6**, then this contains
the binary IPv6 address in network byte order.

### `ulIpv6FlowInfo`

If the **type** member is **VDS_IPT_IPV6**, then this contains
the flow information as defined in version 6 of the IP protocol.

### `ulIpv6ScopeId`

If the **type** member is **VDS_IPT_IPV6**, then this contains
the scope ID as defined in version 6 of the IP protocol.

### `wszTextAddress`

If the **type** member is **VDS_IPT_TEXT**, then this contains
the text address, either a DNS address or dotted address, in host byte order.

### `ulPort`

The TCP port number.

## See also

[IVdsIscsiPortal::GetIpsecSecurity](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsiportal-getipsecsecurity)

[IVdsIscsiPortal::SetIpsecSecurity](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsiportal-setipsecsecurity)

[IVdsIscsiPortal::SetIpsecTunnelAddress](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsiportal-setipsectunneladdress)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_IPADDRESS_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_ipaddress_type)

[VDS_ISCSI_PORTAL_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_iscsi_portal_prop)

[VDS_PATH_INFO](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_path_info)
# _ISCSI_IP_Address structure

## Description

The ISCSI_IP_Address structure defines an IP address.

## Members

### `Type`

A [ISCSIIPADDRESSTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ne-iscsidef-iscsiipaddresstype) value that indicates the type of IP address.

### `IpV4Address`

If **Type** = **ISCSI_IP_ADDRESS_IPV4**, the binary version 4 IP address. Otherwise, **IpV4Address** is not defined.

### `IpV6Address`

If **Type** = **ISCSI_IP_ADDRESS_IPV6**, the binary version 6 IP address. Otherwise, **IpV6Address** is not defined.

### `IpV6FlowInfo`

If **Type** = **ISCSI_IP_ADDRESS_IPV6**, the flow information for this IP address, as defined in version 6 of the IP protocol. Otherwise, **IpV6FlowInfo** is not defined.

### `IpV6ScopeId`

If **Type** = **ISCSI_IP_ADDRESS_IPV6**, the scope ID of this IP address, as defined in version 6 of the IP protocol,. Otherwise, **IpV6ScopeId** is not defined.

### `TextAddress`

If **Type** = **ISCSI_IP_ADDRESS_TEXT**, the DNS or dotted decimal text address. Otherwise, **TextAddress** is not defined.

## See also

[ISCSIIPADDRESSTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ne-iscsidef-iscsiipaddresstype)

[ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address)
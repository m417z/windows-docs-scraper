# IPV6_ADAPTER_BINDING_INFO structure

## Description

The
**IPV6_ADAPTER_BINDING_INFO** structure contains IPv6-specific information for a particular network adapter.

## Members

### `AddressCount`

The number of IPv6 addresses associated with this adapter.

### `RemoteAddress`

This member is for WAN interfaces. An [in6_addr](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85)) structure that contains the address of the machine at the other end of a dial-up link.

### `Mtu`

Reserved for future use.

### `Speed`

Reserved for future use.

### `Address`

Pointer to an array of
[IPV6_LOCAL_BINDING](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-ipv6_local_binding) structures. The array contains a structure for each of the IPv6 addresses associated with this adapter.

## Remarks

Since an adapter can have more than one IP address, the
**IPV6_ADAPTER_BINDING_INFO** structure maintains an array of
[IPV6_LOCAL_BINDING](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-ipv6_local_binding) structures.

## See also

[IPV6_LOCAL_BINDING](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-ipv6_local_binding)

[IP_ADAPTER_BINDING_INFO](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-ip_adapter_binding_info)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)
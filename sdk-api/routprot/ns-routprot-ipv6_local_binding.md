# IPV6_LOCAL_BINDING structure

## Description

The
**IPV6_LOCAL_BINDING** structure contains IPv6 address information for an adapter.

## Members

### `Address`

An [in6_addr](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85)) structure that specifies an IPv6 address for the adapter.

### `PrefixLength`

The length, in bits, of the address prefix.

## Remarks

Since an adapter can have more than one IP address, the
[IPV6_ADAPTER_BINDING_INFO](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-ipv6_adapter_binding_info) structure maintains an array of
**IPV6_LOCAL_BINDING** structures.

## See also

[IPV6_ADAPTER_BINDING_INFO](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-ipv6_adapter_binding_info)

[IP_LOCAL_BINDING](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-ip_local_binding)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)
# IP_ADAPTER_BINDING_INFO structure

## Description

The
**IP_ADAPTER_BINDING_INFO** structure contains IP-specific information for a particular network adapter.

## Members

### `AddressCount`

The number of IP addresses associated with this adapter.

### `RemoteAddress`

This member is for WAN interfaces. It contains the address of the machine at the other end of a dial-up link.

### `Mtu`

Reserved for future use.

### `Speed`

Reserved for future use.

### `Address`

Pointer to an array of
[IP_LOCAL_BINDING](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-ip_local_binding) structures. The array contains a structure for each of the IP addresses associated with this adapter.

## Remarks

Since an adapter can have more than one IP address, the
**IP_ADAPTER_BINDING_INFO** structure maintains an array of
[IP_LOCAL_BINDING](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-ip_local_binding) structures.

## See also

[IP_LOCAL_BINDING](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-ip_local_binding)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)
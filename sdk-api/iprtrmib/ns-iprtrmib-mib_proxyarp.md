# MIB_PROXYARP structure

## Description

The
**MIB_PROXYARP** structure stores information for a Proxy Address Resolution Protocol (PARP) entry.

## Members

### `dwAddress`

The IPv4 address for which to act as a proxy.

### `dwMask`

The subnet mask for the IPv4 address specified by the **dwAddress** member.

### `dwIfIndex`

The index of the interface on which to act as a proxy for the address specified by the **dwAddress** member.

## See also

[CreateProxyArpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createproxyarpentry)

[DeleteProxyArpEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteproxyarpentry)
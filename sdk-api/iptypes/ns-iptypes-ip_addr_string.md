# IP_ADDR_STRING structure

## Description

The
**IP_ADDR_STRING** structure represents a node in a linked-list of IPv4 addresses.

## Members

### `Next`

A pointer to the next
**IP_ADDR_STRING** structure in the list.

### `IpAddress`

A value that specifies a structure type with a single member, **String**. The **String** member is a **char** array of size 16. This array holds an IPv4 address in dotted decimal notation.

### `IpMask`

A value that specifies a structure type with a single member, **String**. The **String** member is a **char** array of size 16. This array holds the IPv4 subnet mask in dotted decimal notation.

### `Context`

A network table entry (NTE). This value corresponds to the *NTEContext* parameters in the
[AddIPAddress](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-addipaddress) and
[DeleteIPAddress](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipaddress) functions.

## See also

[AddIPAddress](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-addipaddress)

[DeleteIPAddress](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipaddress)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP Helper Structures](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-structures)

[IP_ADAPTER_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_info)

**IP_ADDRESS_STRING**
# IP_ADAPTER_DNS_SUFFIX structure

## Description

The
**IP_ADAPTER_DNS_SUFFIX** structure stores a DNS suffix in a linked list of DNS suffixes for a particular adapter.

## Members

### `Next`

A pointer to the next DNS suffix in the linked list.

### `String`

The DNS suffix for this DNS suffix entry.

## Remarks

The [IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh) structure is retrieved by the [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function. The **FirstDnsSuffix** member of the **IP_ADAPTER_ADDRESSES** structure is a pointer to a linked list of **IP_ADAPTER_DNS_SUFFIX** structures.

## See also

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP Helper Structures](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-structures)

[IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh)
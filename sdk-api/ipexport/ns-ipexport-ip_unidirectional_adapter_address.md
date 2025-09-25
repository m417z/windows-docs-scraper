# IP_UNIDIRECTIONAL_ADAPTER_ADDRESS structure

## Description

The
**IP_UNIDIRECTIONAL_ADAPTER_ADDRESS** structure stores the IPv4 addresses associated with a unidirectional adapter.

## Members

### `NumAdapters`

The number of IPv4 addresses pointed to by the **Address** member.

### `Address`

An array of variables of type [IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr). Each element of the array specifies an IPv4 address associated with this unidirectional adapter.

## Remarks

The **IP_UNIDIRECTIONAL_ADAPTER_ADDRESS** structure is retrieved by the [GetUnidirectionalAdapterInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getunidirectionaladapterinfo) function. A unidirectional adapter is an adapter that can receive
IPv4 datagrams, but can't transmit them.

## See also

[GetUnidirectionalAdapterInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getunidirectionaladapterinfo)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP Helper Structures](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-structures)

[IPAddr](https://learn.microsoft.com/windows/desktop/api/inaddr/ns-inaddr-in_addr)
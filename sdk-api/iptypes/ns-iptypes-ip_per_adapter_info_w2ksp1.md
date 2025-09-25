# IP_PER_ADAPTER_INFO_W2KSP1 structure

## Description

The
**IP_PER_ADAPTER_INFO** structure contains information specific to a particular adapter.

## Members

### `AutoconfigEnabled`

Specifies whether IP address auto-configuration (APIPA) is enabled on this adapter. See Remarks.

### `AutoconfigActive`

Specifies whether this adapter's IP address is currently auto-configured by APIPA.

### `CurrentDnsServer`

Reserved. Use the **DnsServerList** member to obtain the DNS servers for the local computer.

### `DnsServerList`

A linked list of
[IP_ADDR_STRING](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_addr_string) structures that specify the set of DNS servers used by the local computer.

## Remarks

APIPA enables automatic IP address configuration on networks without DHCP servers, using the IANA-reserved Class B network 169.254.0.0, with a subnet mask of 255.255.0.0. Clients send ARP messages to ensure the selected address is not currently in use. Clients auto-configured in this fashion continue to poll for a valid DHCP server every five minutes, and if found, the DHCP server configuration overrides all auto-configuration settings.

## See also

[GetPerAdapterInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getperadapterinfo)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP Helper Structures](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-structures)

[IP_ADDR_STRING](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_addr_string)
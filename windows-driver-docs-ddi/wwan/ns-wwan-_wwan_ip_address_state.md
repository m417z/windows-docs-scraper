# _WWAN_IP_ADDRESS_STATE structure

## Description

The WWAN_IP_ADDRESS_STATE structure represents the IP addresses, gateways, DNS servers, and/or MTUs of a PDP context.

## Members

### `IPv4Flags`

Flags that describe the availability of the IPV4 address, gateway, DNS server, and MTU information of the PDP context.

### `IPv6Flags`

Flags that describe the availability of the IPV6 address, gateway, DNS server, and MTU information of the PDP context.

### `IPv4MTU`

The IPV4 MTU value of the PDP context.

### `IPv6MTU`

The IPV6 MTU value of the PDP context.

### `IpTable`

Pointer to the start of an array of IP addresses of the PDP context.

### `IpCount`

The number of entries in the **IpTable** array.

### `GatewayTable`

Pointer to the start of an array of gateways of the PDP context.

### `GatewayCount`

The number of entries in the **GatewayTable** array.

### `DnsTable`

Pointer to the start of an array of DNS servers of the PDP context.

### `DnsCount`

The number of entries in the **DnsTable** array.

## See also

[WWAN_IPADDRESS_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_ipaddress_entry)

[WWAN_IP_CONFIGURATION_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_ip_configuration_flags)
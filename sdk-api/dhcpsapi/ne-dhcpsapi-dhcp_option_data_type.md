# DHCP_OPTION_DATA_TYPE enumeration

## Description

The **DHCP_OPTION_DATA_TYPE** enumeration defines the set of formats that represent DHCP option data.

## Constants

### `DhcpByteOption`

The option data is stored as a BYTE value.

### `DhcpWordOption`

The option data is stored as a WORD value.

### `DhcpDWordOption`

The option data is stored as a DWORD value.

### `DhcpDWordDWordOption`

The option data is stored as a DWORD_DWORD value.

### `DhcpIpAddressOption`

The option data is an IP address, stored as a [DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value (DWORD).

### `DhcpStringDataOption`

The option data is stored as a Unicode string.

### `DhcpBinaryDataOption`

The option data is stored as a [DHCP_BINARY_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data) structure.

### `DhcpEncapsulatedDataOption`

The option data is encapsulated and stored as a [DHCP_BINARY_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data) structure.

### `DhcpIpv6AddressOption`

The option data is stored as a Unicode string.

## See also

[DHCP_BINARY_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data)
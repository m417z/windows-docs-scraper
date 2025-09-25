# DHCP_BIND_ELEMENT structure

## Description

The **DHCP_BIND_ELEMENT** structure defines an individual network binding for the DHCP server. A single DHCP server can contain multiple bindings and serve multiple networks.

## Members

### `Flags`

Specifies a set of bit flags indicating properties of the network binding.

| Value | Meaning |
| --- | --- |
| **DHCP_ENDPOINT_FLAG_CANT_MODIFY**<br><br>0x01 | The binding specified in this structure cannot be modified. |

### `fBoundToDHCPServer`

Specifies whether or not this binding is set on the DHCP server. If **TRUE**, the binding is set; if **FALSE**, it is not.

### `AdapterPrimaryAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the IP address assigned to the ethernet adapter of the DHCP server.

### `AdapterSubnetAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the subnet IP mask used by this ethernet adapter.

### `IfDescription`

Unicode string that specifies the name assigned to this network interface device.

### `IfIdSize`

Specifies the size of the network interface device ID, in bytes.

### `IfId`

Specifies the network interface device ID.

### `IfId.size_is`

### `IfId.size_is.IfIdSize`

## See also

[DHCP_BIND_ELEMENT_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_bind_element_array)
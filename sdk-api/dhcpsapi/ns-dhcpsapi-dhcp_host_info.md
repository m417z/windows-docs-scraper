# DHCP_HOST_INFO structure

## Description

The **DHCP_HOST_INFO** structure defines information on a DHCP server (host).

## Members

### `IpAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the IP address of the DHCP server.

### `NetBiosName`

Unicode string that contains the NetBIOS name of the DHCP server.

### `HostName`

Unicode string that contains the network name of the DHCP server.

## Remarks

When this structure is populated by the DHCP Server, the **HostName** and **NetBiosName** members may be set to **NULL**.

## See also

[DHCP_SUBNET_ELEMENT_DATA_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v5)
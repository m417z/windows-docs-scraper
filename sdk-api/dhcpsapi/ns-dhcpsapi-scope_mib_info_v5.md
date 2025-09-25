## Description

The **SCOPE_MIB_INFO_V5** structure contains information about a specific DHCP scope.

## Members

### `Subnet`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the IP address of the subnet gateway that defines the scope.

### `NumAddressesInuse`

The number of IP addresses in the scope that are currently assigned to DHCP clients.

### `NumAddressesFree`

The number of IP addresses in the scope that are not currently assigned to DHCP clients.

### `NumPendingOffers`

The number of IP addresses in the scope that have been offered to DHCP clients but have not yet received REQUEST messages.

## See also

[DHCP_MIB_INFO_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_mib_info_v5)

[DhcpGetMibInfoV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetmibinfov5)
# DHCP_RESERVATION_INFO_ARRAY structure

## Description

The **DHCP_RESERVATION_INFO_ARRAY** structure defines an array of IPv4 reservations for DHCPv4 clients.

## Members

### `NumElements`

Integer that specifies the number of IPv4 client reservations in **Elements**.

### `Elements`

Pointer to an array of [DHCP_IP_RESERVATION_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_reservation_info) structures that contain IPv4 client reservations.

### `Elements.size_is`

### `Elements.size_is.NumElements`

## See also

[DhcpV4EnumSubnetReservations](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4enumsubnetreservations)
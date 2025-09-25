# DHCP_BIND_ELEMENT_ARRAY structure

## Description

The **DHCP_BIND_ELEMENT_ARRAY** structure defines an array of network binding elements used by a DHCP server.

## Members

### `NumElements`

Specifies the number of network binding elements listed in *Elements*.

### `Elements`

Specifies an array of [DHCP_BIND_ELEMENT](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_bind_element) structures

### `Elements.size_is`

### `Elements.size_is.NumElements`

## See also

[DHCP_BIND_ELEMENT](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_bind_element)

[DhcpGetServerBindingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetserverbindinginfo)

[DhcpSetServerBindingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetserverbindinginfo)
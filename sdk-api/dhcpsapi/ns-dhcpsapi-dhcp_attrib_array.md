# DHCP_ATTRIB_ARRAY structure

## Description

The **DHCP_ATTRIB_ARRAY** structure defines a set of DHCP server attributes.

## Members

### `NumElements`

Specifies the number of attributes listed in **DhcpAttribs**.

### `DhcpAttribs`

Pointer to a list of [DHCP_ATTRIB](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_attrib) structures that contain the DHCP server attributes.

### `DhcpAttribs.size_is`

### `DhcpAttribs.size_is.NumElements`
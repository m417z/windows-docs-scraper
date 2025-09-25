# DHCPDS_SERVERS structure

## Description

The **DHCPDS_SERVERS** structure defines a list of DHCP servers in the context of directory services.

## Members

### `Flags`

Reserved. This value should be 0.

### `NumElements`

Specifies the number of elements in **Servers**.

### `Servers`

Pointer to an array of [DHCPDS_SERVER](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpds_server) structures that contain information on individual DHCP servers.
# WTSSBX_IP_ADDRESS structure

## Description

Contains information about the IP address of a network resource.

## Members

### `AddressFamily`

A value of the [WTSSBX_ADDRESS_FAMILY](https://learn.microsoft.com/windows/win32/api/tssbx/ne-tssbx-wtssbx_address_family) enumeration type that indicates the address family of the network address.

### `Address`

The network address of the resource.

### `PortNumber`

The port number of the resource that is configured for Remote Desktop Protocol (RDP).

### `dwScope`

The scope of the address. This member is used only for IPv6 addresses.

## See also

[IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin)
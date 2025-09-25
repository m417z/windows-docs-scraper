# WTSSBX_MACHINE_CONNECT_INFO structure

## Description

Contains information about a computer that is accepting remote connections.

## Members

### `wczMachineFQDN`

The fully qualified domain name (FQDN) of the computer. The name cannot exceed 256 characters.

### `wczMachineNetBiosName`

The NetBIOS name of the computer. The name cannot exceed 16 characters.

### `dwNumOfIPAddr`

The number of IP addresses that are configured on the computer.

### `IPaddr`

An array of [WTSSBX_IP_ADDRESS](https://learn.microsoft.com/windows/win32/api/tssbx/ns-tssbx-wtssbx_ip_address) structures that indicate the IP addresses on this computer that are visible to Remote Desktop Connection (RDC) clients. This array cannot exceed 12 elements.

## See also

[IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin)
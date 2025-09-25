# DHCPDS_SERVER structure

## Description

The **DHCPDS_SERVER** structure defines information on a DHCP server in the context of directory services.

## Members

### `Version`

Reserved. This value should be set to 0.

### `ServerName`

Unicode string that contains the unique name of the DHCP server.

### `ServerAddress`

Specifies the IP address of the DHCP server as an unsigned 32-bit integer.

### `Flags`

Specifies a set of bit flags that describe active directory settings for the DHCP server.

### `State`

Reserved. This value should be set to 0.

### `DsLocation`

Unicode string that contains the active directory path to the DHCP server.

### `DsLocType`

Reserved. This value should be set to 0.
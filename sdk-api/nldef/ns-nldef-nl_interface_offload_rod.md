# NL_INTERFACE_OFFLOAD_ROD structure

## Description

The **NL_INTERFACE_OFFLOAD_ROD** structure specifies a set of flags that indicate the offload capabilities for an IP interface.

## Members

### `NlChecksumSupported`

Type: **BOOLEAN**

The network adapter for this network interface supports the offload of IP checksum calculations.

### `NlOptionsSupported`

Type: **BOOLEAN**

The network adapter for this network interface supports the offload of IP checksum calculations for IPv4 packets with IP options.

### `TlDatagramChecksumSupported`

Type: **BOOLEAN**

The network adapter for this network interface supports the offload of UDP checksum calculations.

### `TlStreamChecksumSupported`

Type: **BOOLEAN**

The network adapter for this network interface supports the offload of TCP checksum calculations.

### `TlStreamOptionsSupported`

Type: **BOOLEAN**

The network adapter for this network interface supports the offload of TCP checksum calculations for IPv4 packets containing IP options.

### `FastPathCompatible`

Type: **BOOLEAN**

Reserved for internal use.

### `TlLargeSendOffloadSupported`

Type: **BOOLEAN**

The network adapter for this network interface supports TCP Large Send Offload Version 1. With this capability, TCP can pass a buffer to be transmitted that is bigger than the maximum transmission unit (MTU) supported by the medium. Version 1 allows TCP to pass a buffer up to 64K to be transmitted.

### `TlGiantSendOffloadSupported`

Type: **BOOLEAN**

The network adapter for this network interface supports TCP Large Send Offload Version 2. With this capability, TCP can pass a buffer to be transmitted that is bigger than the maximum transmission unit (MTU) supported by the medium. Version 2 allows TCP to pass a buffer up to 256K to be transmitted.

## Remarks

The **NL_INTERFACE_OFFLOAD_ROD** structure is defined on Windows Vista and later.

## See also

[MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row)
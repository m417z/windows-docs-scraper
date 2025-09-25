# PXE_DHCPV6_OPTION structure

## Description

The **PXE_DHCPV6_OPTION** structure can be used with the Windows Deployment Services PXE Server API.

For more information about the DHCPv6 option code, developers should refer to the Dynamic Host Configuration Protocol for IPv6 ([RFC 3315](https://www.ietf.org/rfc/rfc3315.txt)) maintained by The Internet Engineering Task Force (IETF).

## Members

### `OptionCode`

A DHCPv6 option type.

### `DataLength`

Length of the option value.

### `Data`

The option value.
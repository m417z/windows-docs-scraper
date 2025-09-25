# DHCPV6CAPI_PARAMS structure

## Description

A **DHCPV6CAPI_PARAMS** structure contains a requested parameter.

## Members

### `Flags`

Reserved for future use.

### `OptionId`

Identifier for the DHCPv6 parameter being requested.

#### DHCPV6_OPTION_CLIENTID

#### DHCPV6_OPTION_SERVERID

#### DHCPV6_OPTION_IA_NA

#### DHCPV6_OPTION_IA_TA

#### DHCPV6_OPTION_ORO

#### DHCPV6_OPTION_PREFERENCE

#### DHCPV6_OPTION_UNICAST

#### DHCPV6_OPTION_RAPID_COMMIT

#### DHCPV6_OPTION_USER_CLASS

#### DHCPV6_OPTION_VENDOR_CLASS

#### DHCPV6_OPTION_VENDOR_OPTS

#### DHCPV6_OPTION_RECONF_MSG

#### DHCPV6_OPTION_SIP_SERVERS_NAMES

#### DHCPV6_OPTION_SIP_SERVERS_ADDRS

#### DHCPV6_OPTION_DNS_SERVERS

#### DHCPV6_OPTION_DOMAIN_LIST

#### DHCPV6_OPTION_IA_PD

#### DHCPV6_OPTION_NIS_SERVERS

#### DHCPV6_OPTION_NISP_SERVERS

#### DHCPV6_OPTION_NIS_DOMAIN_NAME

#### DHCPV6_OPTION_CLIENTIDNISP_DOMAIN_NAME

### `IsVendor`

This option is set to **TRUE** if this parameter is vendor-specific. Otherwise, it is **FALSE**.

### `Data`

Contains the actual parameter data.

### `nBytesData`

Size of the **Data** member, in bytes.
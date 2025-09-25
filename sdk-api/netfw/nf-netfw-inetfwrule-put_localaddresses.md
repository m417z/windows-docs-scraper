# INetFwRule::put_LocalAddresses

## Description

Specifies the list of local addresses for this rule.

This property is read/write.

## Parameters

## Remarks

This property is optional.

Also see the restrictions on changing properties described in the Remarks section of the [INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule) interface page.

The *localAddrs* parameter consists of one or more comma-delimited tokens specifying the local addresses from which the application can listen for traffic. "*" is the default value. Valid tokens include:

* "*" indicates any local address. If present, this must be the only token included.
* "Defaultgateway"
* "DHCP"
* "WINS"
* "LocalSubnet" indicates any local address on the local subnet. This token is not case-sensitive.
* A subnet can be specified using either the subnet mask or network prefix notation. If neither a subnet mask not a network prefix is specified, the subnet mask defaults to 255.255.255.255.
* A valid IPv6 address.
* An IPv4 address range in the format of "start address - end address" with no spaces included.
* An IPv6 address range in the format of "start address - end address" with no spaces included.

## See also

[INetFwRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule)
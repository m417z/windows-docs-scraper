# INetFwRemoteAdminSettings::put_RemoteAddresses

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

Specifies a set of remote addresses from which remote administration is allowed.

This property is read/write.

## Parameters

## Remarks

The *remoteAddrs* parameter consists of one or more comma-delimited tokens specifying the remote addresses from which the application can listen for traffic. The default value is "*".

Valid tokens:

* "*": any remote address; if present, it must be the only token.
* "LocalSubnet": not case-sensitive; specifying more than once has no effect.
* subnet: may be specified using either subnet mask or network prefix notation. If neither a subnet mask nor a network prefix is specified, the subnet mask defaults to 255.255.255.255. Examples of valid subnets:
  10.0.0.2/255.0.0.0
  10.0.0.2/8
  10.0.0.2
* Windows Vista: A valid IPv6 address.
* Windows Vista: An IPv4 address range in the format "start address - end address."
* Windows Vista: An IPv6 address range in the format "start address - end address."

For a predefined address range, use the [Scope](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwremoteadminsettings-get_scope) property.

## See also

[INetFwRemoteAdminSettings](https://learn.microsoft.com/windows/desktop/api/netfw/nn-netfw-inetfwremoteadminsettings)
# NL\_PREFIX\_ORIGIN enumeration

The NL\_PREFIX\_ORIGIN enumeration type defines the origin of the prefix or network part of the IP address.

## Constants

- **IpPrefixOriginOther**
The IP address prefix was configured by using a source other than those that are defined in this enumeration. This value applies to an IPv6 or IPv4 address.

- **IpPrefixOriginManual**
The IP address prefix was configured manually. This value applies to an IPv6 or IPv4 address.

- **IpPrefixOriginWellKnown**
The IP address prefix was configured by using a well-known address. This value applies to an IPv6 link-local address or an IPv6 loopback address.

- **IpPrefixOriginDhcp**
The IP address prefix was configured by using DHCP. This value applies to an IPv4 address configured by using DHCP or an IPv6 address configured by using DHCPv6.

- **IpPrefixOriginRouterAdvertisement**
The IP address prefix was configured by using router advertisement. This value applies to an anonymous IPv6 address that was generated after receiving a router advertisement.

- **IpPrefixOriginUnchanged**
The IP address prefix should be unchanged. This value is used when setting the properties for a unicast IP interface when the value for the IP prefix origin should be unchanged.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Nldef.h (include Netioapi.h) |
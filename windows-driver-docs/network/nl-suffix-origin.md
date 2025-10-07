# NL\_SUFFIX\_ORIGIN enumeration

The NL\_SUFFIX\_ORIGIN enumeration type defines the origin of the suffix or host part of the IP address.

## Constants

- **NlsoOther**
Reserved for system use. Do not use this value in your driver.

- **NlsoManual**
Reserved for system use. Do not use this value in your driver.

- **NlsoWellKnown**
Reserved for system use. Do not use this value in your driver.

- **NlsoDhcp**
Reserved for system use. Do not use this value in your driver.

- **NlsoLinkLayerAddress**
Reserved for system use. Do not use this value in your driver.

- **NlsoRandom**
Reserved for system use. Do not use this value in your driver.

- **IpSuffixOriginOther**
The IP address suffix was configured by using a source other than those that are defined in this enumeration. This value applies to an IPv6 or IPv4 address.

- **IpSuffixOriginManual**
The IP address suffix was configured manually. This value applies to an IPv6 or IPv4 address.

- **IpSuffixOriginWellKnown**
The IP address suffix was configured by using a well-known address. This value applies to an IPv6 link-local address or an IPv6 loopback address.

- **IpSuffixOriginDhcp**
The IP address suffix was configured by using DHCP. This value applies to an IPv4 address configured by using DHCP or an IPv6 address configured by using DHCPv6.

- **IpSuffixOriginLinkLayerAddress**
The IP address suffix was the link-local address. This value applies to an IPv6 link-local address or an IPv6 address where the network part was generated based on a router advertisement and the host part was based on the MAC hardware address.

- **IpSuffixOriginRandom**
The IP address suffix was generated randomly. This value applies to an anonymous IPv6 address where the host part of the address was generated randomly from the MAC hardware address after the host received a router advertisement.

- **IpSuffixOriginUnchanged**
The IP address suffix should be unchanged. This value is used when setting the properties for a unicast IP interface when the value for the IP suffix origin should be unchanged.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Nldef.h (include Netioapi.h) |
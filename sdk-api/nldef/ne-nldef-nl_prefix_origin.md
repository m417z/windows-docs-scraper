# NL_PREFIX_ORIGIN enumeration

## Description

The **IP_PREFIX_ORIGIN** enumeration specifies the origin of an IPv4 or IPv6 address prefix, and is used with the [IP_ADAPTER_UNICAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_unicast_address_lh) structure.

## Constants

### `IpPrefixOriginOther:0`

The IP prefix was provided by a source other than those defined in this enumeration.

### `IpPrefixOriginManual`

The IP address prefix was manually specified.

### `IpPrefixOriginWellKnown`

The IP address prefix is from a well known source.

### `IpPrefixOriginDhcp`

The IP address prefix was provided by DHCP settings.

### `IpPrefixOriginRouterAdvertisement`

The IP address prefix was obtained through a router advertisement (RA).

### `IpPrefixOriginUnchanged:1` << 4

The IP address prefix should be unchanged. This value is used when setting the properties for a unicast IP interface when the value for the IP prefix origin should be left unchanged.

**Note** This enumeration value is only available on Windows Vista and later.

## Remarks

The **IP_PREFIX_ORIGIN** enumeration is used in the **PrefixOrigin** member of the [IP_ADAPTER_UNICAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_unicast_address_lh) structure.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **IP_PREFIX_ORIGIN** enumeration is defined in the *Nldef.h* header file which is automatically included by the *Iptypes.h* header file. In order to use the **IP_PREFIX_ORIGIN** enumeration, the *Winsock2.h* header file must be included before the *Iptypes.h* header file.

## See also

[IP_ADAPTER_UNICAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_unicast_address_lh)
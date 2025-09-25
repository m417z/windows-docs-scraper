# NL_SUFFIX_ORIGIN enumeration

## Description

The **IP_SUFFIX_ORIGIN** enumeration specifies the origin of an IPv4 or IPv6 address suffix, and is used with the [IP_ADAPTER_UNICAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_unicast_address_lh) structure.

## Constants

### `NlsoOther:0`

### `NlsoManual`

### `NlsoWellKnown`

### `NlsoDhcp`

### `NlsoLinkLayerAddress`

### `NlsoRandom`

### `IpSuffixOriginOther:0`

The IP address suffix was provided by a source other than those defined in this enumeration.

### `IpSuffixOriginManual`

The IP address suffix was manually specified.

### `IpSuffixOriginWellKnown`

The IP address suffix is from a well-known source.

### `IpSuffixOriginDhcp`

The IP address suffix was provided by DHCP settings.

### `IpSuffixOriginLinkLayerAddress`

The IP address suffix was obtained from the link-layer address.

### `IpSuffixOriginRandom`

The IP address suffix was obtained from a random source.

### `IpSuffixOriginUnchanged:1` << 4

The IP address suffix should be unchanged. This value is used when setting the properties for a unicast IP interface when the value for the IP suffix origin should be left unchanged.

**Note** This enumeration value is only available on Windows Vista and later.

## Remarks

The **IP_SUFFIX_ORIGIN** enumeration is used in the **SuffixOrigin** member of the [IP_ADAPTER_UNICAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_unicast_address_lh) structure.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **IP_SUFFIX_ORIGIN** enumeration is defined in the *Nldef.h* header file which is automatically included by the *Iptypes.h* header file. In order to use the **IP_SUFFIX_ORIGIN** enumeration, the *Winsock2.h* header file must be included before the *Iptypes.h* header file.

## See also

[IP_ADAPTER_UNICAST_ADDRESS](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_unicast_address_lh)
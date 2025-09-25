# TC_GEN_FILTER structure

## Description

The
**TC_GEN_FILTER** structure creates a filter that matches a certain set of packet attributes or criteria, which can subsequently be used to associate packets that meet the attribute criteria with a particular flow. The
**TC_GEN_FILTER** structure uses its **AddressType** member to indicate a specific filter type to apply to the filter.

## Members

### `AddressType`

Defines the filter type to be applied with the filter, as defined in Ntddndis.h. With the designation of a specific filter in **AddressType**, the generic filter structure
**TC_GEN_FILTER** provides a specific filter type.

### `PatternSize`

Size of the **Pattern** member, in bytes.

### `Pattern`

Indicates the specific format of the pattern to be applied to the filter, such as
[IP_PATTERN](https://learn.microsoft.com/windows/desktop/api/traffic/ns-traffic-ip_pattern). The pattern specifies which bits of a given packet should be evaluated when determining whether a packet is included in the filter.

### `Mask`

A bitmask applied to the bits designated in the **Pattern** member. The application of the **Mask** member to the **Pattern** member determines which bits in the **Pattern** member are significant (should be applied to the filter criteria). Note that the **Mask** member must be of the same type as the **Pattern** member.

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)

[IP_PATTERN](https://learn.microsoft.com/windows/desktop/api/traffic/ns-traffic-ip_pattern)
# FWPM_CLASSIFY_OPTION0 structure

## Description

The **FWPM_CLASSIFY_OPTION0** structure is used to define unicast and multicast timeout options and data.

## Members

### `type`

An [FWP_CLASSIFY_OPTION_TYPE](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_classify_option_type) value.

### `value`

An [FWP_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_value0) structure.

## Remarks

The following table lists possible values for the members of a **FWPM_CLASSIFY_OPTION0** structure.

| **type** | **value** |
| --- | --- |
| FWP_CLASSIFY_OPTION_MULTICAST_STATE | * FWP_OPTION_VALUE_ALLOW_MULTICAST_STATE Allow link-local multicast state creation on outbound traffic<br>* FWP_OPTION_VALUE_DENY_MULTICAST_STATE Do not allow link-local multicast state creation on outbound traffic<br>* FWP_OPTION_VALUE_ALLOW_GLOBAL_MULTICAST_STATE Allow global multicast state creation on outbound traffic |
| FWP_CLASSIFY_OPTION_LOOSE_SOURCE_MAPPING | * FWP_OPTION_VALUE_ENABLE_LOOSE_SOURCE Enable loose source mapping<br>* FWP_OPTION_VALUE_DISABLE_LOOSE_SOURCE Disable loose source mapping |
| FWP_CLASSIFY_OPTION_UNICAST_LIFETIME | * Any FWP_UINT32 |
| FWP_CLASSIFY_OPTION_MCAST_BCAST_LIFETIME | * Any FWP_UINT32 |

**FWPM_CLASSIFY_OPTION0** is a specific implementation of FWPM_CLASSIFY_OPTION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_CLASSIFY_OPTIONS0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_classify_options0)

[FWP_CLASSIFY_OPTION_TYPE](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_classify_option_type)

[FWP_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_value0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)
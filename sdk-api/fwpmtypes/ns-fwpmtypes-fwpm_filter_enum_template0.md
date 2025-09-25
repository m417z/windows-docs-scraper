## Description

The **FWPM_FILTER_ENUM_TEMPLATE0** structure is used for enumerating filters.

## Members

### `providerKey`

Uniquely identifies the provider associated with this filter.

### `layerKey`

Layer whose fields are to be enumerated.

### `enumType`

A [FWP_FILTER_ENUM_TYPE](https://learn.microsoft.com/windows/win32/api/fwptypes/ne-fwptypes-fwp_filter_enum_type) value that determines how the filter conditions are interpreted.

### `flags`

| Value | Meaning |
| --- | --- |
| **FWP_FILTER_ENUM_FLAG_BEST_TERMINATING_MATCH** | Only return the terminating filter with the highest weight. |
| **FWP_FILTER_ENUM_FLAG_SORTED** | Return all matching filters sorted by weight (highest to lowest). |
| **FWP_FILTER_ENUM_FLAG_BOOTTIME_ONLY** | Return only boot-time filters. |
| **FWP_FILTER_ENUM_FLAG_INCLUDE_BOOTTIME** | Include boot-time filters; ignored if the **FWP_FILTER_ENUM_FLAG_BOOTTIME_ONLY** flag is set. |
| **FWP_FILTER_ENUM_FLAG_INCLUDE_DISABLED** | Include disabled filters; ignored if the **FWP_FILTER_ENUM_FLAG_BOOTTIME_ONLY** flag is set. |
| **FWP_FILTER_ENUM_VALID_FLAGS** | Combination of **FWP_FILTER_ENUM_FLAG_BEST_TERMINATING_MATCH** and **FWP_FILTER_ENUM_FLAG_SORTED**. |

### `providerContextTemplate`

A [FWPM_PROVIDER_CONTEXT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context_enum_template0) structure that is used to limit the number of filters enumerated. If non-**NULL**, only enumerate filters whose provider context matches the template.

### `numFilterConditions`

Number of filter conditions. If zero, then all filters match.

### `filterCondition`

An array of [FWPM_FILTER_CONDITION0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_filter_condition0) structures that contain distinct filter conditions (duplicated filter conditions will generate an error).

### `actionMask`

Only filters whose action type contains at least one of the bits in **actionMask** will be returned. Using the **FWP_ACTION_** constants directly may not work as intended since they contain multiple bits. Some common examples are in the table below (**^** represents the logical XOR operator).

| Value | Meaning |
| --- | --- |
| FWP_ACTION_BLOCK ^ FWP_ACTION_FLAG_TERMINATING | Enumerate filters that have an **FWP_ACTION_BLOCK** action. |
| FWP_ACTION_PERMIT ^ FWP_ACTION_FLAG_TERMINATING | Enumerate filters that have an **FWP_ACTION_PERMIT** action. |
| **FWP_ACTION_FLAG_CALLOUT** | Enumerate filters that reference callout drivers.<br><br>**Note** **calloutKey** must not be **NULL**. |
| 0xFFFFFFFF | Ignore the filter's action type when enumerating. |

### `calloutKey`

Uniquely identifies the callout.

## Remarks

**FWPM_FILTER_ENUM_TEMPLATE0** is a specific implementation of FWPM_FILTER_ENUM_TEMPLATE. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/win32/fwp/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_FILTER_CONDITION0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_filter_condition0)

[FWPM_PROVIDER_CONTEXT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context_enum_template0)

[FWP_FILTER_ENUM_TYPE](https://learn.microsoft.com/windows/win32/api/fwptypes/ne-fwptypes-fwp_filter_enum_type)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/win32/fwp/fwp-structs)
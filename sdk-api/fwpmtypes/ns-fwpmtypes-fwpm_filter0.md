## Description

The **FWPM_FILTER0** structure stores the state associated with a filter.

## Members

### `filterKey`

Uniquely identifies the session.

If the GUID is initialized to zero in the call to [FwpmFilterAdd0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmfilteradd0), the Base Filtering Engine (BFE) will generate one.

### `displayData`

A [FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwpm_display_data0) structure that contains human-readable annotations associated with the filter. The **name** member of the **FWPM_DISPLAY_DATA0** structure is required.

### `flags`

A combination of the following values.

| Filter flag | Meaning |
| --- | --- |
| **FWPM_FILTER_FLAG_NONE** | Default. |
| **FWPM_FILTER_FLAG_PERSISTENT** | Filter is persistent, that is, it survives across BFE stop/start.<br><br>**Note** This flag cannot be set together with **FWPM_FILTER_FLAG_BOOTTIME**. |
| **FWPM_FILTER_FLAG_BOOTTIME** | Filter is enforced at boot-time, even before BFE starts.<br><br>**Note** This flag cannot be set together with **FWPM_FILTER_FLAG_PERSISTENT**. |
| **FWPM_FILTER_FLAG_HAS_PROVIDER_CONTEXT** | Filter references a provider context. |
| **FWPM_FILTER_FLAG_CLEAR_ACTION_RIGHT** | Clear filter action right. |
| **FWPM_FILTER_FLAG_PERMIT_IF_CALLOUT_UNREGISTERED** | If the callout is not registered, the filter is treated as a permit filter.<br><br>**Note** This flag can be set only if the **action** type is **FWP_ACTION_CALLOUT_TERMINATING** or **FWP_ACTION_CALLOUT_UNKNOWN**. |
| **FWPM_FILTER_FLAG_DISABLED** | Filter is disabled. A provider's filters are disabled when the BFE starts if the provider has no associated Windows service name, or if the associated service is not set to auto-start. <br><br>**Note** This flag cannot be set when adding new filters. It can only be returned by BFE when getting or enumerating filters. |
| **FWPM_FILTER_FLAG_INDEXED** | Filter is indexed to help enable faster lookup during classification.<br><br>**Note** Available only in Windows 8 and Windows Server 2012. |

### `providerKey`

Optional GUID of the policy provider that manages this filter. See [Built-in Provider Identifiers](https://learn.microsoft.com/windows/win32/fwp/built-in-provider-identifiers) for a list of predefined policy providers.

### `providerData`

A [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure that contains optional provider-specific data used by providers to store additional context information with the object.

### `layerKey`

GUID of the layer where the filter resides. See [Filtering Layer Identifiers](https://learn.microsoft.com/windows/win32/fwp/management-filtering-layer-identifiers-) for a list of possible values.

### `subLayerKey`

GUID of the sub-layer where the filter resides. See [Filtering Sub-Layer Identifiers](https://learn.microsoft.com/windows/win32/fwp/management-filtering-sublayer-identifiers) for a list of built-in sub-layers.

If this is set to IID_NULL, the filter is added to the default sublayer.

### `weight`

A [FWP_VALUE0](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_value0) structure that specifies the weight of the filter. The weight indicates the priority of the filter, where higher-numbered weights have higher priorities (and will be evaluated before lower-weighted filters).

Possible type values for **weight** are as follows.

| **weight** type | Meaning |
| --- | --- |
| **FWP_UINT64** | BFE will use the supplied value as the filter's weight. |
| **FWP_UINT8**<br><br>0–15 | BFE will use the supplied value as a weight range index and will compute the filter's weight in that range. See [Filter Weight Assignment](https://learn.microsoft.com/windows/win32/fwp/filter-weight-assignment) for more information. |
| **FWP_EMPTY** | BFE will automatically assign a weight based on the filter conditions. |

See [Filter Weight Identifiers](https://learn.microsoft.com/windows/win32/fwp/filter-weight-identifiers) for built-in constants that may be used to compute the filter weight.

### `numFilterConditions`

Number of filter conditions.

### `filterCondition`

Array of [FWPM_FILTER_CONDITION0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_filter_condition0) structures that contain all the filtering conditions. All must be true for the action to be performed. In other words, the conditions are evaluated using the AND operator. If no conditions are specified, the action is always performed.

**Note** In Windows 7 and Windows Server 2008 R2, consecutive conditions with the same fieldKey will be evaluated using the OR operator.

### `action`

A [FWPM_ACTION0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_action0) structure that specifies the action to be performed if all the filter conditions are true.

### `rawContext`

Available when the filter does not have provider context information, that is, **flags** does not contain **FWPM_FILTER_FLAG_HAS_PROVIDER_CONTEXT**. See [Filter Context Identifiers](https://learn.microsoft.com/windows/win32/fwp/filter-context-identifiers) for a list of built-in possible values.

The **rawContext** is placed 'as is' in the **context** member of the corresponding **FWPS_FILTER0** structure, which is documented in the WDK.

### `providerContextKey`

Available when the filter has provider context information, that is, **flags** contains **FWPM_FILTER_FLAG_HAS_PROVIDER_CONTEXT**. See [Built-in Provider Context Identifiers](https://learn.microsoft.com/windows/win32/fwp/built-in-provider-context-identifiers) for a list of predefined policy provider contexts.

 The LUID of the provider context specified by the **providerContextKey** is used to fill in the **context** member of the corresponding **FWPS_FILTER0** structure, which is documented in the WDK.

### `reserved`

Reserved for system use.

### `filterId`

LUID identifying the filter. This is also the LUID of the corresponding
**FWPS_FILTER0** structure, which is documented in the WDK.

### `effectiveWeight`

An [FWP_VALUE0](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_value0) structure that contains the weight assigned to **FWPS_FILTER0**, which is documented in the WDK.

## Remarks

The first ten members of this structure contain information supplied when adding objects.

The last members, **filterId** and **effectiveWeight**, provides additional information when getting/enumerating objects.

**FWPM_FILTER0** is a specific implementation of FWPM_FILTER. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/win32/fwp/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_ACTION0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_action0)

[FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwpm_display_data0)

[FWPM_FILTER_CONDITION0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_filter_condition0)

[FWP_VALUE0](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_value0)

[Filter Weight Assignment](https://learn.microsoft.com/windows/win32/fwp/filter-weight-assignment)

[Filter Weight Identifiers](https://learn.microsoft.com/windows/win32/fwp/filter-weight-identifiers)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/win32/fwp/fwp-structs)
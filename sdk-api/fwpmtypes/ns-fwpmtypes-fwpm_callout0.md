# FWPM_CALLOUT0 structure

## Description

The **FWPM_CALLOUT0** structure stores the state associated with a callout.

## Members

### `calloutKey`

Uniquely identifies the session.

If the GUID is initialized to zero in the
call to [FwpmCalloutAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmcalloutadd0), the base filtering engine (BFE) will generate one.

### `displayData`

A [FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwpm_display_data0) structure that contains human-readable annotations associated with the callout. The **name** member of the **FWPM_DISPLAY_DATA0** structure is required.

### `flags`

| Value | Meaning |
| --- | --- |
| **FWPM_CALLOUT_FLAG_PERSISTENT** | The callout is persistent across reboots. As a result, it can be referenced by boot-time and other persistent filters. |
| **FWPM_CALLOUT_FLAG_USES_PROVIDER_CONTEXT** | The callout needs access to the provider context stored in the filter invoking the callout. If this flag is set, the provider context will be copied from the [FWPM_FILTER0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_filter0) structure to the **FWPS_FILTER0** structure. The **FWPS_FILTER0** structure is documented in the WDK. |
| **FWPM_CALLOUT_FLAG_REGISTERED** | The callout is currently registered in the kernel. This flag must not be set when adding new callouts. It is used only in querying the state of existing callouts. |

### `providerKey`

Uniquely identifies the provider associated with the callout. If the member is non-NULL, only objects associated with the specified provider will be returned.

### `providerData`

A [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure that contains optional provider-specific data that allows providers to store additional context information with the object.

### `applicableLayer`

Specifies the layer in which the callout can be used. Only filters in this layer can invoke the callout. For more information, see [Filtering Layer Identifiers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

### `calloutId`

 LUID identifying the callout. This is the **calloutId** stored in the
**FWPS_ACTION0** structure for filters that invoke a callout. The **FWPS_ACTION0** structure is documented in the WDK.

## Remarks

The first six members of this structure contain data supplied when adding objects.

The last member, **calloutId**, provides additional information returned when getting/enumerating objects.

**FWPM_CALLOUT0** is a specific implementation of FWPM_CALLOUT. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)
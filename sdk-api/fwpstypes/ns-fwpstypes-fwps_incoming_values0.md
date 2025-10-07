# FWPS_INCOMING_VALUES0 structure

## Description

The **FWPS_INCOMING_VALUES0** structure defines data values that are passed by the filter engine to a
callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn0) callout function.

**Note** **FWPS_INCOMING_VALUES0** is a specific version of **FWPS_INCOMING_VALUES**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `layerId`

The run-time filtering layer identifier for the filtering layer at which the data values were
obtained. For more information, see
[Run-time Filtering Layer
Identifiers](https://learn.microsoft.com/windows/desktop/FWP/management-filtering-layer-identifiers-).

### `valueCount`

The number of
[FWPS_INCOMING_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwpstypes/ns-fwpstypes-fwps_incoming_value0) structures in the
array pointed to by the
**incomingValue** member.

### `incomingValue`

A pointer to an array of
[FWPS_INCOMING_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwpstypes/ns-fwpstypes-fwps_incoming_value0) structures that
contain the data values.

## Remarks

The filter engine passes a pointer to an FWPS_INCOMING_VALUES0 structure to a callout's

 [classifyFn](https://docs.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn0) callout function.
The values in this array depend on the **layerId**; each layer has an associated set of available indexes as outlined in the **FWPS_FIELDS_\<LAYER_ID>** enumerations.
For example, for the **ALE_AUTH_CONNECT_V4** layer, the available indexes are listed in the [FWPS_FIELDS_ALE_AUTH_CONNECT_V4 enumeration](https://learn.microsoft.com/windows/win32/api/fwpstypes/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_fields_ale_auth_connect_v4_).

## See also

[FWPS_INCOMING_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwpstypes/ns-fwpstypes-fwps_incoming_value0)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn0)
# FwpsClassifyOptionSet0 function

## Description

The
**FwpsClassifyOptionSet0** function is called by a callout filter's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function to specify additional
information that affects the characteristics of permitted filtering operations.

**Note** **FwpsClassifyOptionSet0** is a specific version of **FwpsClassifyOptionSet**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `inMetadataValues` [in]

A pointer to an
[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure. This structure contains the values for each of the
metadata fields at the layer that is being filtered.

### `option` [in]

An
[FWP_CLASSIFY_OPTION_TYPE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552428(v=vs.85)) enumeration
constant that indicates whether the
*newValue* parameter refers to unicast, multicast, or loose source mapping states, or to data
time-out values. For more information, see Remarks.

### `newValue` [in]

A pointer to an array of
[FWP_VALUE0](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552450(v=vs.85)) structures. Each structure in the
array contains particular values for a particular FWP_OPTION_VALUE_XXX constant. For more information, see
Remarks.

## Return value

The
**FwpsClassifyOptionSet0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function completed successfully. |
| **STATUS_FWP_INVALID_ENUMERATOR** | The *option* parameter does not match any of the values in the [FWP_CLASSIFY_OPTION_TYPE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552428(v=vs.85)) enumeration. |
| **STATUS_FWP_OUT_OF_BOUNDS** | The option value specified by *newValue* -> **uint32** does not include one of the defined FWP_OPTION_VALUE_XXX constant values. |
| **STATUS_OBJECT_TYPE_MISMATCH** | The data type specified by *newValue* -> **Type** was not FWP_UINT32. |
| **STATUS_UNSUCCESSFUL** | A general error occurred. |
| **Other status codes** | An error occurred. |

## Remarks

This function should be called only by a callout filter's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function.

The following are the allowed values of the
*option* parameter and members of the
[FWP_VALUE0](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552450(v=vs.85)) structure pointed to by the
*newValue* parameter.

| *option* Parameter | newValue->type Value | newValue->uint32 Value |
| --- | --- | --- |
| FWP_CLASSIFY_OPTION_LOOSE_SOURCE_MAPPING | FWP_UINT32 | FWP_OPTION_VALUE_ENABLE_LOOSE_SOURCE<br><br>Enable loose source mapping.<br><br>FWP_OPTION_VALUE_DISABLE_LOOSE_SOURCE<br><br>Disable loose source mapping. |
| FWP_CLASSIFY_OPTION_MULTICAST_STATE | FWP_UINT32 | FWP_OPTION_VALUE_ALLOW_MULTICAST_STATE<br><br>Allow link-local multicast state creation on outbound traffic.<br><br>FWP_OPTION_VALUE_DENY_MULTICAST_STATE<br><br>Do not allow link-local multicast state creation on outbound traffic.<br><br>FWP_OPTION_VALUE_ALLOW_NON_LINK_LOCAL_RESPONSE<br><br>Allow multicast state creation for outbound traffic (permitting non–link-local responses). |
| FWP_CLASSIFY_OPTION_MCAST_BCAST_LIFETIME | FWP_UINT32 > 0 | Specifies the multicast/broadcast state lifetime, in seconds. |
| FWP_CLASSIFY_OPTION_UNICAST_LIFETIME | FWP_UINT32 > 0 | Specifies the unicast state lifetime, in seconds. |

The first (highest weight) caller to set a particular option will be granted that option. For example,
if callout A sets the multicast state option, callout B will not be able to do so, but callout B can set
other options.

## See also

[FWPM_CLASSIFY_OPTION0](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550078(v=vs.85))

[FWPM_CLASSIFY_OPTIONS0](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550079(v=vs.85))

[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_)

[FWP_CLASSIFY_OPTION_TYPE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552428(v=vs.85))

[FWP_VALUE0](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552450(v=vs.85))

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)
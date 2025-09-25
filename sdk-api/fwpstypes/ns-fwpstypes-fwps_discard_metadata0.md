# FWPS_DISCARD_METADATA0 structure

## Description

The **FWPS_DISCARD_METADATA0** structure describes the data that was discarded by the filter engine, a
network layer, or a transport layer.

**Note** **FWPS_DISCARD_METADATA0** is a specific version of **FWPS_DISCARD_METADATA**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `discardModule`

An
[FWPS_DISCARD_MODULE0](https://learn.microsoft.com/windows/desktop/api/fwpstypes/ne-fwpstypes-fwps_discard_module0) type that indicates
the type of module that discarded the data.

### `discardReason`

A UINT32 value that specifies why the data was discarded. For a description of the discard reason identifiers for each type of module, see [Discard Reason Identifiers](https://learn.microsoft.com/windows-hardware/drivers/network/general-discard-reasons).

### `filterId`

A UINT64 value that specifies the run-time identifier for the filter in the filter engine that caused the data to be discarded.

## Remarks

The FWPS_DISCARD_METADATA0 structure contains valid data only if the FWPS_METADATA_FIELD_DISCARD_REASON flag is set in the
**currentMetadataValues** member of the
[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure that the filter engine passes to a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn0) callout function.

## See also

[FWPS_DISCARD_MODULE0](https://learn.microsoft.com/windows/desktop/api/fwpstypes/ne-fwpstypes-fwps_discard_module0)

[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn0)
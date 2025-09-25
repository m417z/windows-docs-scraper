# FWPS_INBOUND_FRAGMENT_METADATA0 structure

## Description

The **FWPS_INBOUND_FRAGMENT_METADATA0** structure describes the fragment data for a received packet
fragment.

**Note** **FWPS_INBOUND_FRAGMENT_METADATA0** is a specific version of **FWPS_INBOUND_FRAGMENT_METADATA**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `fragmentIdentification`

A value that identifies the packet to which the packet fragment belongs.

### `fragmentOffset`

A value that specifies the offset, in bytes, of the packet fragment from the beginning of the
packet.

### `fragmentLength`

A value that specifies the length, in bytes, of the packet fragment.

## Remarks

The FWPS_INBOUND_FRAGMENT_METADATA0 structure contains valid data only if the
FWPS_METADATA_FIELD_FRAGMENT_DATA flag is set in the
**currentMetadataValues** member of the
[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure that the filter engine passes to a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn0) callout function.

## See also

[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn0)
# FWPS_INCOMING_VALUE0 structure

## Description

The **FWPS_INCOMING_VALUE0** structure defines an individual data value.

**Note** **FWPS_INCOMING_VALUE0** is a specific version of **FWPS_INCOMING_VALUE**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `value`

An
[FWP_VALUE0](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552450(v=vs.85)) structure that contains the data value.

## Remarks

The
[FWPS_INCOMING_VALUES0](https://learn.microsoft.com/windows/desktop/api/fwpstypes/ns-fwpstypes-fwps_incoming_values0) structure
contains a pointer to an array of FWPS_INCOMING_VALUE0 structures that contain the incoming data values
that are passed to a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn0) callout function.

## See also

[FWPS_INCOMING_VALUES0](https://learn.microsoft.com/windows/desktop/api/fwpstypes/ns-fwpstypes-fwps_incoming_values0)

[FWP_VALUE0](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552450(v=vs.85))

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nc-fwpsk-fwps_callout_classify_fn0)
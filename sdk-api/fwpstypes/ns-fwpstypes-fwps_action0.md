# FWPS_ACTION0 structure

## Description

The **FWPS_ACTION0** structure specifies the run-time action that the filter engine takes if all of
the filter's filtering conditions are true.

**Note** **FWPS_ACTION0** is a specific version of **FWPS_ACTION**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `type`

An **FWP_ACTION_TYPE** value that represents the action that the filter engine takes if all of
the filter's filtering conditions are true. For a filter that is passed to a callout's
[notifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/_netvista/) or
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/_netvista/) callout function, this member will
be one of the following values:

#### FWP_ACTION_CALLOUT_TERMINATING

Specifies that the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/_netvista/) callout function must return one
of the following values for the action to be taken on the data:

##### FWP_ACTION_BLOCK

Block the data from being transmitted or received.

##### FWP_ACTION_PERMIT

Permit the data to be transmitted or received.

If the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/_netvista/) callout function returns any
other value for the action to be taken on the data, it is handled the same as if the callout driver's
classifyFn callout function returned
**FWP_ACTION_BLOCK**.

#### FWP_ACTION_CALLOUT_INSPECTION

Specifies that the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/_netvista/) callout function must return the
following value for the action to be taken on the data.

##### FWP_ACTION_CONTINUE

Continue on to the next filter.

If the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/_netvista/) callout function returns any
other value for the action to be taken on the data, it is handled the same as if the callout driver's
classifyFn callout function returned
**FWP_ACTION_CONTINUE**.

#### FWP_ACTION_CALLOUT_UNKNOWN

Specifies that the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/_netvista/) callout function can return any
of the following values for the action to be taken on the data:

##### FWP_ACTION_BLOCK

Block the data from being transmitted or received.

##### FWP_ACTION_PERMIT

Permit the data to be transmitted or received.

##### FWP_ACTION_CONTINUE

Continue on to the next filter.

### `calloutId`

The run-time identifier for the callout that the filter engine calls if all of the filter's
filtering conditions are true. This is the same identifier that was returned when the callout driver
called the
[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nf-fwpsk-fwpscalloutregister0) function to
register the callout with the filter engine.

## Remarks

An FWPS_ACTION0 structure is contained within an
[FWPS_FILTER0](https://learn.microsoft.com/windows/desktop/api/fwpstypes/ns-fwpstypes-fwps_filter0) structure.

## See also

[FWPS_FILTER0](https://learn.microsoft.com/windows/desktop/api/fwpstypes/ns-fwpstypes-fwps_filter0)

[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nf-fwpsk-fwpscalloutregister0)

[Types of Callouts](https://learn.microsoft.com/windows-hardware/drivers/network/types-of-callouts)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/_netvista/)

[notifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/_netvista/)
# FwpsCalloutUnregisterByKey0 function

## Description

The
**FwpsCalloutUnregisterByKey0** function unregisters a callout from the filter engine.

**Note** **FwpsCalloutUnregisterByKey0** is a specific version of **FwpsCalloutUnregisterByKey**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `calloutKey` [in]

A pointer to a GUID that uniquely identifies the callout that is being unregistered from the
filter engine. This must be a pointer to the same GUID that was specified when the callout driver called
either the
[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0) or
[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1) functions to
register the callout with the filter engine.

## Return value

The
**FwpsCalloutUnregisterByKey0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callout was successfully unregistered from the filter engine. |
| **STATUS_DEVICE_BUSY** | There are one or more data flows being processed by the callout that have an outstanding context associated with the data flow. A callout driver must call the [FwpsFlowRemoveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsflowremovecontext0) function for each of these data flows to remove the associated context. After the context has been successfully removed from each of these data flows, the callout driver must call the **FwpsCalloutUnregisterByKey0** function again to finish unregistering the callout from the filter engine. |
| **STATUS_FWP_CALLOUT_NOT_FOUND** | There is not a callout registered with the filter engine that matches the GUID specified in the *calloutKey* parameter. |
| **STATUS_FWP_IN_USE** | The callout is already in the process of being registered or unregistered in another thread. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver calls the
**FwpsCalloutUnregisterByKey0** function to unregister a callout from the filter engine, using the GUID
key to identify the callout to be unregistered. This function succeeds even if there are filters in
the filter engine that specify the callout for the filter's action. In this situation, filters with an
action type of **FWP_ACTION_CALLOUT_TERMINATING** or **FWP_ACTION_CALLOUT_UNKNOWN** are treated as
**FWP_ACTION_BLOCK**, and filters with an action type of **FWP_ACTION_CALLOUT_INSPECTION** are ignored after the
callout has been deregistered from the filter engine.

A callout driver cannot be unloaded until all of the callouts that were previously registered with the
filter engine have been successfully unregistered.

## See also

[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0)

[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1)

[FwpsCalloutUnregisterById0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutunregisterbyid0)

[FwpsFlowRemoveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsflowremovecontext0)

[Types of Callouts](https://learn.microsoft.com/windows-hardware/drivers/network/types-of-callouts)
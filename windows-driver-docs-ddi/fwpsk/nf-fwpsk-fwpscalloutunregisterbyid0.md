# FwpsCalloutUnregisterById0 function

## Description

The
**FwpsCalloutUnregisterById0** function unregisters a callout from the filter engine.

**Note** **FwpsCalloutUnregisterById0** is a specific version of **FwpsCalloutUnregisterById**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `calloutId` [in]

The run-time identifier for the callout that is being unregistered from the filter engine. This
must be the run-time identifier that was returned when the callout driver called either the
[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0) or
[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1) function to
register the callout with the filter engine.

## Return value

The
**FwpsCalloutUnregisterById0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callout was successfully unregistered from the filter engine. |
| **STATUS_DEVICE_BUSY** | There are one or more data flows being processed by the callout that have an outstanding context associated with the data flow. A callout driver must call the [FwpsFlowRemoveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsflowremovecontext0) function for each of these data flows to remove the associated context. After the context has been successfully removed from each of these data flows, the callout driver must call the **FwpsCalloutUnregisterById0** function again to finish unregistering the callout from the filter engine. |
| **STATUS_FWP_CALLOUT_NOT_FOUND** | There is not a callout registered with the filter engine that matches the run-time identifier specified in the *calloutId* parameter. |
| **STATUS_FWP_IN_USE** | The callout is already in the process of being registered or unregistered in another thread. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver calls the
**FwpsCalloutUnregisterById0** function to unregister a callout from the filter engine, using the
run-time identifier to identify the callout to be unregistered. This function succeeds even if there
are filters in the filter engine that specify the callout for the filter's action. In this situation,
filters with an action type of **FWP_ACTION_CALLOUT_TERMINATING** or **FWP_ACTION_CALLOUT_UNKNOWN** are treated
as **FWP_ACTION_BLOCK**, and filters with an action type of **FWP_ACTION_CALLOUT_INSPECTION** are ignored after
the callout has been deregistered from the filter engine.

A callout driver cannot be unloaded until all of the callouts that were previously registered with the
filter engine have been successfully unregistered.

## See also

[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0)

[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1)

[FwpsCalloutUnregisterByKey0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutunregisterbykey0)

[FwpsFlowRemoveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsflowremovecontext0)

[Types of Callouts](https://learn.microsoft.com/windows-hardware/drivers/network/types-of-callouts)
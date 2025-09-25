# FwpsCalloutRegister2 function

## Description

The
**FwpsCalloutRegister2** function registers a callout with the filter engine.

**Note** **FwpsCalloutRegister2** is the specific version of **FwpsCalloutRegister** used in Windows 8 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 7, [FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1) is available. For Windows Vista, [FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0) is available.

## Parameters

### `deviceObject` [in, out]

A pointer to a device object that was previously created by the callout driver. For more
information about how a callout driver creates a device object, see
[Creating a Device Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-device-object).

### `callout` [in]

A pointer to a constant
[FWPS_CALLOUT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_callout2_) structure that contains the
data that is required to register the callout with the filter engine.

### `calloutId` [out, optional]

A pointer to a UINT32-typed variable that receives a run-time identifier that identifies the
callout in the filter engine. The callout driver passes this identifier to the
[FwpsCalloutUnregisterById0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutunregisterbyid0) function when unregistering the callout from the filter engine. If a
callout driver is filtering a data flow, it also passes this identifier to the
[FwpsFlowAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsflowassociatecontext0) and
[FwpsFlowRemoveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsflowremovecontext0) functions.
If a callout driver injects data into data streams, it also passes this identifier to the
[FwpsStreamInjectAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsstreaminjectasync0) function.
The filter engine also passes this
identifier to the callout driver's
[flowDeleteFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_flow_delete_notify_fn0) callout function. This
parameter is optional and can be NULL.

## Return value

The
**FwpsCalloutRegister2** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callout was successfully registered with the filter engine. |
| **STATUS_FWP_ALREADY_EXISTS** | The callout could not be registered with the filter engine. A callout is already registered in the filter engine with an identifier identical to the GUID specified in the **calloutKey** member of the [FWPS_CALLOUT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_callout2_) structure pointed to by the *callout* parameter. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver calls the
**FwpsCalloutRegister2** function to register a callout with the filter engine. A callout driver can
register a callout with the filter engine at any time, even if the filter engine is not currently
running.

A callout and filters that specify the callout for the filter's action can be added to the filter
engine before a callout driver registers the callout with the filter engine. In this situation, filters
with an action type of **FWP_ACTION_CALLOUT_TERMINATING** or **FWP_ACTION_CALLOUT_UNKNOWN** are treated as
**FWP_ACTION_BLOCK**, and filters with an action type of **FWP_ACTION_CALLOUT_INSPECTION** are ignored until the
callout is registered with the filter engine.

A callout driver unregisters a callout from the filter engine by calling either the
[FwpsCalloutUnregisterById0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutunregisterbyid0) function or the
[FwpsCalloutUnregisterByKey0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutunregisterbykey0) function. A callout driver cannot be unloaded until all of the callouts
that were previously registered with the filter engine have been successfully unregistered.

This function is essentially identical to the previous version,
[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1). The only difference is the
updated [FWPS_CALLOUT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_callout2_) structure pointed to by the
*callout* parameter.

## See also

[Creating a Device Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-device-object)

[FWPS_CALLOUT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_callout2_)

[FwpsCalloutRegister0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister0)

[FwpsCalloutRegister1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutregister1)

[FwpsCalloutUnregisterById0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutunregisterbyid0)

[FwpsCalloutUnregisterByKey0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscalloutunregisterbykey0)

[FwpsFlowAssociateContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsflowassociatecontext0)

[FwpsFlowRemoveContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsflowremovecontext0)

[FwpsStreamInjectAsync0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsstreaminjectasync0)

[IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice)

[Types of Callouts](https://learn.microsoft.com/windows-hardware/drivers/network/types-of-callouts)

[flowDeleteFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_callout_flow_delete_notify_fn0)
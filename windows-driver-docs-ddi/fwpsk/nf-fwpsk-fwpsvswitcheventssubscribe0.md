# FwpsvSwitchEventsSubscribe0 function

## Description

The **FwpsvSwitchEventsSubscribe0** function registers callback entry points for virtual switch layer events such as virtual port creation and deletion.

**Note** **FwpsvSwitchEventsSubscribe0** is a specific version of **FwpsvSwitchEventsSubscribe**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `providerGuid`

The provider GUID.

### `notifyContext`

An optional pointer to a callout driver–supplied context. Event notification functions pass this parameter back to the driver.

### `flags`

Reserved. Set to zero.

### `reserved`

Reserved. Set to zero.

### `eventDispatchTable`

A pointer to an [FWPS_VSWITCH_EVENT_DISPATCH_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_vswitch_event_dispatch_table0_) structure that defines the callback entry points for virtual switch layer events.

### `subscriptionId`

A pointer to a variable that contains a unique identifier that WFP assigns to the subscription. The caller must return the subscription identifier to WFP with the [FwpsvSwitchEventsUnsubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventsunsubscribe0) function.

## Return value

The
**FwpsvSwitchEventsSubscribe0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | A handle to the classify request was successfully returned. The variable that the *classifyHandle* parameter points to contains the handle for the classify request. |
| **Other status codes** | An error occurred. |

## Remarks

A callout driver calls the **FwpsvSwitchEventsSubscribe0** function to register callback entry points for virtual switch layer events.

The entry points for the callback notification functions are specified in and [FWPS_VSWITCH_EVENT_DISPATCH_TABLE0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_vswitch_event_dispatch_table0_) structure.

The callout driver must later call
[FwpsvSwitchEventsUnsubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventsunsubscribe0) to
free the system resources.

## See also

[FWPS_VSWITCH_EVENT_DISPATCH_TABLE0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_vswitch_event_dispatch_table0_)

[FwpsvSwitchEventsUnsubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventsunsubscribe0)
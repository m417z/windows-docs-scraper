# FwpsvSwitchEventsUnsubscribe0 function

## Description

The **FwpsvSwitchEventsUnsubscribe0** function releases resources that are associated with virtual switch notification subscriptions.

**Note** **FwpsvSwitchEventsUnsubscribe0** is a specific version of **FwpsvSwitchEventsUnsubscribe**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `subscriptionId`

A unique event subscription identifier that the callout driver obtained by calling the [FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0) function.

### `flags`

Reserved. Set this parameter to zero.

### `reserved`

Reserved. Set this parameter to zero.

## Remarks

 A callout driver calls the **FwpsvSwitchEventsUnsubscribe0** function to unsubscribe to virtual switch notifications that the callout driver previously subscribed to by calling the [FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0) function.

## See also

[FwpsvSwitchEventsSubscribe0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsvswitcheventssubscribe0)
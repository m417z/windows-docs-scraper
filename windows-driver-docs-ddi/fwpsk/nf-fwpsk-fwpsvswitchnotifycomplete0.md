# FwpsvSwitchNotifyComplete0 function

## Description

The **FwpsvSwitchNotifyComplete0** function completes a pending virtual switch event notification.

**Note** **FwpsvSwitchNotifyComplete0** is a specific version of **FwpsvSwitchNotifyComplete**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `completionContext`

The context data that was passed to the callback driver from the virtual switch event notify function.

### `status`

Any NTSTATUS value that is a valid return code for the notification that was pending completion except for STATUS_PENDING.

### `flags`

Reserved. Set this member to zero.

### `reserved`

Reserved. Set this member to zero.

## Remarks

 If a callout driver returns STATUS_PENDING from a WFP notification function, WFP will return STATUS_PENDING for any associated OID request. The callout driver calls the **FwpsvSwitchNotifyComplete0** function to complete the pending operation. After the **FwpsvSwitchNotifyComplete0** call, WFP calls the [NdisFOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequestcomplete) function to complete the OID for the virtual switch.

## See also

[FwpsCompleteClassify0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpscompleteclassify0)

[NdisFOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfoidrequestcomplete)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)
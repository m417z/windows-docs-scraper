# FWPS_NET_BUFFER_LIST_NOTIFY_FN1 callback function

## Description

The filter engine calls the *FWPS_NET_BUFFER_LIST_NOTIFY_FN1* callout function to notify the callout driver about events that are
associated with packets tagged by the callout.

**Note** *FWPS_NET_BUFFER_LIST_NOTIFY_FN1* is the specific version of *FWPS_NET_BUFFER_LIST_NOTIFY_FN* used in Windows 8 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows 7, [FWPS_NET_BUFFER_LIST_NOTIFY_FN0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_net_buffer_list_notify_fn0) is available.

## Parameters

### `eventType` [in]

A value that indicates the type of notification that the filter engine is sending to the callout.
This parameter will be set to one of the values of the
[FWPS_NET_BUFFER_LIST_EVENT_TYPE0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_net_buffer_list_event_type0_) enumeration.

### `netBufferList` [in, out]

A pointer to the buffer list that contains packets that were previously tagged as interesting by
the callout driver.

### `newNetBufferList` [in, out, optional]

A pointer to an updated buffer list that contains packets that are interesting to the callout
driver. The use of this parameter differs depending on the type of event. For events where a change is
made to the indicated packet, the changed version is passed as this parameter.

### `layerId` [in]

The layer from which the notification function was called.

### `context` [in]

The context used to tag the packets of interest. This value is the value assigned to the packet by
the callout driver and is used to identify the packet.

### `contextTag` [in]

The context tag used to associate the packets of interest with the context of the callout
driver.

## Return value

A callout's
*FWPS_NET_BUFFER_LIST_NOTIFY_FN1* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callout driver accepts the notification from the filter engine. |
| **Other status codes** | An error occurred. |

## Remarks

This function is associated with a callout driver by a call to [FwpsNetBufferListAssociateContext1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext1). A callout driver can use a single notification function to
handle messages for multiple associated buffer lists by using the context and context tag to
differentiate between instances.

This function is identical to [FWPS_NET_BUFFER_LIST_NOTIFY_FN0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_net_buffer_list_notify_fn0), except that the return type is **NTSTATUS** instead of **VOID**.

## See also

[Callout Driver Callout Functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)

[FWPS_NET_BUFFER_LIST_EVENT_TYPE0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ne-fwpsk-fwps_net_buffer_list_event_type0_)

[FWPS_NET_BUFFER_LIST_NOTIFY_FN0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nc-fwpsk-fwps_net_buffer_list_notify_fn0)

[FwpsNetBufferListAssociateContext1](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsnetbufferlistassociatecontext1)

[Using Packet Tagging](https://learn.microsoft.com/windows-hardware/drivers/network/using-packet-tagging)
## Description

Miniport drivers implement the *NdisSetPollNotification* callback function to enable or disable the interrupt associated with a Poll object.

## Parameters

### `Context` [_In_]

A pointer to the context information that the driver provided when it created the Poll object.

### `Notification` [_Inout_]

A pointer to an [**NDIS_POLL_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_notification) structure containing the interrupt state for the Poll object.

## Return value

## Remarks

Miniport drivers register the *NdisSetPollNotification* callback during miniport adapter initialization. Drivers specify an entry point for the *NdisSetPollNotification* function at the **SetPollNotificationHandler** parameter of the [**NDIS_POLL_CHARACTERISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_characteristics) structure before calling [**NdisRegisterPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisregisterpoll).

NDIS typically invokes the *NdisSetPollNotification* callback when it detects that the miniport driver is not making forward progress in [*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll). NDIS uses *NdisSetPollNotification* to tell the driver that it will stop invoking *NdisPoll*. The driver should invoke [**NdisRequestPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisrequestpoll) when new work is ready to be processed.

## See also

[*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll)

[**NdisRequestPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisrequestpoll)

[**NDIS_POLL_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_notification)

[**NDIS_POLL_CHARACTERISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_characteristics)

[**NdisRegisterPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisregisterpoll)
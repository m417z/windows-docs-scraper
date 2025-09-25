## Description

Miniport drivers implement the *NdisPoll* callback function that NDIS will poll for receive indications and send completions.

## Parameters

### `Context` [_In_]

A pointer to the context information that the driver provided when it created the Poll object.

### `PollData` [_Inout_]

A pointer to an [**NDIS_POLL_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_data) structure that the driver should use to perform receive indications and send completions. It also contains details about how many NBLs need to be indicated.

## Return value

## Remarks

Miniport drivers register the *NdisPoll* callback during miniport adapter initialization. Drivers specify an entry point for the *NdisPoll* function at the **PollHandler** parameter of the [**NDIS_POLL_CHARACTERISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_characteristics) structure before calling [**NdisRegisterPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisregisterpoll).

NDIS will first invoke the *NdisPoll* callback when the driver calls [**NdisRequestPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisrequestpoll). NDIS will keep invoking *NdisPoll* while the driver is making forward progress on receive indications or transmit completions.

The *NdisPoll* callback may be invoked at both PASSIVE_LEVEL and DISPATCH_LEVEL IRQL. The driver shouldn't make assumptions about which level it will be.

The driver must check the **receive** or **transmit** parameters of the [**NDIS_POLL_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_data) structure to get the maximum number of NBLs it can indicate or complete.

For receive indications, the driver should:
1. Fetch up to the maximum number of Rx packets it can indicate.
1. Initialize the NBLs.
1. Add them to the NBL queue provided by the [**NDIS_POLL_RECEIVE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_receive_data) structure (located in the [**NDIS_POLL_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_data) structure of the *NdisPoll* **PollData** parameter).
1. Exit the callback.

For transmit completions, the driver should:
1. Fetch up to the maximum number of Tx packets it can complete.
1. Complete the NBLs.
1. Add them to the NBL queue provided by the [**NDIS_POLL_TRANSMIT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_transmit_data) structure (located in the [**NDIS_POLL_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_data) structure of the *NdisPoll* **PollData** parameter).
1. Exit the callback.

The driver should not enable the Poll object's interrupt before exiting the *NdisPoll* function. NDIS will keep polling the driver until it assesses that no forward progress is being made. At this point NDIS will stop polling and ask the driver to reenable the interrupt by invoking the [*NdisSetPollNotification*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_set_poll_notification) callback.

## See also

[*NdisSetPollNotification*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_set_poll_notification)

[**NDIS_POLL_CHARACTERISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_characteristics)

[**NDIS_POLL_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_data)

[**NDIS_POLL_RECEIVE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_receive_data)

[**NdisRegisterPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisregisterpoll)

[**NdisRequestPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisrequestpoll)
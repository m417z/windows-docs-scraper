## Description

The **NDIS_POLL_CHARACTERISTICS** structure contains a Poll object’s [*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll) and [*NdisSetPollNotification*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_set_poll_notification) callback pointers.

## Members

### `Header`

The [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the **NDIS_POLL_CHARACTERISTICS** structure. Set the members of this structure as follows:

- **Type** = NDIS_OBJECT_TYPE_DEFAULT
- **Revision** = NDIS_POLL_CHARACTERISTICS_REVISION_1
- **Size** = NDIS_SIZEOF_NDIS_POLL_CHARACTERISTICS_REVISION_1

### `SetPollNotificationHandler`

An entry point for the [*NdisSetPollNotification*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_set_poll_notification) callback function that NDIS invokes when it wants the driver to enable or disable interrupts.

### `PollHandler`

An entry point for the [*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll) callback function that NDIS invokes to poll the driver for receive indications and send completions.

## Remarks

Miniport drivers initialize the **NDIS_POLL_CHARACTERISTICS** structure and then pass it to NDIS when calling [**NdisRegisterPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisregisterpoll).

## See also

[*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll)

[*NdisSetPollNotification*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_set_poll_notification)

[**NdisRegisterPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisregisterpoll)
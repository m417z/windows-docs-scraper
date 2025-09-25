## Description

A miniport driver calls the **NdisSetPollAffinity** function to lock an [*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll) callback to a processor.

## Parameters

### `PollHandle` [_In_]

A handle to the Poll object returned by a successful call to [**NdisRegisterPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisregisterpoll).

### `PollAffinity` [_In_]

A pointer to a driver-initialized [**PROCESSOR_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number) structure that describes the core on which the driver wants the [*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll) callback for this object to be called.

## Remarks

After **NdisSetPollAffinity** returns one poll iteration can still occur with the old affinity. The affinity works when polling both at PASSIVE_LEVEL and DISPATCH_LEVEL IRQL.

## See also

[*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll)

[**NdisRegisterPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisregisterpoll)
## Description

Miniport drivers call **NdisRequestPoll** to ask NDIS to execute the [*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll) callback for this Poll object.

## Parameters

### `PollHandle` [_In_]

A handle to the Poll object returned by a successful call to [**NdisRegisterPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisregisterpoll).

### `Reserved`

[_Reserved_] Reserved for future use. The driver must set to **zero**.

## Remarks

A driver calls **NdisRequestPoll** to ask NDIS to execute the [*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll) callback for this Poll object. It is guaranteed that NDIS will invoke the *NdisPoll* callback at least once. **NdisRequestPoll** can be called from any IRQL, typically from interrupt handling routines.

## See also

[*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll)

[**NdisRegisterPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisregisterpoll)
## Description

A miniport driver calls the **NdisDeregisterPoll** function to deregister a Poll object it previously registered with a call to the [**NdisRegisterPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisregisterpoll) function.

## Parameters

### `PollHandle` [_In_]

A handle to the Poll object returned by a successful call to [**NdisRegisterPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisregisterpoll).

## Remarks

The **NdisDeregisterPoll** runs down any polling currently in progress.

Drivers typically call **NdisDeregisterPoll** from their [*MiniportHalt*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function.

## See also

[**NdisRegisterPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisregisterpoll)
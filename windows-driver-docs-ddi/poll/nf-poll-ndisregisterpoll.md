## Description

A miniport driver calls the **NdisRegisterPoll** function to register a Poll object with NDIS.

## Parameters

### `NdisHandle` [_In_]

An NDIS-supplied miniport handle given to the driver in their [*MiniportInitialize*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) callback.

### `Context` [_In_opt_]

A pointer to a block of driver-allocated context that stores information about the Poll object. NDIS passes this context information in calls to [*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll) and [*NdisSetPollNotification*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_set_poll_notification).

### `Characteristics` [_In_]

A pointer to a driver-initialized [**NDIS_POLL_CHARACTERISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_characteristics) structure.

### `PollHandle` [_Out_]

On a successful return this location contains a handle for the new Poll object.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

Drivers typically register one Poll object for each RSS processor in their [*MiniportInitialize*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) callback.

Drivers should call the [**NdisDeregisterPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisderegisterpoll) to deregister the Poll object.

## See also

[*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll)

[*NdisSetPollNotification*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_set_poll_notification)

[**NDIS_POLL_CHARACTERISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_characteristics)

[**NdisDeregisterPoll**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nf-poll-ndisderegisterpoll)
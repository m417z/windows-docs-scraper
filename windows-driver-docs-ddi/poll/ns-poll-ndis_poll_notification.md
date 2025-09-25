## Description

The **NDIS_POLL_NOTIFICATION** structure contains the interrupt state associated with a Poll object.

## Members

### `Header`

The header information for the **NDIS_POLL_NOTIFICATION** structure.

### `Enabled`

A value of **TRUE** requests that the miniport driver enable the interrupt associated with this Poll object. A value of **FALSE** requests that the miniport driver disable the interrupt.

## Remarks

NDIS passes a pointer to the **NDIS_POLL_NOTIFICATION** structure when invoking the miniport driver's [*NdisSetPollNotification*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_set_poll_notification) callback.

## See also

[*NdisSetPollNotification*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_set_poll_notification)
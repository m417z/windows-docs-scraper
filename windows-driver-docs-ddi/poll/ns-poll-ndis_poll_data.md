## Description

The **NDIS_POLL_DATA** structure contains pointers to the [**NDIS_POLL_TRANSMIT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_transmit_data) and [**NDIS_POLL_RECEIVE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_receive_data) structures that the miniport driver uses to perform receive indications and send completions when using a Poll object.

## Members

### `Header`

The header information for the **NDIS_POLL_DATA** structure.

### `Transmit`

An [**NDIS_POLL_TRANSMIT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_transmit_data) structure.

### `Receive`

An [**NDIS_POLL_RECEIVE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_receive_data) structure.

## Remarks

NDIS passes a pointer to the **NDIS_POLL_DATA** structure when invoking [*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll).

## See also

[**NDIS_POLL_TRANSMIT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_transmit_data)

[**NDIS_POLL_RECEIVE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_receive_data)

[*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll)
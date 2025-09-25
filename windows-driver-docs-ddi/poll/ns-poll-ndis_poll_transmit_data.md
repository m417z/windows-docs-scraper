## Description

Miniport drivers use the **NDIS_POLL_TRANSMIT_DATA** structure to perform send completions when using a Poll object.

## Members

### `MaxNblsToComplete`

The maximum number of [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures (NBLs) that a miniport driver should include in a transmit completion. If this value is **NDIS_ANY_NUMBER_OF_NBLS**, the driver may complete an unlimited number of transmit NBLs.

### `Reserved1`

Reserved for future use, must be **zero**.

### `CompletedNblChain`

A pointer that the miniport driver assigns to an NBL chain with the completed transmit packets.

### `NumberOfCompletedNbls`

The number of NBLs that the driver placed in the **CompletedNblChain**. The driver can set this value to **NDIS_ANY_NUMBER_OF_NBLS** if it wants NDIS to count the NBLs.

### `NumberOfRemainingNbls`

Specifies the number of NBLs that remain to be completed. A value of **zero** indicates that there are no more NBLs to complete. A value of **NDIS_ANY_NUMBER_OF_NBLS** indicates that there is some unknown (but non-zero) number of NBLs remaining. The driver should only fill this field with a precise number if it is cheap to calculate.

### `SendCompleteFlags`

A combination of zero or more of the following flags:

`NDIS_SEND_COMPLETE_FLAGS_SINGLE_QUEUE`

`NDIS_SEND_COMPLETE_FLAGS_SWITCH_SINGLE_SOURCE`

### `Reserved2`

Reserved for future use, must be **zero**.

### `Reserved3`

Reserved for future use, must be **zero**.

## Remarks

An instance the **NDIS_POLL_TRANSMIT_DATA** structure is contained in the [**NDIS_POLL_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_data) structure that NDIS passes to the miniport driver as a parameter to the [*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll) callback.

## See also

[*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll)

[**NDIS_POLL_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_data)

[**NDIS_POLL_RECEIVE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_receive_data)
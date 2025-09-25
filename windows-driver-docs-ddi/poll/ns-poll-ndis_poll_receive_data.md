## Description

Miniport drivers use the **NDIS_POLL_RECEIVE_DATA** structure to perform receive indications when using a Poll object.

## Members

### `MaxNblsToIndicate`

The maximum number of [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures (NBLs) that a miniport driver should include in a receive indication. If this value is **NDIS_ANY_NUMBER_OF_NBLS**, the driver may indicate an unlimited number of NBLs.

### `Reserved1`

Reserved for future use, must be **zero**.

### `IndicatedNblChain`

A pointer that the miniport driver assigns to an NBL chain with the indicated receive packets.

### `NumberOfIndicatedNbls`

The number of NBLs that the driver placed in the **IndicatedNblChain**. The driver can set this value to **NDIS_ANY_NUMBER_OF_NBLS** if it wants NDIS to count the NBLs.

### `NumberOfRemainingNbls`

Specifies the number of NBLs that remain to be indicated. A value of **zero** indicates that there are no more NBLs to indicate. A value of **NDIS_ANY_NUMBER_OF_NBLS** indicates that there is some unknown (but non-zero) number of NBLs remaining. The driver should only fill this field with a precise number if it is cheap to calculate.

### `Flags`

A combination of zero or more of the following flags:

`NDIS_RECEIVE_FLAGS_SINGLE_ETHER_TYPE`

`NDIS_RECEIVE_FLAGS_SINGLE_VLAN`

`NDIS_RECEIVE_FLAGS_PERFECT_FILTERED`

`NDIS_RECEIVE_FLAGS_SINGLE_QUEUE`

`NDIS_RECEIVE_FLAGS_SHARED_MEMORY_VALID`

### `Reserved2`

Reserved for future use, must be **zero**.

### `Reserved3`

Reserved for future use, must be **zero**.

## Remarks

An instance the **NDIS_POLL_RECEIVE_DATA** structure is contained in the [**NDIS_POLL_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_data) structure that NDIS passes to the miniport driver as a parameter to the [*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll) callback.

## See also

[*NdisPoll*](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/nc-poll-ndis_poll)

[**NDIS_POLL_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_data)

[**NDIS_POLL_TRANSMIT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/poll/ns-poll-ndis_poll_transmit_data)
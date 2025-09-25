# _NDIS_RECEIVE_THROTTLE_PARAMETERS structure

## Description

The NDIS_RECEIVE_THROTTLE_PARAMETERS structure specifies the maximum number of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that a miniport
driver should indicate in a deferred procedure call (DPC).

## Members

### `MaxNblsToIndicate`

The maximum number of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that a miniport
driver should include in a receive indication. If this value is NDIS_INDICATE_ALL_NBLS, the miniport can
indicate all of the NET_BUFFER_LIST structures that it has.

### `MoreNblsPending`

A value that, when **TRUE**, specifies that the miniport driver has NET_BUFFER_LIST structures pending
after it processed the maxim number or structures that NDIS requested in the
**MaxNblsToIndicate** member.

**Note** If NDIS set the
**MaxNblsToIndicate** member to NDIS_INDICATE_ALL_NBLS, the miniport driver should set
**MoreNblsPending** to **FALSE** before it returns from the DPC.

## Remarks

The
*ReceiveThrottleParameters* parameters of the
[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) and the
[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc) DPC handler functions point to an NDIS_RECEIVE_THROTTLE_PARAMETERS
structure. This structure specifies the parameters of
[Receive Side Throttle
(RST)](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_receive_throttle_parameters) in NDIS 6.20 and later.

On entry to the DPC handler, the
**MaxNblsToIndicate** member of the NDIS_RECEIVE_THROTTLE_PARAMETERS structure specifies the maximum
number of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that the miniport
driver should indicate in the DPC. If this value is NDIS_INDICATE_ALL_NBLS, the miniport driver can
indicate all of the NET_BUFFER_LIST structures that it has in its queues.

After the miniport driver processes the specified maximum number of NET_BUFFER_LIST structures, the
miniport driver might have more packets in its receive queues. In this case, the miniport driver should
set the
**MoreNblsPending** member to **TRUE** and it should not re-enable interrupts before it returns from the
DPC. This is true for both line-based and message biased interrupts.

The miniport driver should follow these guidelines when the
**MaxNblsToIndicate** member is set to NDIS_INDICATE_ALL_NBLS:

* A value of NDIS_INDICATE_ALL_NBLS allows the miniport driver to determine the number of
  NET_BUFFER_LIST structures that it indicates in a DPC call. This gives the miniport driver the following
  options:
  + The miniport driver can indicate all of its pending NET_BUFFER_LIST structures from its receive
    queues.
  + The miniport driver can limit the number of NET_BUFFER_LIST structures that it indicates based on
    its heuristics to avoid spending an excessive amount of time within a DPC call.

    In particular, the driver should use its heuristics to avoid a DPC timeout, which is the maximum
    amount of time the driver can spend in its DPC. When the timeout interval expires, a bugcheck occurs
    on the system. Starting with Windows 7, the DPC timeout is 10 seconds.
* The miniport driver should set
  **MoreNblsPending** to **FALSE** before it returns from the DPC. The driver should do this regardless of
  whether it has pending NET_BUFFER_LIST structures in its receive queues that have not been
  indicated.

If the miniport driver is using line-based interrupts or a single MSI message, it should do
interrupt-processing for all of the interrupt sources that it has. If there are packets in the receive
queue, it should indicate at most
**MaxNblsToIndicate** NET_BUFFER_LIST structures to NDIS with the
[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists) function.

If the miniport driver is using multiple MSI messages to differentiate different interrupt sources, it
should ignore the
*ReceiveThrottleParameters* member for MSI messages that are not associated with receive indications.
For receive interrupt messages, the miniport driver should indicate at most
**MaxNblsToIndicate** NET_BUFFER_LIST structures.

**Note** If the miniport driver sets
**MoreNblsPending**, NDIS will call the DPC again. However, the amount of time that passes before the
next DPC call is not defined. Also, the amount of time between the initial interrupt service routing
(ISR) returns and the DPC is not defined. After the miniport driver sets **MoreNblsPending**, it should handle the next DPC as it handled the first DPC.

## See also

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists)
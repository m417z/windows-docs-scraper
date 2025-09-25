# FwpsReferenceNetBufferList0 function

## Description

The
**FwpsReferenceNetBufferList0** function increments the reference count for a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

**Note** **FwpsReferenceNetBufferList0** is a specific version of **FwpsReferenceNetBufferList**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `netBufferList` [in, out]

A pointer to the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure for which the
reference count is being incremented.

### `intendToModify` [in]

A value that indicates whether a callout intends to modify the cloned network buffer list, whose
parent is pointed to by the
*netBufferList* parameter, after the
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function has returned. If **TRUE**,
the callout intends to modify the cloned net buffer list after
*classifyFn* has returned (an out-of-band modification). Otherwise, set to **FALSE**.

## Remarks

A callout driver calls the
**FwpsReferenceNetBufferList0** function to increment the reference count for a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure such that the network
buffer list remains valid outside of the
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) function.

For example, when a callout driver performs packet reassembly, it increments the reference count for
each of the received NET_BUFFER_LIST structures that describe the packet fragments that make up an
individual packet. This allows the new NET_BUFFER_LIST structure that describes the reassembled packet to
safely reference the memory descriptor lists (MDLs) pointed to by the NET_BUFFER_LIST structures that describe the packet
fragments. After the callout driver has injected the new NET_BUFFER_LIST structure into the network
stack, it decrements the reference count for each of the NET_BUFFER_LIST structures that describe the
packet fragments from its packet injection completion routine.

A callout driver must call the
[FwpsDereferenceNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsdereferencenetbufferlist0) function for the NET_BUFFER_LIST structure after the callout driver
has finished referencing the structure.

### Guidelines for Managing Referenced Packets

A callout driver must not hold referenced packets indefinitely. A referenced packet can interfere
with power management operations on an idle computer.

The intended use for referenced packets in WFP is to get clarification from a user-mode application
or other relatively fast operation. The callout driver must not hold referenced packets while, for
example, waiting for user input, web service clearance, or any other
operation that might take an arbitrary amount of time.

If the callout driver must wait for a potentially lengthy operation, it should make a deep copy of
the packet using
[FwpsAllocateNetBufferAndNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsallocatenetbufferandnetbufferlist0) and block and absorb the original packet.

Callout drivers should always return held packets as quickly as possible.

## See also

[FwpsDereferenceNetBufferList0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsdereferencenetbufferlist0)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)
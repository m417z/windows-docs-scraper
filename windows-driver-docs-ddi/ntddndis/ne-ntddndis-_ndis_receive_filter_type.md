# _NDIS_RECEIVE_FILTER_TYPE enumeration

## Description

The **NDIS_RECEIVE_FILTER_TYPE** enumeration identifies the receive filter types that the miniport driver
supports.

## Constants

### `NdisReceiveFilterTypeUndefined`

An undefined filter.

### `NdisReceiveFilterTypeVMQueue`

A filter for a virtual machine (VM) receive queue. This receive queue has been allocated by the miniport driver that supports the virtual machine queue (VMQ) or single root I/O virtualization (SR-IOV) interface.

### `NdisReceiveFilterTypePacketCoalescing`

A packet coalescing filter.

### `NdisReceiveFilterTypeMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The NDIS_RECEIVE_FILTER_TYPE enumeration is used in the
[NDIS_RECEIVE_FILTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_parameters) structure.

For more information about VMQ, see [Virtual Machine Queue (VMQ)](https://learn.microsoft.com/windows-hardware/drivers/network/virtual-machine-queue-architecture).

For more information about SR-IOV, see [Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/single-root-i-o-virtualization--sr-iov-).

For more information about packet coalescing, see [NDIS Packet Coalescing](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-packet-coalescing).

## See also

[NDIS_RECEIVE_FILTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_parameters)
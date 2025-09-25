# TCP_OFFLOAD_RECEIVE_INDICATE_HANDLER callback function

## Description

[The TCP chimney offload feature is deprecated and should not be used.]

NDIS calls a protocol driver's or intermediate driver's
*ProtocolTcpOffloadReceiveIndicate* function to deliver received data that is being indicated by an
underlying driver or offload target.

## Parameters

### `OffloadContext` [in]

A pointer to the protocol or intermediate driver's
[NDIS_OFFLOAD_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_offload_handle) structure for the
TCP connection on which the indication is being made. The protocol or intermediate driver supplied this
pointer as an input parameter to the
[NdisInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisinitiateoffload) function when
offloading the connection.

### `NetBufferList` [in]

A pointer to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. Each
**NET_BUFFER_LIST** structure
describes a list of
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures. Each
**NET_BUFFER** structure in the list maps to a
chain of
[memory descriptor lists (MDLs)](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl). The MDLs contain the
received data. The MDLs are locked so that they remain resident, but they are not mapped into system
memory.

The
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure
specified by
*NetBufferList* must be a stand-alone structure and cannot be the first
structure in a linked list of
**NET_BUFFER_LIST** structures.
Offload targets can work around this limitation by chaining as many MDLs as necessary to the same
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) in an offload receive
indication.

### `Status` [in]

An intermediate driver should propagate this status when calling
[NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate).

### `BytesConsumed` [out]

A pointer to a ULONG-typed variable that receives the number of bytes that were consumed by the
client application.

## Return value

The
*ProtocolTcpOffloadReceiveIndicate* function can return one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The client application consumed all the indicated receive data. |
| **NDIS_STATUS_OFFLOAD_DATA_NOT_ACCEPTED** | The client application rejected all the indicated receive data. |
| **NDIS_STATUS_OFFLOAD_DATA_PARTIALLY_ACCEPTED** | The client application consumed a subset of the indicated receive data. The amount of data, in bytes, that was consumed by the client application is returned in the variable specified by the *BytesConsumed* parameter. |

## Remarks

To propagate the indication to the overlying driver or host stack, the intermediate driver calls the
[NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate) function. The intermediate driver passes the following parameters to
the
**NdisTcpOffloadReceiveHandler** function:

* The
  **NdisOffloadHandle** that the offload target stored in its context for the offloaded TCP connection.
  For more information, see
  [Referencing Offloaded State Through an Intermediate Driver](https://learn.microsoft.com/windows-hardware/drivers/network/referencing-offloaded-state-through-an-intermediate-driver).
* The
  *NetBufferList* pointer that NDIS passed to the intermediate driver's
  *ProtocolTcpOffloadReceiveIndicate* function.
* The
  *Status* that NDIS passed to the intermediate driver's
  *ProtocolTcpOffloadReceiveIndicate* function.

## See also

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[NDIS_OFFLOAD_HANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_offload_handle)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisInitiateOffload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisinitiateoffload)

[NdisOffloadTcpReceiveReturn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nf-ndischimney-ndisoffloadtcpreceivereturn)

[NdisTcpOffloadReceiveHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/nc-ndischimney-ndis_tcp_offload_receive_indicate)
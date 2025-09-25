# NET_BUFFER_LIST_RECEIVE_QUEUE_ID macro

## Description

The **NET_BUFFER_LIST_RECEIVE_QUEUE_ID** macro sets or gets the identifier of a virtual machine queue (VMQ) or single root I/O virtualization (SR-IOV) receive queue identifier within the out-of-band (OOB) data of a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

For the SR-IOV interface, the receive queue is created on a default or nondefault virtual port (VPort). Starting with Windows Server 2012, only the default receive queue of a VPort is supported.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_RECEIVE_QUEUE_ID** returns a USHORT value for a receive queue identifier.

## Remarks

Any NDIS 6.20 or later driver can use **NET_BUFFER_LIST_RECEIVE_QUEUE_ID** to set or get the receive queue identifier from a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. **NET_BUFFER_LIST_RECEIVE_QUEUE_ID** accesses the receive queue identifier from the **QueueId** member of the [**NDIS_NET_BUFFER_LIST_FILTERING_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_net_buffer_list_filtering_info) structure.

> [!NOTE]
> When a VMQ is deleted (for example, during VM live migration), it is possible for the miniport driver to receive an NBL that contains an invalid **QueueId** value. If this happens, the miniport should ignore the invalid queue ID and use 0 (the default queue) instead. The **QueueId** is found in the **NetBufferListFilteringInfo** portion of the NBL's OOB data, and is retrieved by using the **NET_BUFFER_LIST_RECEIVE_QUEUE_ID** macro.

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[**NDIS_NET_BUFFER_LIST_FILTERING_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_net_buffer_list_filtering_info)
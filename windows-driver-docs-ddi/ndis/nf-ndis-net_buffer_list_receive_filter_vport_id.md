# NET_BUFFER_LIST_RECEIVE_FILTER_VPORT_ID macro

## Description

The **NET_BUFFER_LIST_RECEIVE_FILTER_VPORT_ID** macro sets or gets the identifier of a virtual port (VPort) within the out-of-band (OOB) data in a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_RECEIVE_FILTER_VPORT_ID** returns a USHORT value for a VPort identifier.

## Remarks

Miniport drivers that support the single root I/O virtualization (SR-IOV) interface can use the **NET_BUFFER_LIST_RECEIVE_FILTER_VPORT_ID** macro to set or get the VPort identifier in a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. The **NET_BUFFER_LIST_RECEIVE_FILTER_VPORT_ID** macro accesses the VPort identifier from the **VPortId** member of the [**NDIS_NET_BUFFER_LIST_FILTERING_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_net_buffer_list_filtering_info) structure.

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[**NDIS_NET_BUFFER_LIST_FILTERING_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_net_buffer_list_filtering_info)
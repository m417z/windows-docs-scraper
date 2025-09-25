# NET_BUFFER_LIST_RECEIVE_FILTER_ID macro

## Description

The **NET_BUFFER_LIST_RECEIVE_FILTER_ID** macro gets a receive filter identifier from the out-of-band (OOB) data in a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_RECEIVE_FILTER_ID** returns a USHORT value for a receive filter identifier.

## Remarks

Any NDIS 6.20 or later driver can use **NET_BUFFER_LIST_RECEIVE_FILTER_ID** to get the receive filter identifier from a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

**NET_BUFFER_LIST_RECEIVE_FILTER_ID** gets the receive filter identifier from the **FilterId** member of the [**NDIS_NET_BUFFER_LIST_FILTERING_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_net_buffer_list_filtering_info) structure.

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[**NDIS_NET_BUFFER_LIST_FILTERING_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_net_buffer_list_filtering_info)
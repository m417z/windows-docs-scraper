## Description

The **NET_BUFFER_LIST_IS_TCP_LSO_SET** function returns whether the TCP large send offload (LSO) offload information is set for a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `Nbl` [in]

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

Returns a non-zero value if the TCP LSO feature is enabled for this **NET_BUFFER_LIST**.

## Remarks

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[Offloading the Segmentation of Large TCP Packets](https://learn.microsoft.com/windows-hardware/drivers/network/offloading-the-segmentation-of-large-tcp-packets)
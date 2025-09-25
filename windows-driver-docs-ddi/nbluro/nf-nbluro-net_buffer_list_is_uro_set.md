## Description

The **NET_BUFFER_LIST_IS_URO_SET** macro returns whether the [UDP Receive Segment Coalescing Offload (URO)](https://learn.microsoft.com/windows-hardware/drivers/network/udp-rsc-offload) offload information is set for a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

Returns a non-zero value if the URO feature is enabled for this NET_BUFFER_LIST.

## Remarks

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[UDP Receive Segment Coalescing Offload (URO)](https://learn.microsoft.com/windows-hardware/drivers/network/udp-rsc-offload)
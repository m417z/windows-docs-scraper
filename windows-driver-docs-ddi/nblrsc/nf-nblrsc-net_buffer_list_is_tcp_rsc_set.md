## Description

The **NET_BUFFER_LIST_IS_TCP_RSC_SET** function returns whether receive segment coalescing (RSC) is set for a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `Nbl` [in]

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

Returns a non-zero value if RSC is enabled for this **NET_BUFFER_LIST**.

## Remarks

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)
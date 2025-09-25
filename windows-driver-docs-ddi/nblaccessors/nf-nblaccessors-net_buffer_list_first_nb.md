# NET_BUFFER_LIST_FIRST_NB macro

## Description

**NET_BUFFER_LIST_FIRST_NB** is a macro that NDIS drivers use to get the first [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure in a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Syntax

```cpp
#define NET_BUFFER_LIST_FIRST_NB(_NBL) ((_NBL)->FirstNetBuffer)
```

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_FIRST_NB** returns a pointer to the first **NET_BUFFER** structure in the indicated **NET_BUFFER_LIST** structure.

## Remarks

**NET_BUFFER_LIST_FIRST_NB** gets the return value from the **FirstNetBuffer** member of the [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## See also

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)
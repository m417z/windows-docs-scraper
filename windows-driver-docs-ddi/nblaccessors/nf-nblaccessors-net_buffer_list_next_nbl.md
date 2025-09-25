# NET_BUFFER_LIST_NEXT_NBL macro

## Description

**NET_BUFFER_LIST_NEXT_NBL** is a macro that NDIS drivers use to get the next [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure in a linked list of **NET_BUFFER_LIST** structures.

## Syntax

```cpp
#define NET_BUFFER_LIST_NEXT_NBL(_NBL) ((_NBL)->Next)
```

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_NEXT_NBL** returns a pointer to the next [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure in the linked list of **NET_BUFFER_LIST** structures, or it returns **NULL** if the end of the linked list is reached.

## Remarks

**NET_BUFFER_LIST_NEXT_NBL** gets the return value from the **Next** member of the [**NET_BUFFER_LIST_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_data) structure in the [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that the *\_NBL* parameter points to.

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[**NET_BUFFER_LIST_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_data)
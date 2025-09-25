## Description

**NET_BUFFER_LIST_CONTEXT_DATA_SIZE** is a macro that NDIS drivers use to get the size of the [**NET_BUFFER_LIST_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) data buffer that is associated with a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Syntax

```cpp
#define NET_BUFFER_LIST_CONTEXT_DATA_SIZE(_NBL) (((_NBL)->Context)->Size)
```

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_CONTEXT_DATA_SIZE** returns the size, in bytes, of the **NET_BUFFER_LIST_CONTEXT** data buffer that is associated with the indicated [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Remarks

**NET_BUFFER_LIST_CONTEXT_DATA_SIZE** gets the return value from the **Size** member of the first [**NET_BUFFER_LIST_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) structure.

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[**NET_BUFFER_LIST_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context)
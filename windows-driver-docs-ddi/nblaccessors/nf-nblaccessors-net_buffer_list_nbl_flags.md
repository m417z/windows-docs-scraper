# NET_BUFFER_LIST_NBL_FLAGS macro

## Description

The **NET_BUFFER_LIST_NBL_FLAGS** macro retrieves the **NblFlags** member of a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Syntax

```cpp
#define NET_BUFFER_LIST_NBL_FLAGS(_NBL) ((_NBL)->NblFlags)
```

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Remarks

NDIS network drivers should use the **NET_BUFFER_LIST_NBL_FLAGS** macro to get the **NblFlags** member of a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)
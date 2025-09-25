# NET_BUFFER_LIST_STATUS macro

## Description

**NET_BUFFER_LIST_STATUS** is a macro that NDIS drivers use to access the **StatusCode** member of a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Syntax

```cpp
#define NET_BUFFER_LIST_STATUS(_NBL) ((_NBL)->Status)
```

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_STATUS** returns the value of the **StatusCode** member of the indicated [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Remarks

Miniport drivers and NDIS intermediate drivers can use **StatusCode** for their own purposes.

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)
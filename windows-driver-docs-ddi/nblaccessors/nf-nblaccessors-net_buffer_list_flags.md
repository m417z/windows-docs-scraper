# NET_BUFFER_LIST_FLAGS macro

## Description

**NET_BUFFER_LIST_FLAGS** is a macro that NDIS drivers use to get the flags associated with a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Syntax

```cpp
#define NET_BUFFER_LIST_FLAGS(_NBL) ((_NBL)->Flags)
```

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_FLAGS** returns the **Flags** member of the indicated **NET_BUFFER_LIST** structure.

## Remarks

For definitions of possible **NET_BUFFER_LIST** structure flags, see [**NDIS_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list).

## See also

[**NDIS_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)
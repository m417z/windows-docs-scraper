# NET_BUFFER_LIST_MINIPORT_RESERVED macro

## Description

**NET_BUFFER_LIST_MINIPORT_RESERVED** is a macro that NDIS drivers use to access the **MiniportReserved** member of a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Syntax

```cpp
#define NET_BUFFER_MINIPORT_RESERVED(_NB) ((_NB)->MiniportReserved)
```

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_MINIPORT_RESERVED** returns a pointer to the start of the **MiniportReserved** member of the indicated [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Remarks

Miniport drivers and NDIS intermediate drivers can use **MiniportReserved** for their own purposes.

> [!NOTE]
> Only one driver can use **MiniportReserved** . Therefore, if another driver has used **MiniportReserved**, an intermediate driver cannot use it.

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)
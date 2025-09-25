# NET_BUFFER_MINIPORT_RESERVED macro

## Description

**NET_BUFFER_MINIPORT_RESERVED** is a macro that NDIS drivers use to access the **MiniportReserved** member of a [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Syntax

```cpp
#define NET_BUFFER_MINIPORT_RESERVED(_NB) ((_NB)->MiniportReserved)
```

## Parameters

### `_NB`

A pointer to a **NET_BUFFER** structure.

## Return value

**NET_BUFFER_MINIPORT_RESERVED** returns a pointer to the start of the **MiniportReserved** member of the specified [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Remarks

Miniport drivers and NDIS intermediate drivers can use **MiniportReserved** for their own purposes. Miniport drivers typically use **MiniportReserved** to maintain [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure context information for outstanding transfers.

> [!NOTE]
> Only one driver can use **MiniportReserved**. Therefore, if another driver has used **MiniportReserved**, an intermediate driver cannot use it.

## See also

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)
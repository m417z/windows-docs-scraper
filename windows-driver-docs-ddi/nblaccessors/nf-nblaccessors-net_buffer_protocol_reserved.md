# NET_BUFFER_PROTOCOL_RESERVED macro

## Description

**NET_BUFFER_PROTOCOL_RESERVED** is a macro that NDIS drivers use to get the **ProtocolReserved** member of a [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Syntax

```cpp
#define NET_BUFFER_PROTOCOL_RESERVED(_NB) ((_NB)->ProtocolReserved)
```

## Parameters

### `_NB`

A pointer to a **NET_BUFFER** structure.

## Return value

**NET_BUFFER_PROTOCOL_RESERVED** returns the value of the **ProtocolReserved** member of the specified [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Remarks

Protocol drivers and NDIS intermediate drivers can use this area for their own purposes. Protocol drivers typically use **ProtocolReserved** to maintain [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure context information for outstanding transfers.

> [!NOTE]
> Only one driver can use **ProtocolReserved**. Therefore, if another driver has used **ProtocolReserved**, an intermediate driver cannot use it.

## See also

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)
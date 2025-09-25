# NET_BUFFER_LIST_PROTOCOL_RESERVED macro

## Description

**NET_BUFFER_LIST_PROTOCOL_RESERVED** is a macro that NDIS drivers use to access the **ProtocolReserved** member of a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Syntax

```cpp
#define NET_BUFFER_PROTOCOL_RESERVED(_NB) ((_NB)->ProtocolReserved)
```

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_PROTOCOL_RESERVED** returns a pointer to the start of the **ProtocolReserved** member of the indicated [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Remarks

Protocol drivers and NDIS intermediate drivers can use **ProtocolReserved** for their own purposes.

> [!NOTE]
> Only one driver can use **ProtocolReserved** . Therefore, if another driver has used **ProtocolReserved**, an intermediate driver cannot use it.

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)
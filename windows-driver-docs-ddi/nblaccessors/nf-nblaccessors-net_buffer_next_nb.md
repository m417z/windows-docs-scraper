# NET_BUFFER_NEXT_NB macro

## Description

**NET_BUFFER_NEXT_NB** is a macro that NDIS drivers use to get a pointer to the next [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure in a linked list of **NET_BUFFER** structures.

## Syntax

```cpp
#define NET_BUFFER_NEXT_NB(_NB) ((_NB)->Next)
```

## Parameters

### `_NB`

A pointer to a **NET_BUFFER** structure.

## Return value

**NET_BUFFER_NEXT_NB** returns a pointer to the next [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure in the linked list of **NET_BUFFER** structures, or it returns **NULL** if the end of the linked list is reached.

## Remarks

**NET_BUFFER_NEXT_NB** gets the return value from the **Next** member of the [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## See also

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)
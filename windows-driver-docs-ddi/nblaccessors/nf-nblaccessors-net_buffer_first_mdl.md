# NET_BUFFER_FIRST_MDL macro

## Description

**NET_BUFFER_FIRST_MDL** is a macro that NDIS drivers use to get the first MDL in a [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Syntax

```cpp
#define NET_BUFFER_FIRST_MDL(_NB) ((_NB)->MdlChain)
```

## Parameters

### `_NB`

A pointer to a **NET_BUFFER** structure.

## Return value

**NET_BUFFER_FIRST_MDL** returns a pointer to the first MDL in a linked list of MDLs that is associated with the indicated [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Remarks

**NET_BUFFER_FIRST_MDL** gets the return value from the **MdlChain** member of the [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## See also

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)
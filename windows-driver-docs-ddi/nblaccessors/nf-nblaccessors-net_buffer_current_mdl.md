# NET_BUFFER_CURRENT_MDL macro

## Description

**NET_BUFFER_CURRENT_MDL** is a macro that NDIS drivers use to get the **CurrentMdl** member of a [**NET_BUFFER_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_data) structure in a [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Syntax

```cpp
#define NET_BUFFER_CURRENT_MDL(_NB) ((_NB)->CurrentMdl)
```

## Parameters

### `_NB`

A pointer to a **NET_BUFFER** structure.

## Return value

**NET_BUFFER_CURRENT_MDL** returns the value of the **CurrentMdl** member of the indicated [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Remarks

The return value is a pointer to the first MDL that the current driver is using. This pointer provides an optimization that improves performance by skipping over any MDLs that the current driver is not using.

## See also

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[**NET_BUFFER_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_data)
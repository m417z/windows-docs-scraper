# NET_BUFFER_CURRENT_MDL_OFFSET macro

## Description

**NET_BUFFER_CURRENT_MDL_OFFSET** is a macro that NDIS drivers use to get the **CurrentMdlOffset** member of a [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Syntax

```cpp
#define NET_BUFFER_CURRENT_MDL_OFFSET(_NB) ((_NB)->CurrentMdlOffset)
```

## Parameters

### `_NB`

A pointer to a **NET_BUFFER** structure.

## Return value

**NET_BUFFER_CURRENT_MDL_OFFSET** returns the value of the **CurrentMdlOffset** member of the indicated [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Remarks

The return value specifies the offset, in bytes, to the beginning of the used data space in the MDL that is specified by the **CurrentMdl** member of the [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## See also

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)
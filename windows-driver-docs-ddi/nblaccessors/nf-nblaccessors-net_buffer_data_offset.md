# NET_BUFFER_DATA_OFFSET macro

## Description

**NET_BUFFER_DATA_OFFSET** is a macro that NDIS drivers use to get the current offset from the beginning of the data space to the start of the *used data space* in a [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Syntax

```cpp
#define NET_BUFFER_DATA_OFFSET(_NB) ((_NB)->DataOffset)
```

## Parameters

### `_NB`

A pointer to a **NET_BUFFER** structure.

## Return value

**NET_BUFFER_DATA_OFFSET** returns the offset, in bytes, from the beginning of the data space to the start of the *used data space* of the indicated **NET_BUFFER** structure. This value also represents the size of the *unused data space* (available backfill).

## Remarks

**NET_BUFFER_DATA_OFFSET** gets the return value from the **DataOffset** member of the [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## See also

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)
# NET_BUFFER_DATA_LENGTH macro

## Description

**NET_BUFFER_DATA_LENGTH** is a macro that NDIS drivers use to get the amount of *used data space* in a [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Syntax

```cpp
#define NET_BUFFER_DATA_LENGTH(_NB) ((_NB)->DataLength)
```

## Parameters

### `_NB`

A pointer to a **NET_BUFFER** structure.

## Return value

**NET_BUFFER_DATA_LENGTH** returns the amount of *used data space* in a [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Remarks

**NET_BUFFER_DATA_LENGTH** gets the return value from the **DataLength** member of the [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## See also

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)
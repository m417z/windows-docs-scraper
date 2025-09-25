# NET_BUFFER_DATA_PHYSICAL_ADDRESS macro

## Description

The **NET_BUFFER_DATA_PHYSICAL_ADDRESS** macro retrieves the **DataPhysicalAddress** member of a [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Syntax

```cpp
#define NET_BUFFER_DATA_PHYSICAL_ADDRESS(_NB) ((_NB)->DataPhysicalAddress)
```

## Parameters

### `_NB`

A pointer to a **NET_BUFFER** structure.

## Return value

**NET_BUFFER_DATA_PHYSICAL_ADDRESS** returns the **DataPhysicalAddress** member of a [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Remarks

NDIS network drivers should use the **NET_BUFFER_DATA_PHYSICAL_ADDRESS** macro to get the **DataPhysicalAddress** member of a [**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## See also

[**NET_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)
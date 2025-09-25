# _SCATTER_GATHER_LIST structure

## Description

The **SCATTER_GATHER_LIST** structure describes the scatter/gather list for a DMA operation.

## Members

### `NumberOfElements`

Specifies the number of elements in the **Elements** array.

### `Reserved`

Reserved for future use.

### `Elements`

Specifies an array of scatter/gather elements that comprise a scatter/gather list. Each array element is a structure of type **SCATTER_GATHER_ELEMENT**, which is defined as follows:

```cpp
typedef struct _SCATTER_GATHER_ELEMENT {
  PHYSICAL_ADDRESS  Address;
  ULONG  Length;
  ULONG_PTR  Reserved;
} SCATTER_GATHER_ELEMENT, *PSCATTER_GATHER_ELEMENT;
```

The **SCATTER_GATHER_ELEMENT** structure specifies the length, in bytes, of a physically contiguous scatter/gather region and the starting physical address of this region.

## Remarks

For a driver that performs scatter/gather DMA, the [GetScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list) or [BuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list) routine creates a scatter/gather list and passes this list to the driver's [AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control) routine. This scatter/gather list consists of a **SCATTER_GATHER_LIST** structure that is immediately followed in memory by a **SCATTER_GATHER_ELEMENT** array. The number of elements in this array is specified by the **NumberOfElements** member of the **SCATTER_GATHER_LIST** structure.

For more information about scatter/gather lists, see [Using Scatter/Gather DMA](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-scatter-gather-dma).

## See also

[AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control)

[BuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list)

[GetScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list)
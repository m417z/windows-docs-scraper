# PCALCULATE_SCATTER_GATHER_LIST_SIZE callback function

## Description

The **CalculateScatterGatherList** routine calculates the size, in bytes, of scatter/gather list necessary to hold a given buffer.

## Parameters

### `DmaAdapter` [in]

Pointer to the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) that represents the bus-master adapter or DMA controller.

### `Mdl` [in, optional]

Either **NULL** or a pointer to the MDL that contains the buffer.

### `CurrentVa` [in]

Pointer to the virtual address of the beginning of the buffer.

### `Length` [in]

Specifies the length of the buffer, in bytes.

### `ScatterGatherListSize` [out]

Pointer to the variable the routine uses to return the size of the scatter/gather list, in bytes.

### `pNumberOfMapRegisters` [out, optional]

Either **NULL** or pointer to the variable the routine uses to return the number of map registers needed for DMA operations on the buffer.

## Return value

**CalculateScatterGatherList** returns one of the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The values returned in *ScatterGatherListSize* and *NumberOfMapRegisters* are valid. |
| **STATUS_INSUFFICIENT_RESOURCES** | The number of map registers required exceeds the number of map registers available. |
| **STATUS_BUFFER_TOO_SMALL** | The specified *Length* is too big to fit within the buffer. |

## Remarks

**CalculateScatterGatherList**
is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a
[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)
structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION2. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

If the caller passes **NULL** for the *Mdl* parameter, the routine calculates the maximum possible size needed to hold a scatter/gather list for the specified buffer. If the caller specifies the MDL that contains the buffer in the *Mdl* parameter, the routine computes the actual size needed to hold the scatter/gather list.

A driver uses **CalculateScatterGatherList** to allocate a scatter/gather list buffer to pass to [BuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list).

## See also

[BuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list)

[DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list)
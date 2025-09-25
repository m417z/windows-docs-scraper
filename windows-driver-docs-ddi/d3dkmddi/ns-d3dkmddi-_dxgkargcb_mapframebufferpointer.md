# DXGKARGCB_MAPFRAMEBUFFERPOINTER structure

## Description

The **DXGKARGCB_MAPFRAMEBUFFERPOINTER** structure contains arguments used by the [**DXGKCB_MAPFRAMEBUFFERPOINTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapframebufferpointer) callback function to map a frame buffer pointer.

## Members

### `PhysicalAdapterIndex` [in]

The index of the physical adapter.

### `Size` [in]

The size, in bytes, of the mapped subregion of the section object. **Size** must be a multiple of PAGE_SIZE.

### `Offset` [in/out]

On input, this is the offset, in bytes, to the mapped subregion of the section object. Offset must be a multiple of PAGE_SIZE. On output, this is the offset from the output base address to which the driver should copy the data.

### `pBaseAddress` [out]

A CPU accessible base address pointer to the mapped subregion of the section object. The driver must add the output **Offset** value to the base address to get the destination address of any copy operations (pDestinationAddress = pBaseAddress + Offset).

## Remarks

If pinning the entire frame buffer’s section object fails, the driver must try to ensure forward progress by performing the transfer in smaller pieces. This is accomplished by allocating a small MDL or chunk of memory during initialization time which can be used to transfer the contents from the hardware, and then calling **DXGKCB_MAPFRAMEBUFFERPOINTER** to obtain a pointer to a subregion of the section object.

The driver is responsible for copying the data from the pre-allocated buffer to the mapped subregion. The reverse is also true when restoring the frame buffer contents.

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKCB_MAPFRAMEBUFFERPOINTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapframebufferpointer)
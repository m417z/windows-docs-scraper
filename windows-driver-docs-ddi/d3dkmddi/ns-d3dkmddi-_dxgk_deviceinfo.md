# _DXGK_DEVICEINFO structure

## Description

The DXGK_DEVICEINFO structure describes parameters that the Microsoft DirectX graphics kernel subsystem requires from the display miniport driver.

## Members

### `DmaBufferSize` [out]

The size, in bytes, of the buffer of hardware commands that is sent through direct memory access (DMA) to the hardware.

The DMA buffer can grow and shrink after the device is created; however, the DMA buffer can never shrink smaller than the starting size that **DmaBufferSize** specifies.

### `DmaBufferSegmentSet` [out]

The identifiers of the segments where the DMA buffers should be made accessible to the graphics processing unit (GPU).

### `DmaBufferPrivateDataSize` [out]

The size, in bytes, of the driver-resident private data structure that is associated with each DMA buffer. Memory for this private data structure is allocated from nonpaged pool. If the driver specifies zero in **DmaBufferPrivateDataSize**, no memory is allocated for the private data structure.

The private data structure that is associated with a DMA buffer is initialized to zero when the DMA buffer is created. During the lifetime of the DMA buffer, the video memory manager never accesses the private data structure that is associated with the DMA buffer.

### `AllocationListSize` [out]

The starting number of elements in an array of allocations (that is, an array of [DXGK_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationlist) structures). This number is the starting number of allocations that the driver requests to be in the **pAllocationList** members of [DXGKARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present) and [DXGKARG_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_render) structures in calls to the driver's [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) and [DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render) functions.

The allocation list can grow and shrink after the device is created; however, the allocation list can never shrink smaller than the starting size that **AllocationListSize** specifies.

### `PatchLocationListSize` [out]

The starting number of elements in an array of patch locations (that is, an array of [D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist) structures) for the device in user mode and kernel mode. This number is the starting number of patch locations that the driver requests to be in the **pPatchLocationListIn** members of [DXGKARG_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_render) structures in calls to its [DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render) function.

The patch-location list can grow and shrink after the device is created; however, the patch-location list can never shrink smaller than the starting size that **PatchLocationListSize** specifies.

### `Flags` [out]

A [DXGK_DEVICEINFOFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_deviceinfoflags) structure that identifies, in bit-field flags, information about the device.

## Remarks

The display miniport driver specifies values for the **DmaBufferSize** and **AllocationListSize** members to guarantee the following:

* The DirectX graphics subsystem can use only one DMA buffer to display (by using the display miniport driver's [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) function) at least one [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure for all scenarios.
* The sizes of DMA and allocation-list buffers are large enough to hold at least one command that cannot be split across multiple buffers.
* The sizes of DMA and allocation-list buffers are large enough to avoid setup and DMA overhead.

The display miniport driver can specify only aperture segments in the **DmaBufferSegmentSet** member; if the driver specifies a memory segment, a device-creation failure occurs.

If the driver sets **DmaBufferSegmentSet** to 0, the video memory manager allocates contiguous paged-locked memory, which is mapped write-combined memory, for the DMA buffers. Therefore, the GPU must access DMA buffers by using PCI cycles on systems where AGP transfers that occur outside the AGP aperture are not permitted.

## See also

[D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist)

[DXGKARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present)

[DXGKARG_RENDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_render)

[DXGK_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationlist)

[DXGK_DEVICEINFOFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_deviceinfoflags)

[DxgkDdiCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice)

[DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present)

[DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render)
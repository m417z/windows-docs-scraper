# DXGKARGCB_MAPCONTEXTALLOCATION structure

## Description

The **DXGKARGCB_MAPCONTEXTALLOCATION** structure contains the arguments used in the [**DXGKCB_MAPCONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapcontextallocation) callback function, to map a graphics processing unit (GPU) virtual address to the specified context allocation.

## Members

### `BaseAddress` [in]

(optional) If non-NULL, the video memory manager will attempt to use this address as the base address for the mapping. If the range from **BaseAddress** to **BaseAddress**+**Size** isn’t free, the call will fail. When this parameter is non-NULL, **MinimumAddress** and **MaximumAddress** are ignored.

If NULL is specified, the video memory manager will pick the base address for the allocation within the specified **MinimumAddress** and **MaximumAddress**.

### `MinimumAddress` [in]

(optional) The minimum GPU virtual address to consider for the mapped range. This parameter is ignored when **BaseAddress** != **NULL**.

### `MaximumAddress` [in]

The maximum GPU virtual address to consider for the mapped range. The video memory manager will guarantee that **BaseAddress**+**Size** <= **MaximumAddress**. If this is set to **NULL** the video memory manager will not apply any limit. This parameter is ignored when **BaseAddress** != **NULL**.

### `hAllocation` [in]

Handle to the allocation being mapped into the GPU virtual address space. This is a DirectX graphics kernel handle, returned by [**DXGKCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation).

### `OffsetInPages` [in]

The offset, in 4KB pages, to the starting page within the specified allocation that must be mapped.

### `SizeInPages` [in]

The size of the range to map in number of 4KB pages.

### `Protection` [in]

The protection on the GPU virtual address that is mapped.

### `DriverProtection` [in]

The driver protection parameters.

## See also

[**DXGKCB_CREATECONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation)

[**DXGKCB_MAPCONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapcontextallocation)
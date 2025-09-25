# DXGKCB_MAPCONTEXTALLOCATION callback function

## Description

A kernel-mode display miniport driver calls **DXGKCB_MAPCONTEXTALLOCATION** to map a graphics processing unit (GPU) virtual address to the specified context allocation.

## Parameters

### `hAdapter` [in]

A handle to the display adapter.

### `pArgs` [in]

Pointer to a [**DXGKARGCB_MAPCONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_mapcontextallocation) structure that describes the operation.

## Return value

**DXGKCB_MAPCONTEXTALLOCATION** returns a **D3DGPU_VIRTUAL_ADDRESS** if successful, NULL otherwise.

## Remarks

This device driver interface (DDI) behaves like its user-mode counterpart; see [**pfnMapGpuVirtualAddressCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_mapgpuvirtualaddresscb) for more details.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_MAPCONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_mapcontextallocation) and then call **DxgkCbMapContextAllocation** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_MAPCONTEXTALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_mapcontextallocation)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)

[**pfnMapGpuVirtualAddressCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_mapgpuvirtualaddresscb)
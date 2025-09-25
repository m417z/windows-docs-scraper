## Description

The **DXGK_QUERYSCATTERRESERVEOUT** structure contains the output parameters (**pOutputData**) for a [**DxgkDdiQueryAdaptedInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) call with a **Type** of **DXGKQAITYPE_SCATTER_RESERVE**.

## Members

### `SetVGPUResourcesPageSize`

The page size of the 2nd phase of GPU-VA translation available on the hardware, in bytes. The driver must specify a page size that aligns with the reserve physical assignments (partition VRAM sizes and offsets are multiples of this page size).

## Remarks

For more information, see [Live migration on GPU-P devices](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)
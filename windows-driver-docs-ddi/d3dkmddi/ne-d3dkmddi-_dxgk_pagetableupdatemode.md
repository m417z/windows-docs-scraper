# _DXGK_PAGETABLEUPDATEMODE enumeration

## Description

**DXGK_PAGETABLEUPDATEMODE** is used as part of a [DxgkDdiBuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) operation to indicate which member of the related [DXGK_PAGETABLEUPDATEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_pagetableupdateaddress) structure contains the address of the page table to update.

## Constants

### `DXGK_PAGETABLEUPDATE_CPU_VIRTUAL`

Indicates that the address of the page table to update is in the **CpuVirtual** member of the [DXGK_PAGETABLEUPDATEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_pagetableupdateaddress) structure.

### `DXGK_PAGETABLEUPDATE_GPU_VIRTUAL`

Indicates that the address of the page table to update is in the **GpuVirtual** member of the [DXGK_PAGETABLEUPDATEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_pagetableupdateaddress) structure.

### `DXGK_PAGETABLEUPDATE_GPU_PHYSICAL`

Indicates that the address of the page table to update is in the **GpuPhysical** member of the [DXGK_PAGETABLEUPDATEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_pagetableupdateaddress) structure.

## See also

[DXGK_PAGETABLEUPDATEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_pagetableupdateaddress)

[DxgkDdiBuildPagingBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer)
# _DXGK_CREATECONTEXTALLOCATIONFLAGS structure

## Description

Specifies the properties of the context to be allocated.

## Members

### `SharedAcrossContexts` [in]

A UINT value that specifies the association of the context.

If **SharedAcrossContexts** is set to one, the allocation is associated with all contexts specified by the **hDevice** member of the [DXGKARGCB_CREATECONTEXTALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_createcontextallocation) structure. The allocated context will be made resident when any context that belongs to **hDevice** is
scheduled to run on the GPU.

If **SharedAcrossContexts** is set to zero, the allocation is associated with the context specified by the **hContext** member of the [DXGKARGCB_CREATECONTEXTALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_createcontextallocation) structure. The allocated context will be made resident when **hContext** is scheduled to run on the GPU.

### `MapGpuVirtualAddress`

### `Reserved` [in]

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the most significant 31 bits (0xFFFFFFFE) to zeros.

### `Value` [in]

A 32-bit value that specifies the context allocation flags.

## Remarks

The display miniport driver allocates GPU contexts or device-specific contexts by calling [DxgkCbCreateContextAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation).

The **ContextAllocationFlags** member of the [DXGKARGCB_CREATECONTEXTALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_createcontextallocation) structure is an **DXGK_CREATECONTEXTALLOCATIONFLAGS** data type.

## See also

[DXGKARGCB_CREATECONTEXTALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_createcontextallocation)

[DxgkCbCreateContextAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_createcontextallocation)
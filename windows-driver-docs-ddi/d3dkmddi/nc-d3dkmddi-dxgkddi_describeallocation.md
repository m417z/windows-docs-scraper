# DXGKDDI_DESCRIBEALLOCATION callback function

## Description

The *DxgkDdiDescribeAllocation* function retrieves information about an existing allocation that is not otherwise available to the Microsoft DirectX graphics kernel subsystem.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pDescribeAllocation` [in/out]

A pointer to a [DXGKARG_DESCRIBEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_describeallocation) structure that describes an existing allocation.

## Return value

*DxgkDdiDescribeAllocation* returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

Because the DirectX graphics kernel subsystem does not necessarily maintain records of allocations, the graphics kernel subsystem calls *DxgkDdiDescribeAllocation* to request that the display miniport driver return information about existing allocations. Currently, the display miniport driver must be able to return this information for the following allocations:

* Allocations that are also primaries (that is, allocations that the user-mode display driver created by setting the **Primary** bit-field flag in the **Flags** member of the [D3DDDI_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo) structure in a call to the [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function).
* Allocations that might be the source of a presentation (that is, allocations that are represented by the **hSource** member of the [DXGKARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present) structure in a call to the display miniport driver's [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) function).

*DxgkDdiDescribeAllocation* should be made pageable.

## See also

[D3DDDI_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo)

[DXGKARG_DESCRIBEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_describeallocation)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present)

[pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb)
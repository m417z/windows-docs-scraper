# DXGKDDI_GETSTANDARDALLOCATIONDRIVERDATA callback function

## Description

The **DxgkDdiGetStandardAllocationDriverData** function returns a description of a standard allocation type.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The kernel-mode display driver (KMD) previously provided this handle to *Dxgkrnl* in its [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pGetStandardAllocationDriverData` [in/out]

A pointer to a[**DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_getstandardallocationdriverdata) structure that describes a standard allocation.

## Return value

**DxgkDdiGetStandardAllocationDriverData** returns one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | **DxgkDdiGetStandardAllocationDriverData** successfully returned a description of the standard allocation type.|
| STATUS_NO_MEMORY | **DxgkDdiGetStandardAllocationDriverData** couldn't allocate memory that was required for it to complete.|

## Remarks

*Standard allocation types* are allocations that must be created in kernel mode without communication from the user-mode display driver.

*Dxgkrnl* calls the kernel mode driver's (KMD's) **DxgkDdiGetStandardAllocationDriverData** function to generate a description of the standard allocation type that the **pGetStandardAllocationDriverData** parameter specifies. KMD returns the description of the allocation type in the **pAllocationPrivateDriverData** and **pResourcePrivateDriverData** members of the [**DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_getstandardallocationdriverdata) structure that the **pGetStandardAllocationDriverData** parameter points to. *Dxgkrnl* subsequently passes the description to the [**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function to actually create the allocation.

Beginning with Windows 7, if KMD processes a call to the **DxgkDdiGetStandardAllocationDriverData** function to create allocations for GDI hardware acceleration, the driver should set the pitch of the allocation for CPU visible allocations, **pGetStandardAllocationDriverData->pCreateGdiSurfaceData->Pitch**.

**DxgkDdiGetStandardAllocationDriverData** should be made pageable.

## See also

[**DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_getstandardallocationdriverdata)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)
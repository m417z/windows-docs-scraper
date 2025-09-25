# DXGKDDI_DESTROYCONTEXT callback function

## Description

The *DxgkDdiDestroyContext* function destroys the specified graphics processing unit (GPU) context.

## Parameters

### `hContext` [in]

A handle to the context to destroy. The display miniport driver's [DxgkDdiCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext) function previously returned this handle in the **hContext** member of the [DXGKARG_CREATECONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createcontext) structure that the *pCreateContext* parameter of *DxgkDdiCreateContext* points to.

## Return value

*DxgkDdiDestroyContext* returns STATUS_SUCCESS, or an appropriate error result if the context is not successfully destroyed.

## Remarks

A driver should free all resources that it allocated for the context and clean up any internal tracking data structures.

*DxgkDdiDestroyContext* should be made pageable.

## See also

[DXGKARG_CREATECONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createcontext)

[DxgkDdiCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext)
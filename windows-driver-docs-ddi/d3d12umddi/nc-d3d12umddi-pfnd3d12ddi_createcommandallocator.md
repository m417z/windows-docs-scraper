# PFND3D12DDI_CREATECOMMANDALLOCATOR callback function

## Description

The user-mode display driver's (UMD) **pfnCreateCommandAllocator** function creates a command allocator.

## Parameters

### `unnamedParam1`

[in] A handle to the display device (graphics context).

### `unnamedParam2`

[in] Pointer to a [**D3D12DDIARG_CREATECOMMANDALLOCATOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createcommandallocator) structure that describes the command allocator to create.

## Return value

**pfnCreateCommandAllocator** returns an HRESULT value.

## Remarks

The command allocator corresponds to the underlying allocations in which GPU command lists are stored. It applies to both direct and bundle command lists.

## See also

[**D3D12DDIARG_CREATECOMMANDALLOCATOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createcommandallocator)

[**pfnCalcPrivateCommandAllocatorSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatecommandallocatorsize)

[**pfnDestroyCommandAllocator**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_destroycommandallocator)

[**pfnResetCommandAllocator**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_resetcommandallocator)
# DXGKDDI_CREATEVIRTUALGPU callback function

## Description

This function creates a virtual GPU with provided parameters and re-tunes information about physical GPU resources, which are needed for the virtual GPU.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_GPU_PARTITION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_gpu_partition_interface) structure.

### `pArgs` [in]

Pointer to a [DXGKARG_CREATEVIRTUALGPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkarg_createvirtualgpu) structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_CREATEVIRTUALGPU DxgkddiCreatevirtualgpu;

// Definition

NTSTATUS DxgkddiCreatevirtualgpu
(
	HANDLE Context
	DXGKARG_CREATEVIRTUALGPU * pArgs
)
{...}

```

## Remarks

## See also
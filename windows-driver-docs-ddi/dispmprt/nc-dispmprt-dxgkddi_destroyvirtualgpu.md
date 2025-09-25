# DXGKDDI_DESTROYVIRTUALGPU callback function

## Description

The DxgkDdiDestroyVirtualGpu function destroys a previously created virtual GPU.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_GPU_PARTITION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_gpu_partition_interface) structure.

### `pArgs` [in]

Pointer to a [DXGKARG_DESTROYVIRTUALGPU](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkarg_destroyvirtualgpu) structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_DESTROYVIRTUALGPU DxgkddiDestroyvirtualgpu;

// Definition

NTSTATUS DxgkddiDestroyvirtualgpu
(
	HANDLE Context
	DXGKARG_DESTROYVIRTUALGPU * pArgs
)
{...}

```

## Remarks

## See also
# DXGKDDI_SUSPENDVIRTUALGPU callback function

## Description

> [!NOTE]
> Virtual GPU suspend/resume is not supported. This callback function is never used.

This function suspends execution of all engines and operation of the given virtual GPU. The video memory must not be touched after this point.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_GPU_PARTITION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_gpu_partition_interface) structure.

### `pArgs` [in]

A pointer to a DXGKARG_SUSPENDVIRTUALGPU structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_SUSPENDVIRTUALGPU DxgkddiSuspendvirtualgpu;

// Definition

NTSTATUS DxgkddiSuspendvirtualgpu
(
	HANDLE Context
	DXGKARG_SUSPENDVIRTUALGPU * pArgs
)
{...}

```

## Remarks

## See also
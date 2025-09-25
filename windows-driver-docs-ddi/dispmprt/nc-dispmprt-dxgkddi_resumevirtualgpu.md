# DXGKDDI_RESUMEVIRTUALGPU callback function

## Description

> [!NOTE]
> Virtual GPU suspend/resume is not supported. This callback function is never used.

Resumes execution of processing engines of the given virtual GPU.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_GPU_PARTITION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_gpu_partition_interface) structure.

### `pArgs` [in]

A pointer to a DXGKARG_RESUMEVIRTUALGPU structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_RESUMEVIRTUALGPU DxgkddiResumevirtualgpu;

// Definition

NTSTATUS DxgkddiResumevirtualgpu
(
	HANDLE Context
	DXGKARG_RESUMEVIRTUALGPU * pArgs
)
{...}

```

## Remarks

## See also
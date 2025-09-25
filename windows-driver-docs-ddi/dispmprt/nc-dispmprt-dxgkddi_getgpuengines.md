# DXGKDDI_GETGPUENGINES callback function

## Description

This function is no longer used and maybe be deleted in the near future. It is currently required, but will never be called.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_GPU_PARTITION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_gpu_partition_interface) structure.

### `pArgs` [in]

A pointer to the DXGKARG_GETGPUENGINES structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_GETGPUENGINES DxgkddiGetgpuengines;

// Definition

NTSTATUS DxgkddiGetgpuengines
(
	HANDLE Context
	DXGKARG_GETGPUENGINES * pArgs
)
{...}

```

## Remarks

## See also
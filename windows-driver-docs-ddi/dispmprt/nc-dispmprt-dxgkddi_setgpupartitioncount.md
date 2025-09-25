# DXGKDDI_SETGPUPARTITIONCOUNT callback function

## Description

Sets the number of partitions the physical GPU should be divided into. The OS guarantees that at this point there are no existing vGPUs on the physical GPU.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_GPU_PARTITION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_gpu_partition_interface) structure.

### `pArgs` [in]

A pointer to a DXGKARG_SETGPUPARTITIONCOUNT structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_SETGPUPARTITIONCOUNT DxgkddiSetgpupartitioncount;

// Definition

NTSTATUS DxgkddiSetgpupartitioncount
(
	HANDLE Context
	DXGKARG_SETGPUPARTITIONCOUNT * pArgs
)
{...}

```

## Remarks

## See also
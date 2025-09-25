# DXGKDDI_GETVIRTUALGPUINFO callback function

## Description

Queries the current capability of a previously created vGPU.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_GPU_PARTITION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_gpu_partition_interface) structure.

### `pArgs` [in, out]

A pointer to a DXGKARG_GETVIRTUALGPUINFO structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_GETVIRTUALGPUINFO DxgkddiGetvirtualgpuinfo;

// Definition

NTSTATUS DxgkddiGetvirtualgpuinfo
(
	HANDLE Context
	DXGKARG_GETVIRTUALGPUINFO * pArgs
)
{...}

```

## Remarks

## See also
# DXGKDDI_GETVIRTUALGPUPROFILE callback function

## Description

Returns information about the vGPU profile, which is supported by the physical GPU when it is divided into given number of partitions. This function could be called multiple times to get current vGPU capabilities.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_GPU_PARTITION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_gpu_partition_interface) structure.

### `pArgs` [in, out]

A pointer to the DXGKARG_GETVIRTUALGPUPROFILE structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_GETVIRTUALGPUPROFILE DxgkddiGetvirtualgpuprofile;

// Definition

NTSTATUS DxgkddiGetvirtualgpuprofile
(
	HANDLE Context
	DXGKARG_GETVIRTUALGPUPROFILE * pArgs
)
{...}

```

## Remarks

## See also
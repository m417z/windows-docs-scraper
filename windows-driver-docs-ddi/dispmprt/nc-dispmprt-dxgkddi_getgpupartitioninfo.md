# DXGKDDI_GETGPUPARTITIONINFO callback function

## Description

Returns physical GPU partition information. The DXGKDDI_GETGPUPARTITIONINFO callback function is called once during the graphics adapter initialization.

## Parameters

### `Context`

A handle to the driver context.

### `pArgs`

Pointer to a DXGKARG_GETGPUPARTITIONINFO structure that contains arguments.

## Return value

Return one of the following values:

* STATUS_SUCCESS
* STATUS_BUFFER_TOO_SMALL
* If any other return code is specified the GPU will be excluded from partitioning

## Prototype

```
//Declaration

DXGKDDI_GETGPUPARTITIONINFO DxgkddiGetgpupartitioninfo;

// Definition

NTSTATUS DxgkddiGetgpupartitioninfo
(
	HANDLE Context
	DXGKARG_GETGPUPARTITIONINFO * pArgs
)
{...}

```

## Remarks

The OS will set a particular partition count (one of the driver returned values) before a first vGPU is created. Unless the buffer is not large enough, a driver should always set NumGpuPartitionOptions and CurrentGpuPartitionCount, even when returning STATUS_BUFFER_TOO_SMALL.

## See also
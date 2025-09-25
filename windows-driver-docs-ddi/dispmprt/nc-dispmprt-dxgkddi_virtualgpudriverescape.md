# DXGKDDI_VIRTUALGPUDRIVERESCAPE callback function

## Description

This function passes information between a user mode emulation DLL and the kernel mode driver. This function is called in response to IOCTL_GPUP_DRIVER_ESCAPE.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_GPU_PARTITION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_gpu_partition_interface) structure.

### `pArgs` [in, out]

A pointer to a DXGK_VIRTUALGPUDRIVERESCAPE structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_VIRTUALGPUDRIVERESCAPE DxgkddiVirtualgpudriverescape;

// Definition

NTSTATUS DxgkddiVirtualgpudriverescape
(
	HANDLE Context
	PDXGK_VIRTUALGPUDRIVERESCAPE pArgs
)
{...}

```

## Remarks

## See also
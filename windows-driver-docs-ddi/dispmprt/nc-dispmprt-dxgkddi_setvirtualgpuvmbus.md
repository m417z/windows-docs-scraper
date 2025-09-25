# DXGKDDI_SETVIRTUALGPUVMBUS callback function

## Description

This function passes a kernel mode virtual machine bus handle to the kernel mode driver. The handle is used to create VM bus channels for communication between guest and host KMDs.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_GPU_PARTITION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_gpu_partition_interface) structure.

### `pArgs` [in, out]

A pointer to a DXGKARG_SETVIRTUALGPUVMBUS structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds, STATUS_INVALID_PARAMETER otherwise.

## Prototype

```
//Declaration

DXGKDDI_SETVIRTUALGPUVMBUS DxgkddiSetvirtualgpuvmbus;

// Definition

NTSTATUS DxgkddiSetvirtualgpuvmbus
(
	HANDLE Context
	DXGKARG_SETVIRTUALGPUVMBUS * pArgs
)
{...}

```

## Remarks

The kernel mode driver uses the kernel mode handle to create a VM bus channel. The function is called before the guest KMD gets DxgkDdiAddDevice and DxgkDdiStartDevice calls (in case of Windows OS on the guest partition). The function could be called multiple times with a new handle for the same virtual GPU. When this happened it is recommended to destroy the old channel and create the new one.

## See also
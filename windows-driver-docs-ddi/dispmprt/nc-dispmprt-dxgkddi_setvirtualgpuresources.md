# DXGKDDI_SETVIRTUALGPURESOURCES callback function

## Description

This function assigns physical resources capabilities to a virtual GPU. The function is called before setting the virtual GPU to the D0 state.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_GPU_PARTITION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_gpu_partition_interface) structure.

### `pArgs` [in]

A pointer to a DXGKARG_SETVIRTUALGPURESOURCES structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_SETVIRTUALGPURESOURCES DxgkddiSetvirtualgpuresources;

// Definition

NTSTATUS DxgkddiSetvirtualgpuresources
(
	HANDLE Context
	DXGKARG_SETVIRTUALGPURESOURCES * pArgs
)
{...}

```

## Remarks

Remapping of vGPUs is not currently supported.

## See also
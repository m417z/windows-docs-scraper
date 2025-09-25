# DXGKDDI_RESETVIRTUALFUNCTION callback function

## Description

This routine allows the virtualized I/O management software running in the privileged virtual machine to reset a specific virtual function.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_SRIOV_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_sriov_interface) structure.

### `pArgs` [in, out]

A pointer to a DXGKARG_RESETVIRTUALFUNCTION structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_RESETVIRTUALFUNCTION DxgkddiResetvirtualfunction;

// Definition

NTSTATUS DxgkddiResetvirtualfunction
(
	HANDLE Context
	DXGKARG_RESETVIRTUALFUNCTION * pArgs
)
{...}

```

## Remarks

## See also
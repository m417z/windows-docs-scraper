# DXGKDDI_WRITEVIRTUALFUNCTIONCONFIGBLOCK callback function

## Description

This function allows the non-privileged virtual machine to write configuration data supplied by the Physical Function driver in the privileged VM. This is used by the VFs in order to write configuration block data to the PF. This function is only required if the guest VF driver expects it.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_SRIOV_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_sriov_interface) structure.

### `pArgs` [in]

A pointer to a DXGKARG_WRITEVIRTUALFUNCTIONCONFIGBLOCK structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_WRITEVIRTUALFUNCTIONCONFIGBLOCK DxgkddiWritevirtualfunctionconfigblock;

// Definition

NTSTATUS DxgkddiWritevirtualfunctionconfigblock
(
	HANDLE Context
	DXGKARG_WRITEVIRTUALFUNCTIONCONFIGBLOCK * pArgs
)
{...}

```

## Remarks

## See also
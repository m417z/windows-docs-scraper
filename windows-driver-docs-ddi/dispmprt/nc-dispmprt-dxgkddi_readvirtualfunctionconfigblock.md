# DXGKDDI_READVIRTUALFUNCTIONCONFIGBLOCK callback function

## Description

This routine supplies the non-privileged virtual machine (VM) with configuration data supplied by the Physical Function driver in the privileged VM. This is used by the virtual functions (VF) in order to read predefined configuration blocks from the PF. This function is only required if the guest VF driver expects it.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_SRIOV_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_sriov_interface) structure.

### `pArgs` [in, out]

A pointer to the DXGKARG_READVIRTUALFUNCTIONCONFIGBLOCK structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_READVIRTUALFUNCTIONCONFIGBLOCK DxgkddiReadvirtualfunctionconfigblock;

// Definition

NTSTATUS DxgkddiReadvirtualfunctionconfigblock
(
	HANDLE Context
	DXGKARG_READVIRTUALFUNCTIONCONFIGBLOCK * pArgs
)
{...}

```

## Remarks

## See also
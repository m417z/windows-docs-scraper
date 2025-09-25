# DXGKDDI_SETVIRTUALFUNCTIONPOWERSTATE callback function

## Description

This routine allows a non-privileged virtual machine to change the power state of a PCI Express SR-IOV Virtual Function.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_SRIOV_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_sriov_interface) structure.

### `pArgs` [in]

A pointer to a DXGKARG_SETVIRTUALFUNCTIONPOWERSTATE structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_SETVIRTUALFUNCTIONPOWERSTATE DxgkddiSetvirtualfunctionpowerstate;

// Definition

NTSTATUS DxgkddiSetvirtualfunctionpowerstate
(
	HANDLE Context
	DXGKARG_SETVIRTUALFUNCTIONPOWERSTATE * pArgs
)
{...}

```

## Remarks

When all vGPUs are in a D3 state and if the Host doesn’t need the GPU, the physical GPU will be put into a D3 Cold state in which case the PF and all of the VF will become inaccessible until the GPU is powered up again. Upon power up we expect the same PF/VF configuration to be in effect as before the power down.

## See also
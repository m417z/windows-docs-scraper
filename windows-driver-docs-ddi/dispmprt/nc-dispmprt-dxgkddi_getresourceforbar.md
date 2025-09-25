# DXGKDDI_GETRESOURCEFORBAR callback function

## Description

If the driver does not support the GUID_DXGKDDI_FLEXIOV_DEVICE_INTERFACE interface, this routine returns the host partition base address of a single Virtual Function base address register. This host physical address should be the beginning of the MMIO (Memory management input output) space that the driver wants to be mapped as the GPU partition’s MMIO bar.

When the driver report that it does support the GUID_DXGKDDI_FLEXIOV_DEVICE_INTERFACE interface, this function will not be called.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_SRIOV_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_sriov_interface) structure.

### `pArgs` [in, out]

A pointer to the DXGKARG_GETRESOURCEFORBAR that contains arguments for this function.

## Return value

If the VF has resources at this BarIndex and can return the information correct, the statement NT_SUCCESS(return value) will be true.

## Prototype

```
//Declaration

DXGKDDI_GETRESOURCEFORBAR DxgkddiGetresourceforbar;

// Definition

NTSTATUS DxgkddiGetresourceforbar
(
	HANDLE Context
	DXGKARG_GETRESOURCEFORBAR * pArgs
)
{...}

```

## Remarks

This routine can fail if the VF does not expose a BAR at BarIndex. This is expected and will not cause an immediate failure.

## See also
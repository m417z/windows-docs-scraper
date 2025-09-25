# DXGKDDI_GETVENDORANDDEVICE callback function

## Description

This routine supplies the Vendor and Device IDs for a PCI Express SR-IOV Virtual Function (VF) to be used as the basis for the more generic Plug and Play IDs for the VF. These can’t be read directly from the VF’s configuration space.

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_SRIOV_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_sriov_interface) structure.

### `pArgs` [in, out]

A pointer to the DXGKARG_GETVENDORANDDEVICE structure.

## Prototype

```
//Declaration

DXGKDDI_GETVENDORANDDEVICE DxgkddiGetvendoranddevice;

// Definition

VOID DxgkddiGetvendoranddevice
(
	HANDLE Context
	DXGKARG_GETVENDORANDDEVICE * pArgs
)
{...}

```

## Remarks

## See also
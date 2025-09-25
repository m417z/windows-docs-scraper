# DXGKDDI_QUERYPROBEDBARS callback function

## Description

This routine allows a non-privileged virtual machine to find out what would have been read from a Virtual Function’s Base Address Registers after they had been written with the value (-1).

## Parameters

### `Context` [in]

The miniport context that is returned by the driver in the [DXGKDDI_SRIOV_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_sriov_interface) structure.

### `pArgs` [in, out]

Pointer to the DXGKARG_QUERYPROBEDBARS structure.

## Prototype

```
//Declaration

DXGKDDI_QUERYPROBEDBARS DxgkddiQueryprobedbars;

// Definition

VOID DxgkddiQueryprobedbars
(
	HANDLE Context
	DXGKARG_QUERYPROBEDBARS * pArgs
)
{...}

```

## Remarks

This is part of the normal process of setting up a PCI device, and the result allows the PCI driver to know how much address space would be decoded by the device after it was enabled. Because writing -1 to the physical BARS could be considered a security risk, this step of PCI enumeration is emulated.

## See also
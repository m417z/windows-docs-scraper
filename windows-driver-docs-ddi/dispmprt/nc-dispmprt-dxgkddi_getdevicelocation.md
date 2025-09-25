# DXGKDDI_GETDEVICELOCATION callback function

## Description

Returns the location of a Virtual Function on the PCI bus relative to the root partition. If an IHV implementation does not support SR-IOV, the location of the physical function is returned.

## Parameters

### `Context`

The miniport context that is returned by the driver in the [DXGKDDI_SRIOV_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_sriov_interface) structure.

### `pArgs`

Pointer to the DXGKARG_GETDEVICELOCATION structure.

## Prototype

```
//Declaration

DXGKDDI_GETDEVICELOCATION DxgkddiGetdevicelocation;

// Definition

VOID DxgkddiGetdevicelocation
(
	HANDLE Context
	DXGKARG_GETDEVICELOCATION * pArgs
)
{...}

```

## Remarks

VF indices are incrementing, but the bus location is not directly tied to the index. This function retrieves the actual PCIe bus location of a virtual function.

## See also
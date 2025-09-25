# DXGKDDI_QUERYMITIGATEDRANGES callback function

## Description

This function is called from the virtual PCI system to the kernel mode driver to get the list of pages in the virtual function’s BARs that need to be mitigated.

## Parameters

### `Context`

The miniport context that is returned by the driver in the [DXGKDDI_GPU_PARTITION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_gpu_partition_interface) structure.

### `pArgs`

Pointer to the DXGKARG_QUERYMITIGATEDRANGES structure.

## Return value

Return STATUS_SUCCESS if the operation succeeds.

## Prototype

```
//Declaration

DXGKDDI_QUERYMITIGATEDRANGES DxgkddiQuerymitigatedranges;

// Definition

NTSTATUS DxgkddiQuerymitigatedranges
(
	HANDLE Context
	DXGKARG_QUERYMITIGATEDRANGES * pArgs
)
{...}

```

## Remarks

This function returns the map of valid hardware pages to exclude from the virtual device exposed in the guest partition. Each base address register will be queried separately. These pages will never be exposed in the guest partition. Any operation on these pages by the guest VM will instead cause a trap into the user mode COM device driver.

## See also
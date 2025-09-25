# DXGKDDI_QUERYMITIGATEDRANGECOUNT callback function

## Description

This function is called to get the count of the number of ranges per BAR that need to be mitigated (trapped and re-redirected to the user mode emulation DLL).

## Parameters

### `Context`

The miniport context that is returned by the driver in the [DXGKDDI_GPU_PARTITION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkddi_gpu_partition_interface) structure.

### `pArgs`

A pointer to the DXGKARG_QUERYMITIGATEDRANGECOUNT structure.

## Prototype

```
//Declaration

DXGKDDI_QUERYMITIGATEDRANGECOUNT DxgkddiQuerymitigatedrangecount;

// Definition

VOID DxgkddiQuerymitigatedrangecount
(
	HANDLE Context
	DXGKARG_QUERYMITIGATEDRANGECOUNT * pArgs
)
{...}

```

## Remarks

## See also
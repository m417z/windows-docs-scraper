# DXGKDDI_GETMMIORANGES callback function

## Description

Get the memory ranges for a single MMIO (memory mapped input output) BAR (base address register) in the virtual device.

## Parameters

### `Context`

A handle to the device context.

### `pArgs`

Pointer to a [DXGKARG_GETMMIORANGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkarg_getmmioranges) structure.

## Return value

Returns:

* STATUS_SUCCESS The IHV system did not encounter any errors.
* STATUS_INVALID_DEVICE_REQUEST The virtual device encountered an error and should be forcibly stopped. Failure here will cause virtual device failure.
* BUFFER_TO_SMALL may result in this being called again with a larger buffer.

## Prototype

```cpp
//Declaration

DXGKDDI_GETMMIORANGES DxgkddiGetmmioranges;

// Definition

NTSTATUS DxgkddiGetmmioranges
(
	HANDLE Context
	PDXGKARG_GETMMIORANGES pArgs
)
{...}

```

## Remarks

This callback function gets the specific ranges on which intercepts and mapping must be placed. This is a more flexible scatter/gather mapping of the BARs than the general SR-IOV (single-root input/output virtualization) solution that allows for VF (virtual function) BARS (base address registers) to be different sized than the physical bars and map/emulate any order of pages from any physical bar to any virtual bar. This function MUST contain a mapping for every page in the virtual bar. If it does not the device will fail to be created.

## See also
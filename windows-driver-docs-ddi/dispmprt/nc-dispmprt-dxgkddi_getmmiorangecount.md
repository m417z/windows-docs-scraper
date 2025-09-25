# DXGKDDI_GETMMIORANGECOUNT callback function

## Description

Gets the number of memory ranges in the virtual device's MMIO (memory mapped input output) BARs (base address registers).

## Parameters

### `Context`

A handle to the device context.

### `pArgs`

Pointer to a [DXGKARG_GETMMIORANGECOUNT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkarg_getmmiorangecount) structure.

## Return value

Returns:

* STATUS_SUCCESS The IHV system did not encounter any errors.
* STATUS_INVALID_DEVICE_REQUEST The virtual device encountered an error and should be forcibly stopped. Failure here will cause virtual device failure.

## Prototype

```cpp
//Declaration

DXGKDDI_GETMMIORANGECOUNT DxgkddiGetmmiorangecount;

// Definition

NTSTATUS DxgkddiGetmmiorangecount
(
	HANDLE Context
	DXGKARG_GETMMIORANGECOUNT * pArgs
)
{...}

```

## Remarks

This function will get the total count of memory rages that make up each of the virtual device BARs. Each range represent a group of pages that is either directly mapped from one of the physical device BARs, intercepted by the software virtual device (but still backed by physical device memory), or completely virtual and not mapped.

Note that if a device is fully virtual, and does not require any intercepts or virtual pages, this function can be unimplemented and NULL in the interface.

## See also
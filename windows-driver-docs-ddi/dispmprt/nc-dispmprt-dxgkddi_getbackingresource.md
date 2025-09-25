# DXGKDDI_GETBACKINGRESOURCE callback function

## Description

Gets any physical backings for the virtual device MMIO (memory mapped input output) BARs (base address registers).

## Parameters

### `Context`

A handle to the device context.

### `pArgs`

Pointer to a [DXGKARG_GETBACKINGRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkarg_getbackingresource) structure.

## Return value

Returns:

* STATUS_SUCCESS The IHV system did not encounter any errors.
* STATUS_INVALID_DEVICE_REQUEST The virtual device encountered an error and should be forcibly stopped. Failure here will cause virtual device failure.

## Prototype

```cpp
//Declaration

DXGKDDI_GETBACKINGRESOURCE DxgkddiGetbackingresource;

// Definition

NTSTATUS DxgkddiGetbackingresource
(
	HANDLE Context
	DXGKARG_GETBACKINGRESOURCE * pArgs
)
{...}

```

## Remarks

## See also
# PFN_IDDCXADAPTERSETRENDERADAPTER callback function

## Description

**PFN_IDDCXADAPTERSETRENDERADAPTER** is a pointer to an OS callback function that sets the preferred render adapter on which to render the swapchains for the specified adapter.

## Parameters

### `DriverGlobals`

[in] Pointer to an [**IDD_DRIVER_GLOBALS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idd_driver_globals) structure containing system-defined per-driver data.

### `AdapterObject`

[in] The adapter object of the adapter for which the rendering adapter preference is being set.

### `pInArgs`

[in] Input arguments.

## Return value

None.

## Remarks

An indirect display driver (IDD) should not use this pointer to directly call the function that it points to. IDDs should instead call [**IddCxAdapterSetRenderAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadaptersetrenderadapter).

## See also

[**IddCxAdapterSetRenderAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadaptersetrenderadapter)
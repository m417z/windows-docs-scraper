# IddCxAdapterDisplayConfigUpdate function

## Description

A remote driver can call **IddCxAdapterDisplayConfigUpdate** to allow a client to tell the server how to update the monitor configuration. A driver that reports HDR support must use [**IddCxAdapterDisplayConfigUpdate2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorupdatemodes2) instead.

## Parameters

### `AdapterObject`

[in] The [**IDDCX_ADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object of the remote adapter that the display configuration is specified for.

### `pInArgs`

[in] Pointer to an [**IDARG_IN_ADAPTERDISPLAYCONFIGUPDATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapterdisplayconfigupdate) structure containing input arguments to the function.

## Return value

**IddCxAdapterDisplayConfigUpdate** returns STATUS_SUCCESS upon success; otherwise, it returns an appropriate error code. See Remarks.

## Remarks

A remote indirect display driver (IDD) calls **IddCxAdapterDisplayConfigUpdate** when it receives a new display configuration.

The OS returns STATUS_SUCCESS if it has stored the newly specified display configuration. These changes will asynchronously reconfigure the swapchains for the monitors as requested. **IddCxAdapterDisplayConfigUpdate** will first flush any pending monitor arrivals, and process departures to ensure that the list of monitors is current.

If **IddCxAdapterDisplayConfigUpdate** determines that the supplied display configuration is not currently supported by the driver, it returns STATUS_INVALID_PARAMETER and logs the reason using WPP for debugging purposes. For example, a driver might not support a specified resolution/refresh rate, or an invalid monitor might be specified.

**IddCxAdapterDisplayConfigUpdate** returns STATUS_GRAPHICS_INDIRECT_DISPLAY_DEVICE_STOPPED if the session this configuration change is targeted to gets disconnected or if the session adapter is being stopped.

## See also

[**IDARG_IN_ADAPTERDISPLAYCONFIGUPDATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapterdisplayconfigupdate)

[**IddCxAdapterDisplayConfigUpdate2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorupdatemodes2)
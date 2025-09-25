## Description

*Dxgkrnl* calls a kernel-mode display driver's (KMD) **DxgkDdiDisplayMuxGetDriverSupportLevel** function to query the level of support the driver has for the [automatic display switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch) (ADS) feature.

## Parameters

### `DriverContext`

[in] Handle to a context block that is associated with a display adapter. KMD's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to *Dxgkrnl*.

### `pDriverSupportLevel`

[out] Pointer to a [**DXGK_DISPLAYMUX_SUPPORT_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-dxgk_displaymux_support_level) value in which the driver writes the level of ADS support that it provides.

## Return value

**DxgkDdiDisplayMuxGetDriverSupportLevel** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns an appropriate NT_STATUS error code.

## Remarks

This DDI is called under [synchronization level 2](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level).

**DxgkDdiDisplayMuxGetDriverSupportLevel** is called before [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device). It's meant to return just the level of automatic display switch support the driver generically has. The support level returned shouldn't be influenced by any other factor, including:

* The GPU the driver is loaded for.
* Any other GPU in the system.
* Any aspect of the system; for example, internal or external monitor connected, system type, or any information obtained from the system.

If the driver supports automatic display switching on any system then it return a value that isn't DXGK_DISPLAYMUX_DRIVER_SUPPORT_LEVEL_NONE.

For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).

## See also

[**DXGK_DISPLAYMUX_SUPPORT_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-dxgk_displaymux_support_level)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)
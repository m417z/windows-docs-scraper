## Description

The **IDDCX_DISPLAYCONFIG_MODE** structure contains details of the mode to be set for the monitor in a path.

## Members

### `Position`

A [**POINT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that contains the requested desktop position for this path.

### `Resolution`

A [**DISPLAYCONFIG_2DREGION**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_2dregion) structure that contains the resolution for this path. **Resolution** must match a resolution supported by the driver.

### `Rotation`

A [**DISPLAYCONFIG_ROTATION**](https://learn.microsoft.com/windows/win32/api/wingdi/ne-wingdi-displayconfig_rotation) value that specifies the requested screen orientation for this path.

### `RefreshRate`

A [**DISPLAYCONFIG_RATIONAL**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_rational) structure that contains the requested refresh rate for this path. **RefreshRate** must match a refresh rate supported by the driver for the specified resolution. This refresh rate is defined as progressive because remote drivers can only support progressive target modes.

### `VSyncFreqDivider`

The V Sync divider value for the specified **RefreshRate**.

### `MonitorColorMode`

A [**IDDCX_DISPLAYCONFIG_MONITOR_COLORMODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_displayconfig_monitor_colormode) value that specifies the color mode to be set on this monitor.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDARG_IN_ADAPTERDISPLAYCONFIGUPDATE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_adapterdisplayconfigupdate2)

[**IDDCX_DISPLAYCONFIGPATH2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_displayconfigpath2)

[**IddCxAdapterDisplayConfigUpdate2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate2)
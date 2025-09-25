## Description

The **DXGK_DISPLAYMUX_SET_INTERNAL_PANEL_INFO** structure contains information about the internal panel.

## Members

### `Brightness3Supported`

Boolean value that indicates whether the [**DXGK_BRIGHTNESS_INTERFACE_3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_brightness_interface_3) is supported by the GPU that the panel was initially connected to at boot time.

### `Brightness3Caps`

If **Brightness3Supported** is TRUE, **Brightness3Caps** is a [**DXGK_BRIGHTNESS_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_caps) structure that contains the reported brigtness 3 capabilities.

### `Bridgtness3Ranges`

If **Brightness3Supported** is TRUE, **Brightness3Ranges** is a [**DXGK_BRIGHTNESS_GET_NIT_RANGES_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_brightness_get_nit_ranges_out) structure that contains the reported brigtness 3 ranges.

## Remarks

For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).

## See also

[**DxgkddiDisplayMuxSetInternalPanelInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_set_internal_panel_info)
## Description

The **DXGK_DISPLAYMUX_SUPPORT_LEVEL** enumeration specifies the level of support that a kernel-mode display driver (KMD) provides for [automatic display switching](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch) (ADS).

## Constants

### `DXGK_DISPLAYMUX_DRIVER_SUPPORT_LEVEL_UNINITIALIZED:0`

A variable of this enumeration type hasn't yet been assigned a meaningful value.

### `DXGK_DISPLAYMUX_DRIVER_SUPPORT_LEVEL_NONE:1`

The driver has no support for ADS.

### `DXGK_DISPLAYMUX_DRIVER_SUPPORT_LEVEL_DEVELOPMENT:2`

The driver has development support for ADS, but the quality isn't considered good enough for release. For development purposes only.

### `DXGK_DISPLAYMUX_DRIVER_SUPPORT_LEVEL_EXPERIMENTAL:3`

The driver has experimental support for ADS, but the quality isn't considered good enough for general customer rollout. For testing purposes only.

### `DXGK_DISPLAYMUX_DRIVER_SUPPORT_LEVEL_FULL:4`

The driver has full support for ADS and is ready for general customer rollout.

## Remarks

For more information, see [Automatic Display Switch](https://learn.microsoft.com/windows-hardware/drivers/display/automatic-display-switch).

## See also

[**DxgkDdiDisplayMuxGetDriverSupportLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_displaymux_get_driver_support_level)
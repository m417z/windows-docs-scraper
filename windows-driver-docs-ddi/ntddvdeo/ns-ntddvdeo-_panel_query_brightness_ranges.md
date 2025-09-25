# PANEL_QUERY_BRIGHTNESS_RANGES structure

## Description

The **PANEL_QUERY_BRIGHTNESS_RANGES** structure contains a list of supported nit ranges.

## Members

### `Version`

a [**BRIGHTNESS_INTERFACE_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ne-ntddvdeo-_brightness_interface_version) value that specifies the target interface version. This value should always be DXGK_BRIGHTNESS_INTERFACE_VERSION_3.

### `BrightnessLevel`

A [**BRIGHTNESS_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_brightness_level) structure for the list of supported brightness levels of the display panel.

### `NitRanges`

A [**BRIGHTNESS_NIT_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-_brightness_nit_range) structure for the supported nit ranges of the display panel.

## See also

[**IOCTL_PANEL_QUERY_BRIGHTNESS_RANGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_panel_query_brightness_ranges)
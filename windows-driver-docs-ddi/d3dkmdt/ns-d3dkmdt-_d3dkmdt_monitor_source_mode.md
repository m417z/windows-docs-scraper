# _D3DKMDT_MONITOR_SOURCE_MODE structure

## Description

The D3DKMDT_MONITOR_SOURCE_MODE structure contains information about a monitor source mode.

## Members

### `Id`

An integer that identifies the monitor source mode.

### `VideoSignalInfo`

A [D3DKMDT_VIDEO_SIGNAL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_signal_info) enumerator that indicates the video mode standard (if any) that defines the mode.

### `ColorBasis`

A [D3DKMDT_COLOR_BASIS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_color_basis) enumerator that indicates the color basis of the mode.

### `ColorCoeffDynamicRanges`

A [D3DKMDT_COLOR_COEFF_DYNAMIC_RANGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_color_coeff_dynamic_ranges) structure that contains the dynamic ranges for the color channels in the mode's color basis.

### `Origin`

A value from the [D3DKMDT_MONITOR_CAPABILITIES_ORIGIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_monitor_capabilities_origin) enumeration that indicates the source of the mode information. For example the mode information could be from a default monitor profile or it could be from an override in an INF file.

### `Preference`

A value from the [D3DKMDT_MODE_PREFERENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_mode_preference) enumeration that indicates whether the mode is the preferred mode in a [monitor source mode set](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## Remarks

The D3DKMDT_MONITOR_SOURCE_MODE_ID data type is defined in *D3dkmdt.h*.

## See also

[D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode)

[D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode)
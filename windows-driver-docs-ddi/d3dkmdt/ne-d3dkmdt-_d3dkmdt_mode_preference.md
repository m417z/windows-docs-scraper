# _D3DKMDT_MODE_PREFERENCE enumeration

## Description

The D3DKMDT_MODE_PREFERENCE enumeration is used to indicate whether a particular mode is one of the modes preferred by the monitor connected to a given video present target.

## Constants

### `D3DKMDT_MP_UNINITIALIZED`

Indicates that a variable of type D3DKMDT_MODE_PREFERENCE has not yet been assigned a meaningful value.

### `D3DKMDT_MP_PREFERRED`

Indicates that the mode is preferred by the monitor.

### `D3DKMDT_MP_NOTPREFERRED`

Indicates that the mode is not preferred by the monitor.

## Remarks

The **Info** member of the [D3DKMDT_MONITOR_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_source_mode) structure and the **SignalInfo** member of the [D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode) structure are [D3DKMDT_VIDEO_SIGNAL_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_signal_info) structures. The **ModePreference** member of the D3DKMDT_VIDEO_SIGNAL_MODE structure is a D3DKMDT_MODE_PREFERENCE value.

## See also

[DxgkDdiEnumVidPnCofuncModality](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_enumvidpncofuncmodality)
# _D3DKMDT_MONITOR_CAPABILITIES_ORIGIN enumeration

## Description

The D3DKMDT_MONITOR_CAPABILITIES_ORIGIN enumeration is used to indicate where a monitor's capability information was obtained.

## Constants

### `D3DKMDT_MCO_UNINITIALIZED`

Indicates that a variable of type D3DKMDT_MONITOR_CAPABILITIES_ORIGIN has not yet been assigned a meaningful value.

### `D3DKMDT_MCO_DEFAULTMONITORPROFILE`

Indicates that the capability information was obtained from the default monitor profile.

### `D3DKMDT_MCO_MONITORDESCRIPTOR`

Indicates that the capability information was obtained from an Extended Display Information Data (EDID) descriptor.

### `D3DKMDT_MCO_MONITORDESCRIPTOR_REGISTRYOVERRIDE`

Indicates that the capability information was obtained from an INF file section that overrides the monitor's EDID descriptor.

### `D3DKMDT_MCO_SPECIFICCAP_REGISTRYOVERRIDE`

Indicates that the capability information was obtained from an INF file section that overrides a single capability.

### `D3DKMDT_MCO_DRIVER`

Indicates that the capability information was obtained by a call to the display miniport driver's [DxgkDdiRecommendMonitorModes](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendmonitormodes) function.

## Remarks

The **Origin** member of the [D3DKMDT_MONITOR_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_source_mode) structure is a constant from the D3DKMDT_MONITOR_CAPABILITIES_ORIGIN enumeration.

## See also

[Monitor Source Mode Set Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/)
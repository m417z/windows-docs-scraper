# DXGK_PATH_UPDATE enumeration

## Description

Enum which indicates how this path has been modified since the previous successful call to [**SetTimingsFromVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn).

## Constants

### `DXGK_PATH_UPDATE_UNMODIFIED`

Indicates that this path has not been changed since the last call to [**SetTimingsFromVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn). This allows the driver to skip interrogating VidPn for changes. Existing scan-out should continue, other than any glitching which might be caused due to reassignment of display resources to satisfy other paths.

### `DXGK_PATH_UPDATE_ADDED`

Indicates that this path is new so the driver will have to fully comprehend the description of what is required. Since there is no allocation from which to scan out, the driver must scan out black until the OS associates one or more planes to be scanned out.

### `DXGK_PATH_UPDATE_MODIFIED`

Indicates that this path has been changed since the last call to [**SetTimingsFromVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn). The driver will have to interrogate the VidPn and check the other path info fields in order to understand what has changed. The OS will have removed all pixel planes prior to making this call so the driver must scan out black until the OS associates one or more planes to be scanned out.

### `DXGK_PATH_UPDATE_REMOVED`

Indicates that this path was present in the previous VidPn but has been removed. The driver should be able to optimize the removal without interrogating VidPn to see that the path has been removed.
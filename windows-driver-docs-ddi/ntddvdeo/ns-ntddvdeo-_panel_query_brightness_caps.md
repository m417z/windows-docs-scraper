# _PANEL_QUERY_BRIGHTNESS_CAPS structure

## Description

Retrieves brightness control capabilities of a display panel.

## Members

### `Smooth`

All drivers are required to support a smooth timed transition.

### `Adaptive`

Supports adaptive transition.

### `NitsCalibrated`

The display brightness is calibrated to correspond to absolute brightness levels measured in nits. Calibrated data provided to the Display Driver by OEMs should be taken with an On Pixel Ratio (OPR) percentage of 100% where each pixel is set to an RGB value of (255, 255, 255) or floating point equivalent. If it is not set, then the OS is aware that the levels exposed by GetNitRanges do not necessarily represent the actual luminance of the display.

### `Reserved`

Reserved.

### `Value`

Value.

### `Version`

The target version. This value should always be DXGK_BRIGHTNESS_INTERFACE_VERSION_3.
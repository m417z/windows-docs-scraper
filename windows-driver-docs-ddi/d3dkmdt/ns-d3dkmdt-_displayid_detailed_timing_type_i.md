# _DISPLAYID_DETAILED_TIMING_TYPE_I structure

## Description

The DISPLAYID_DETAILED_TIMING_TYPE_I structure specifies an additional target mode set for a video present target.

## Members

### `PixelClock` [in]

The display pixel clock rate, in units of 10 KHz. Clock rate must be between 1 MHz and 10 GHz, inclusive.

### `AspectRatio` [in]

The display aspect ratio, which must be one of the values in the [DISPLAYID_DETAILED_TIMING_TYPE_I_ASPECT_RATIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_displayid_detailed_timing_type_i_aspect_ratio) enumeration.

### `Reserved` [in]

Reserved for system use.

### `ScanningType` [in]

The frame scanning type. Must be one of the values in the [DISPLAYID_DETAILED_TIMING_TYPE_I_SCANNING_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_displayid_detailed_timing_type_i_scanning_mode) enumeration.

### `StereoMode` [in]

The display stereo vision mode. Must be one of the values in the [DISPLAYID_DETAILED_TIMING_TYPE_I_STEREO_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_displayid_detailed_timing_type_i_stereo_mode) enumeration.

### `PreferredTiming`

 [in] Indicates whether the first 128-byte block of a monitor's Extended Display Identification Data [Extended Display Identification Data (EDID)](https://learn.microsoft.com/windows-hardware/drivers/) contains detailed timing data. This must be 1 if the display conforms to EDID version 1.3 and later.

### `HorizontalActivePixels` [in]

The number of active pixels in the horizontal direction.

### `HorizontalBlankPixels` [in]

The number of blank pixels in the horizontal direction.

### `HorizontalFrontPorch` [in]

The horizontal front porch interval, in pixels. The front porch is the blanking interval before the sync pulse.

### `HorizontalSyncPolarity` [in]

The horizontal sync polarity, which must be one of the values in the [DISPLAYID_DETAILED_TIMING_TYPE_I_SYNC_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_displayid_detailed_timing_type_i_sync_polarity) enumeration.

### `HorizontalSyncWidth` [in]

The horizontal sync interval, in pixels.

### `VerticalActiveLines` [in]

The number of active scan lines.

### `VerticalBlankLines` [in]

The number of blank scan lines.

### `VerticalFrontPorch` [in]

The vertical front porch interval, in number of lines. The front porch is the blanking interval before the sync pulse.

### `VerticalSyncPolarity` [in]

The vertical sync polarity. Must be one of the values in the [DISPLAYID_DETAILED_TIMING_TYPE_I_SYNC_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_displayid_detailed_timing_type_i_sync_polarity) enumeration.

### `VerticalSyncWidth` [in]

The vertical sync interval, in number of lines.

## Remarks

The Microsoft DirectX graphics kernel subsystem fills this structure by reading the additional target mode data that is stored in the registry at the following path:

**HKEY_LOCAL_MACHINE\ SYSTEM\ CurrentControlSet\ Control\ GraphicsDrivers\ AdditionalTargetModeLists**

The graphics kernel subsystem also validates that each registry value meets the requirements described above for each respective member.

## See also

[DISPLAYID_DETAILED_TIMING_TYPE_I_ASPECT_RATIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_displayid_detailed_timing_type_i_aspect_ratio)

[DISPLAYID_DETAILED_TIMING_TYPE_I_SCANNING_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_displayid_detailed_timing_type_i_scanning_mode)

[DISPLAYID_DETAILED_TIMING_TYPE_I_STEREO_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_displayid_detailed_timing_type_i_stereo_mode)

[DISPLAYID_DETAILED_TIMING_TYPE_I_SYNC_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_displayid_detailed_timing_type_i_sync_polarity)
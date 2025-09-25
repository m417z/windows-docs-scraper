# D2D1_HDRTONEMAP_PROP enumeration

## Description

Defines constants that identify the top level properties of the [HDR tone map effect](https://learn.microsoft.com/windows/desktop/Direct2D/hdr-tone-map-effect). The effect adjusts the maximum luminance of the source image to fit within the maximum output luminance supported. Input and output luminance values are specified in nits. Note that the color space of the target image is assumed to be scRGB.

## Constants

### `D2D1_HDRTONEMAP_PROP_INPUT_MAX_LUMINANCE` (0)

Identifies the `InputMaxLuminance` property of the effect. The property is of type FLOAT, and is specified in nits.

### `D2D1_HDRTONEMAP_PROP_OUTPUT_MAX_LUMINANCE` (1)

Identifies the `OutputMaxLuminance` property of the effect. The property is of type FLOAT, and is specified in nits.

### `D2D1_HDRTONEMAP_PROP_DISPLAY_MODE` (2)

Identifies the `DisplayMode` property of the effect. The property is of type [**D2D1_HDRTONEMAP_DISPLAY_MODE**](https://learn.microsoft.com/windows/desktop/api/d2d1effects_2/ne-d2d1effects_2-d2d1_hdrtonemap_display_mode).

### `D2D1_HDRTONEMAP_PROP_FORCE_DWORD` (0xFFFFFFFF)
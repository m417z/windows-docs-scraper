# D2D1_COLORMANAGEMENT_RENDERING_INTENT enumeration

## Description

Specifies which ICC rendering intent the [Color management effect](https://learn.microsoft.com/windows/desktop/Direct2D/color-management) should use.

## Constants

### `D2D1_COLORMANAGEMENT_RENDERING_INTENT_PERCEPTUAL:0`

The effect compresses or expands the full color gamut of the image to fill the color gamut of the device,
so that gray balance is preserved but colorimetric accuracy may not be preserved.

### `D2D1_COLORMANAGEMENT_RENDERING_INTENT_RELATIVE_COLORIMETRIC:1`

The effect preserves the chroma of colors in the image at the possible expense of hue and lightness.

### `D2D1_COLORMANAGEMENT_RENDERING_INTENT_SATURATION:2`

The effect adjusts colors that fall outside the range of colors the output device renders to the closest color available. It does not preserve the white point.

### `D2D1_COLORMANAGEMENT_RENDERING_INTENT_ABSOLUTE_COLORIMETRIC:3`

The effect adjusts any colors that fall outside the range that the output device can render to the closest color that can be rendered. The effect does not change the other colors and preserves the white point.

### `D2D1_COLORMANAGEMENT_RENDERING_INTENT_FORCE_DWORD:0xffffffff`
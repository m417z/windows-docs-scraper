# D2D1_BLEND_MODE enumeration

## Description

The blend mode used for the [Blend effect](https://learn.microsoft.com/windows/desktop/Direct2D/blend).

## Constants

### `D2D1_BLEND_MODE_MULTIPLY:0`

Basic blend formula for alpha only.

![Mathematical formula for a multiply effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_multiply_1.png)

### `D2D1_BLEND_MODE_SCREEN:1`

Basic blend formula for alpha only.

![Mathematical formula for a screen effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_screen_1.png)

### `D2D1_BLEND_MODE_DARKEN:2`

Basic blend formula for alpha only.

![mathematical formula for a darken effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_darken_1.png)

### `D2D1_BLEND_MODE_LIGHTEN:3`

Basic blend formula for alpha only.

![Mathematical formula for a lighten effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_lighten_1.png)

### `D2D1_BLEND_MODE_DISSOLVE:4`

Given:

* A scene coordinate XY for the current pixel
* A deterministic pseudo-random number generator rand(XY) based on seed coordinate XY, with unbiased distribution of values from [0, 1]

![Mathematical formula for a dissolve blend effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_dissolve_1.png)

### `D2D1_BLEND_MODE_COLOR_BURN:5`

Basic blend formulas with *f*(FRGB, BRGB) =

![Mathematical formula for a coor burn effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_colorburn_1.png)

### `D2D1_BLEND_MODE_LINEAR_BURN:6`

Basic blend formulas with *f*(FRGB, BRGB) =

![Mathematical formula for a linear burn effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_linearburn_1.png)

### `D2D1_BLEND_MODE_DARKER_COLOR:7`

Basic blend formula for alpha only.

![Mathematical formula for a darken color effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_darkencolor_1.png)

### `D2D1_BLEND_MODE_LIGHTER_COLOR:8`

Basic blend formula for alpha only.

![Mathematical formula for a lighter color effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_lightercolor_1.png)

### `D2D1_BLEND_MODE_COLOR_DODGE:9`

Basic blend formulas with *f*(FRGB, BRGB) =

![Mathematical formula for a color dodge effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_colordodge_1.png)

### `D2D1_BLEND_MODE_LINEAR_DODGE:10`

Basic blend formulas with *f*(FRGB, BRGB) =

![Mathematical formula for a linear dodge effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_lineardodge_1.png)

### `D2D1_BLEND_MODE_OVERLAY:11`

Basic blend formulas with *f*(FRGB, BRGB) =

![Mathematical formula for an overlay effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_overlay_1.png)

### `D2D1_BLEND_MODE_SOFT_LIGHT:12`

Basic blend formulas with *f*(FRGB, BRGB) =

![Mathematical formula for a soft light effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_softlight_1.png)

### `D2D1_BLEND_MODE_HARD_LIGHT:13`

Basic blend formulas with *f*(FRGB, BRGB) =

![Mathematical formula for a hard light effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_hardlight_1.png)

### `D2D1_BLEND_MODE_VIVID_LIGHT:14`

Basic blend formulas with *f*(FRGB, BRGB) =

![Mathematical formula for a vivid light effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_vividlight_1.png)

### `D2D1_BLEND_MODE_LINEAR_LIGHT:15`

Basic blend formulas with *f*(FRGB, BRGB) =

![Mathematical formula for a linear light effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_linearlight_1.png)

### `D2D1_BLEND_MODE_PIN_LIGHT:16`

Basic blend formulas with *f*(FRGB, BRGB) =

![Mathematical formula for a pin light effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_pinlight_1.png)

### `D2D1_BLEND_MODE_HARD_MIX:17`

Basic blend formulas with *f*(FRGB, BRGB) =

![Mathematical formula for a hard mix effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_hardmix_1.png)

### `D2D1_BLEND_MODE_DIFFERENCE:18`

Basic blend formulas with *f*(FRGB, BRGB) = abs(FRGB - BRGB)

### `D2D1_BLEND_MODE_EXCLUSION:19`

Basic blend formulas with *f*(FRGB, BRGB) = FRGB + BRGB – 2 * FRGB * BRGB

### `D2D1_BLEND_MODE_HUE:20`

Basic blend formula for alpha only.

![Mathematical formula for a hue blend effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_hue_1.png)

### `D2D1_BLEND_MODE_SATURATION:21`

Basic blend formula for alpha only.

![Mathematical formula for a saturation blend effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_saturation_1.png)

### `D2D1_BLEND_MODE_COLOR:22`

Basic blend formula for alpha only.

![Mathematical formula for a color blend effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_color_1.png)

### `D2D1_BLEND_MODE_LUMINOSITY:23`

Basic blend formula for alpha only.

![Mathematical formula for a luminosity blend effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_luminosity_1.png)

### `D2D1_BLEND_MODE_SUBTRACT:24`

Basic blend formula for alpha only.

![Mathematical formula for a subtract blend effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_subtract_1.png)

### `D2D1_BLEND_MODE_DIVISION:25`

Basic blend formula for alpha only.

![Mathematical formula for a division blend effect.](https://learn.microsoft.com/windows/win32/api/d2d1effects/images/blend_mode_division_1.png)

### `D2D1_BLEND_MODE_FORCE_DWORD:0xffffffff`
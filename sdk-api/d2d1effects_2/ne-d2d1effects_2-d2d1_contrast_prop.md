# D2D1_CONTRAST_PROP enumeration

## Description

Identifiers for properties of the [Contrast effect](https://learn.microsoft.com/windows/desktop/Direct2D/contrast-effect).

## Constants

### `D2D1_CONTRAST_PROP_CONTRAST:0`

The D2D1_CONTRAST_PROP_CONTRAST property is a float value indicating the amount by which to adjust the contrast of the image. Negative values reduce contrast, while positive values increase contrast.
Minimum value is -1.0f, maximum value is 1.0f. The default value for the property is 0.0f.

### `D2D1_CONTRAST_PROP_CLAMP_INPUT:1`

The D2D1_CONTRAST_PROP_CLAMP_INPUT property is a boolean value indicating whether or not to clamp the input to [0.0, 1.0]. The default value for the property is FALSE.

### `D2D1_CONTRAST_PROP_FORCE_DWORD:0xffffffff`

## See also

[Built-in Effects](https://learn.microsoft.com/windows/desktop/Direct2D/built-in-effects)

[Contrast effect](https://learn.microsoft.com/windows/desktop/Direct2D/contrast-effect)

[CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)
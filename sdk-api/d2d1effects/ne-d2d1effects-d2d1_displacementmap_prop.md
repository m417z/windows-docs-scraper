# D2D1_DISPLACEMENTMAP_PROP enumeration

## Description

Identifiers for properties of the [Displacement map effect](https://learn.microsoft.com/windows/desktop/Direct2D/displacement-map).

## Constants

### `D2D1_DISPLACEMENTMAP_PROP_SCALE:0`

Multiplies the intensity of the selected channel from the displacement image. The higher you set this property, the more the effect displaces the pixels.

The type is FLOAT.

The default value is 0.0f.

### `D2D1_DISPLACEMENTMAP_PROP_X_CHANNEL_SELECT:1`

The effect extracts the intensity from this color channel and uses it to spatially displace the image in the X direction.

The type is [D2D1_CHANNEL_SELECTOR](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_channel_selector).

The default value is D2D1_CHANNEL_SELECTOR_A

### `D2D1_DISPLACEMENTMAP_PROP_Y_CHANNEL_SELECT:2`

The effect extracts the intensity from this color channel and uses it to spatially displace the image in the Y direction.

The type is [D2D1_CHANNEL_SELECTOR](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_channel_selector).

The default value is D2D1_CHANNEL_SELECTOR_A

### `D2D1_DISPLACEMENTMAP_PROP_FORCE_DWORD:0xffffffff`
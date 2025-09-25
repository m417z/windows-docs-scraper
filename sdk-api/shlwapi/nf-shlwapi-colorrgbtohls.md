# ColorRGBToHLS function

## Description

Converts colors from RGB to hue-luminance-saturation (HLS) format.

## Parameters

### `clrRGB`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

The original RGB color.

### `pwHue` [out]

Type: **WORD***

A pointer to a value that, when this method returns successfully, receives the HLS hue value.
Can range from 0 to 240.

### `pwLuminance` [out]

Type: **WORD***

A pointer to a value that, when this method returns successfully, receives the HLS luminance value.
Can range from 0 to 240.

### `pwSaturation` [out]

Type: **WORD***

A pointer to a value that, when this method returns successfully, receives the HLS saturation value.
Can range from 0 to 240.
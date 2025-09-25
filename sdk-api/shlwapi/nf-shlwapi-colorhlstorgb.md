# ColorHLSToRGB function

## Description

Converts colors from hue-luminance-saturation (HLS) to RGB format.

## Parameters

### `wHue`

Type: **WORD**

The original HLS hue value.
Can range from 0 to 240.

### `wLuminance`

Type: **WORD**

The original HLS luminance value.
Can range from 0 to 240.

### `wSaturation`

Type: **WORD**

The original HLS saturation value.
Can range from 0 to 240.

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

Returns the RGB value.
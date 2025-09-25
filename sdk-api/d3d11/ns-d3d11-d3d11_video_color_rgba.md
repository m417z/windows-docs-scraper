# D3D11_VIDEO_COLOR_RGBA structure

## Description

Specifies an RGB color value.

## Members

### `R`

The red value.

### `G`

The green value.

### `B`

The blue value.

### `A`

The alpha value. Values range from 0 (transparent) to 1 (opaque).

## Remarks

The RGB values have a nominal range of [0...1]. For an RGB format with *n* bits per channel, the value of each color component is calculated as follows:

`val = f * ((1 << n)-1)`

For example, for RGB-32 (8 bits per channel), `val = BYTE(f * 255.0)`.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)
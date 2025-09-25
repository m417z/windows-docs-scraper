# DXVAHD_COLOR_RGBA structure

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

For full-range RGB, reference black is (0.0, 0.0, 0.0), which corresponds to (0, 0, 0) in an 8-bit representation. For limited-range RGB, reference black is (0.0625, 0.0625, 0.0625), which corresponds to (16, 16, 16) in an 8-bit representation. For wide-gamut formats, the values might fall outside of the [0...1] range.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)
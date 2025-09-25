# D3D11_1DDI_VIDEO_COLOR_YCbCrA structure

## Description

Specifies a YCbCr color value.

## Members

### `Y`

The Y (luma) value.

### `Cb`

The Cb chroma value.

### `Cr`

The Cr chroma value.

### `A`

The alpha value. Values range from 0 (transparent) to 1 (opaque).

## Remarks

Values have a nominal range of [0...1]. Given a format with *n* bits per channel, the value of each color component is calculated as follows:

`val = f * ((1 << n)-1)`

For example, for 8-bit YUV formats, `val = BYTE(f * 255.0)`. Reference black is (0.0625, 0.5, 0.5), which corresponds to (16, 128, 128) in an 8-bit representation.
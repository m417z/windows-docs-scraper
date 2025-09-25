# D3D12_VIDEO_PROCESS_ALPHA_BLENDING structure

## Description

Specifies alpha blending parameters for video processing. Used by the [D3D12_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS]ns-d3d12video-d3d12_video_process_input_stream_arguments) structure.

## Members

### `Enable`

A boolean value specifying whether alpha blending is enabled.

### `Alpha`

The planar alpha value. The value can range from 0.0 (transparent) to 1.0 (opaque). If *Enable* is FALSe, this parameter is ignored.

## Remarks

For each pixel, the destination color value is computed as follows:

`Cd = Cs * (As * Ap * Ae) + Cd * (1.0 - As * Ap * Ae)`

where:

- Cd = The color value of the destination pixel
- Cs = The color value of the source pixel
- As = The per-pixel source alpha
- Ap = The planar alpha value
- Ae = The palette-entry alpha value, or 1.0 (palette-entry alpha values apply only to palettized color formats)

## See also
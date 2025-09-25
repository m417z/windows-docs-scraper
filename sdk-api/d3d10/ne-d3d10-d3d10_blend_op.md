# D3D10_BLEND_OP enumeration

## Description

RGB or alpha blending operation.

## Constants

### `D3D10_BLEND_OP_ADD:1`

Add source 1 and source 2.

### `D3D10_BLEND_OP_SUBTRACT:2`

Subtract source 1 from source 2.

### `D3D10_BLEND_OP_REV_SUBTRACT:3`

Subtract source 2 from source 1.

### `D3D10_BLEND_OP_MIN:4`

Find the minimum of source 1 and source 2.

### `D3D10_BLEND_OP_MAX:5`

Find the maximum of source 1 and source 2.

## Remarks

The runtime implements RGB blending and alpha blending separately. Therefore, blend state requires separate blend operations for RGB data and alpha data. These blend operations are specified in a [blend description](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_blend_desc). The two sources — source 1 and source 2 — are shown in the [blending block diagram](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage).

Blend state is used by the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) to determine how to blend together two RGB pixel values and two alpha values. The two RGB pixel values and two alpha values are the RGB pixel value and alpha value that the pixel shader outputs and the RGB pixel value and alpha value already in the output render target. The [blend option](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend) controls the data source that the blending stage uses to modulate values for the pixel shader, render target, or both. The **blend operation** controls how the blending stage mathematically combines these modulated values.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)
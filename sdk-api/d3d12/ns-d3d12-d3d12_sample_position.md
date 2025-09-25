# D3D12_SAMPLE_POSITION structure

## Description

Describes a sub-pixel sample position for use with programmable sample positions.

## Members

### `X`

A signed sub-pixel coordinate value in the X axis.

### `Y`

A signed sub-pixel coordinate value in the Y axis.

## Remarks

Sample positions have the origin (0, 0) at the pixel center. Each of the X and Y coordinates are signed values in the range -8 (top/left) to 7 (bottom/right). Values outside this range are invalid.

Each increment of these integer values represents 1/16th of a pixel. For example, X and Y values of -8 and 4, respectively, correspond to floating-point values of -0.5 and 0.25, a point located on the left-most edge of the pixel, half-way between its center-line and the bottom edge. Because of this, the bottom-most and right-most edge of a pixel are not reachable by sampling (these positions are reachable as the top-most and left-most edges of the neighboring pixels).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)
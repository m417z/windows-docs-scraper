# ID2D1LinearGradientBrush::SetStartPoint

## Description

Sets the starting coordinates of the linear gradient in the brush's coordinate space.

## Parameters

### `startPoint`

Type: **[D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)**

The starting two-dimensional coordinates of the linear gradient, in the brush's coordinate space.

## Remarks

The start point and end point are described in the brush's space and are mapped to the render target when the brush is used. If there is a non-identity brush transform or render target transform, the brush's start point and end point are also transformed.

## See also

[ID2D1LinearGradientBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1lineargradientbrush)
# IInkStrokeDisp::Shear

## Description

Shears the ink in the stroke or strokes by the specified horizontal and vertical factors.

## Parameters

### `HorizontalMultiplier` [in]

The horizontal factor of the shear.

### `VerticalMultiplier` [in]

The vertical factor of the shear.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

The transformation applied in this method is a pure shear only if one of the parameters is 0. Applied to a rectangle at the origin, when the *shearY* factor is 0, the transformation moves the bottom edge horizontally by *shearX* times the height of the rectangle. When the *shearX* factor is 0, it moves the right edge vertically by *shearY* times the width of the rectangle.

**Note** When both parameters are nonzero, the results may not be intuitive.

This method throws an exception if the shear is non-invertible. The shear is non-invertible if the product of the *shearX* and *shearY* parameters equals 1.

## See also

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)
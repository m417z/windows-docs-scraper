# IInkTransform::Shear

## Description

Adjusts the shear of the [InkTransform](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class) by the specified horizontal and vertical factors.

## Parameters

### `HorizontalComponent` [in]

 The horizontal factor of the shear.

### `VerticalComponent` [in]

 The vertical factor of the shear.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

The transformation applied in this method is a pure shear only if one of the parameters is 0. Applied to a rectangle at the origin, when the *shearY* factor is 0, the transformation moves the bottom edge horizontally by *shearX* times the height of the rectangle. When the *shearX* factor is 0, it moves the right edge vertically by *shearY* times the width of the rectangle.

**Note** When both parameters are nonzero, the results are difficult to predict. For example, if both factors are 1, the transformation squeezes the entire plane to a single line.

## See also

[IInkTransform](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinktransform)

[InkTransform Class](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class)
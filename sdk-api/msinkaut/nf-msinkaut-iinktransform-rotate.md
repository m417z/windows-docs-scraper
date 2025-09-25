# IInkTransform::Rotate

## Description

Changes the amount, measured in degrees, to change the rotation factor of the [InkTransform](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class) object and optionally the center point of the rotation.

## Parameters

### `Degrees` [in]

The degrees by which to rotate clockwise. Without the optional x and y arguments, rotation takes place around the origin point, which by default is the upper left corner of the ink collection area to which the transform is applied.

### `x` [in, optional]

Optional. The x-coordinate of the point in ink space coordinates around which rotation occurs. The default value is 0.

### `y` [in, optional]

Optional. The y-coordinate of the point in ink space coordinates around which rotation occurs. The default value is 0.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

The center point defaults to the origin.

## See also

[IInkTransform](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinktransform)

[InkTransform Class](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class)
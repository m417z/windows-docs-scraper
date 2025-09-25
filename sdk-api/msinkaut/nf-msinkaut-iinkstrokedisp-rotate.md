# IInkStrokeDisp::Rotate

## Description

Rotates the ink using an angle in degrees around a center point of the rotation.

## Parameters

### `Degrees` [in]

The degrees by which to rotate clockwise.

### `x` [in, optional]

Optional. The x-coordinate of the point in ink space coordinates around which to rotate. Default is the origin. The default value is the origin (0).

### `y` [in, optional]

Optional. The y-coordinate of the point in ink space coordinates around which to rotate. The default value is the origin (0).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## See also

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)
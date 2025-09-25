# IInkStrokes::Rotate

## Description

Rotates the ink using an angle in degrees around a center point of the rotation.

## Parameters

### `Degrees` [in]

The degrees by which to rotate clockwise.

### `x` [in, optional]

Optional. The x-coordinate of the point in ink space coordinates around which to rotate. Default is the origin.

### `y` [in, optional]

Optional. The y-coordinate of the point in ink space coordinates around which to rotate. Default is the origin.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## See also

[IInkStrokes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkstrokes)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))
# IInkTransform::SetTransform

## Description

Modifies the [InkTransform](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class) member data.

An [InkTransform](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class) object represents a 3×3 matrix that, in turn, represents an affine transformation. The object stores only six of the nine numbers in a 3×3 matrix because all 3×3 matrices that represent affine transformations have the same third column (0, 0, 1).

## Parameters

### `eM11` [in]

The element in the first row, first column.

### `eM12` [in]

The element in the first row, second column.

### `eM21` [in]

The element in the second row, first column.

### `eM22` [in]

The element in the second row, second column.

### `eDx` [in]

The element in the third row, first column.

### `eDy` [in]

The element in the third row, second column.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## See also

[GetTransform Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinktransform-gettransform)

[IInkTransform](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinktransform)

[InkTransform Class](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class)
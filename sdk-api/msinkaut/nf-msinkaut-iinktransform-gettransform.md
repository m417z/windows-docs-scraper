# IInkTransform::GetTransform

## Description

Gets the [InkTransform](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class) member data.

## Parameters

### `eM11` [out]

 The real number that specifies the element in the first row, first column.

### `eM12` [out]

 The real number that specifies the element in the first row, second column.

### `eM21` [out]

 The real number that specifies the element in the second row, first column.

### `eM22` [out]

 The real number that specifies the element in the second row, second column.

### `eDx` [out]

 The real number that specifies the element in the third row, first column.

### `eDy` [out]

 The real number that specifies the element in the third row, second column.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_POINTER** | A parameter contained an invalid pointer. |

## Remarks

An [InkTransform](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class) object represents a 33 matrix that, in turn, represents an affine transformation. The object stores only six of the nine numbers in a 3x3 matrix because all 3x3 matrices that represent affine transformations have the same third column (0, 0, 1).

## See also

[IInkTransform](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinktransform)

[InkTransform Class](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class)

[SetTransform Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinktransform-settransform)
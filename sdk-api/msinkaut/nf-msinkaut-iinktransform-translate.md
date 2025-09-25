# IInkTransform::Translate

## Description

Applies a translation to a transform.

## Parameters

### `HorizontalComponent` [in]

The horizontal component of the translation.

### `VerticalComponent` [in]

The vertical component of the translation.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **E_INVALIDARG** | Invalid argument. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## See also

[IInkTransform](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinktransform)

[InkTransform Class](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class)
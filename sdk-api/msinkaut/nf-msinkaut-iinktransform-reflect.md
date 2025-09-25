# IInkTransform::Reflect

## Description

Performs reflection on a transform in either horizontal or vertical directions.

## Parameters

### `Horizontally` [in]

**VARIANT_TRUE** to reflect in the horizontal direction; otherwise, **VARIANT_FALSE**.

### `Vertically` [in]

**VARIANT_TRUE** to reflect in the vertical direction; otherwise, **VARIANT_FALSE**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid VARIANT_BOOL variants. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## See also

[IInkTransform](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinktransform)

[InkTransform Class](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class)
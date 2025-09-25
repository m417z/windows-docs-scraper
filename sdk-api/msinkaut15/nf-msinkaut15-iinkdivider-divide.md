# IInkDivider::Divide

## Description

Returns a [IInkDivisionResult](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionresult) object that contains the results of the layout analysis of strokes in the [InkDivider](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class) object.

## Parameters

### `InkDivisionResult` [out, retval]

When this method returns, contains a pointer to an [IInkDivisionResult](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionresult) object that contains structural information about the strokes in the [InkDivider](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class) object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contains an invalid pointer. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **E_FAIL** | An unspecified error occurred. |
| **E_OUTOFMEMORY** | Unable to allocate memory to complete the operation. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

This method returns a new [IInkDivisionResult](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionresult) object each time this method is called.

## See also

[IInkDivider](https://learn.microsoft.com/windows/win32/api/msinkaut15/nn-msinkaut15-iinkdivider)

[IInkDivisionResult Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut15/nn-msinkaut15-iinkdivisionresult)

[InkDivider Class](https://learn.microsoft.com/windows/desktop/tablet/inkdivider-class)
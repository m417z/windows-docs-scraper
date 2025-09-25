# IInkStrokeDisp::GetPoints

## Description

Retrieves the points that make up a stroke.

## Parameters

### `Index` [in, optional]

Optional. The starting index within the array of points that make up the stroke. The default value ISC_FirstElement, defined in the [InkSelectionConstants](https://learn.microsoft.com/windows/win32/api/msinkaut/ne-msinkaut-inkselectionconstants) enumeration type, specifies the first point.

### `Count` [in, optional]

Optional. The number of points to return. The default value ISC_AllElements, defined in the [InkSelectionConstants](https://learn.microsoft.com/windows/win32/api/msinkaut/ne-msinkaut-inkselectionconstants) enumeration type, specifies all of the points that make up the stroke data.

### `Points` [out, retval]

When this method returns, contains the array of points from the stroke.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_OUTOFMEMORY** | Cannot allocate memory for the points. |
| **E_INVALIDARG** | Invalid index (out of range). |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## See also

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[ItemSelectionConstants Enumeration](https://learn.microsoft.com/windows/win32/api/msinkaut/ne-msinkaut-inkselectionconstants)
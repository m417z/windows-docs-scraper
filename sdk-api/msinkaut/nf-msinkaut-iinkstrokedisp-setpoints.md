# IInkStrokeDisp::SetPoints

## Description

Sets the points of the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) using an array of X, Y values.

## Parameters

### `Points` [in]

The array of new points to replace the points in the stroke beginning at *index*. This is a VARIANT containing an array of Long with the points represented by alternating values of the form x0, y0, x1, y1, x2, y2, and so on.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `Index` [in, optional]

Optional. The zero-based index of the first point in the stroke to be modified. The default value [ISC_FirstElement](https://learn.microsoft.com/windows/win32/api/msinkaut/ne-msinkaut-inkselectionconstants), defined in the **ItemSelectionConstants** enumeration type, specifies that the first point in the stroke is modified.

### `Count` [in, optional]

Optional. The count of points in the stroke to be modified. The default value [ISC_AllElements](https://learn.microsoft.com/windows/win32/api/msinkaut/ne-msinkaut-inkselectionconstants), defined in the **ItemSelectionConstants** enumeration type, specifies that all points in the stroke are modified.

### `NumberOfPointsSet` [out, retval]

When this method returns, contains the actual number of packets set.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | Invalid *index* (out of range), or *points* parameter. Was not in the correct format. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

This method does not change the number of points in the stroke. To change the number of points in the stroke, a new stroke must be created, or the stroke must be split.

This method does not provide for truncating the stroke. If the points array contains fewer points than the stroke, the remainder of the points in the stroke are not be modified.

This method does not provide for extending the stroke. If the points array contains more points than the stroke, the extra points are not used. If the count exceeds the number of points in the array, only the number of points in the array are modified.

In order to draw the stroke after calling **SetPoints**, call the [InvalidateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-invalidaterect) function.

## See also

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[ItemSelectionConstants Enumeration](https://learn.microsoft.com/windows/win32/api/msinkaut/ne-msinkaut-inkselectionconstants)
# IInkStrokeDisp::GetRectangleIntersections

## Description

Finds the points where a [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object intersects a given rectangle.

## Parameters

### `Rectangle` [in]

The rectangle in **ink space** coordinates, that describes the hit test area.

### `Intersections` [out, retval]

When this method returns, contains a VARIANT array that indicates where the stroke intersects the *rectangle*. The beginning floating point indices are stored in the even indices. The ending floating point indices are stored in the odd indices. The first pair of indices represents the first intersection.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_OUTOFMEMORY** | Cannot allocate Stroke handler helper object. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

This method returns an array that indicates where the stroke intersects the specified rectangle. Each segment of the stroke that intersects the rectangle is one pair of indices, alternating with a beginning index followed by an ending index.

If the stroke begins within the test rectangle, the first index is set to -1. If the stroke ends within the test rectangle, the last index is set to -1. If the stroke is wholly outside the test rectangle, an empty array is returned. For example, if a stroke begins inside the test rectangle, leaves the boundaries of the rectangle, returns inside, and leaves again, then the **GetRectangleIntersections** method might return {-1, 1.4, 5.5, 10.1} to describe the two segments of the stroke falling within the rectangle.

## See also

[Clip Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-clip)

[FindIntersections Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-findintersections)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)
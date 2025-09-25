# IInkStrokes::GetBoundingBox

## Description

Gets the bounding box in ink space coordinates for either all of the strokes in an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object, an individual stroke, or an [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection.

## Parameters

### `BoundingBoxMode` [in, optional]

Optional. Specifies the stroke characteristics to use to calculate the bounding box. For more details about the use of stroke characteristics to calculate a bounding box, see the [BoundingBoxMode](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkboundingboxmode) enumeration type.

The *BoundingBoxMode* parameter of the [GetBoundingBox](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getboundingbox) method has a default value of -1, which means that all characteristics of a stroke are used to specify the bounding box.

### `BoundingBox` [out, retval]

When this method returns, contains a pointer to the rectangle that defines the bounding box of an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object, an [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object, or an [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection.

**Note** For an [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object, the returned bounding box is a copy of the strokes bounding box, so altering the returned bounding box does not affect the strokes location.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **REGDB_CLASSNOTREG** | The [InkRectangle](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class) object is not registered. |

## Remarks

When the bounding box is affected by the pen width, then this width is scaled appropriately for the [InkRenderer](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)'s view transform. To do this, the pen width is multiplied by the square root of the determinant of the view transform.

**Note** In Windows Vista and later versions, [GetBoundingBox Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getboundingbox) does not take the width of the stroke into account.

**Note** If you have not set the pen width explicitly, it is 53 by default. You must multiply the pen width by the square root of the determinant to yield the correct bounding box. The height and width of the bounding box are expanded by half this amount in each direction. For example, consider that the pen width is 53, the square root of the determinant is 50, and the bounding box is (0, 0, 1000, 1000). The pen width adjustment to the bounding box in each direction is calculated as (53 * 50) / 2, and the right and bottom sides are incremented by one. This results in a rendered bounding box of (-1325, -1325, 2326, 2326).

## See also

[IInkStrokes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkstrokes)

[InkBoundingBoxMode Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkboundingboxmode)

[InkRectangle Class](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))
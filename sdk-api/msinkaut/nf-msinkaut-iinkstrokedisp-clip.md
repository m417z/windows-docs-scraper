# IInkStrokeDisp::Clip

## Description

Removes portions of an [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object or [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection that are outside a rectangle.

## Parameters

### `Rectangle` [in]

Specifies the rectangle outside of which the stroke or strokes are clipped. The rectangle is specified in ink space coordinates.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **REGDB_CLASSNOTREG** | The [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object is not registered. |
| **E_INVALIDARG** | Invalid clip rectangle. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

For an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object, all strokes intersected by the rectangle are split at the intersection points. All portions of strokes outside the rectangle are removed from the **InkDisp** object. The method may add new points to a stroke at the point where the stroke intersects the rectangle. After you call the **Clip** method on an **InkDisp** object, the IDs of the strokes in the **InkDisp** object's strokes collection are guaranteed to be unique, but not guaranteed to preserve other information.

This method does not take the pen width into account when clipping. It clips only the actual **ink** or stroke data.

For an [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object or [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection, the **Clip** method updates the parent [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. Whenever ink is removed from an **InkDisp** object, any **IInkStrokeDisp** objects or InkStrokes collections defined for that **InkDisp** object may be invalidated.

For more information on ink data, see [Ink Data](https://learn.microsoft.com/windows/desktop/tablet/ink-data).

## See also

[HitTest(Rectangle, Single) Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-hittestwithrectangle)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[InkRectangle Class](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class)
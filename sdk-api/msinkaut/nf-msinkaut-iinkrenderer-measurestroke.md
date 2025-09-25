# IInkRenderer::MeasureStroke

## Description

Calculates the rectangle on the device context that would contain a stroke if it were drawn with the [InkRenderer](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class) object using the [DrawStroke](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-drawstroke) method.

## Parameters

### `Stroke` [in]

The stroke to measure.

### `DrawingAttributes` [in, optional]

Optional. The [InkDrawingAttributes](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class) to use when calculating the rectangle, which override the drawing attributes on the stroke. The default value is **NULL**, which means the stroke is measured by using its own drawing attributes.

### `Rectangle` [out, retval]

When this method returns, contains a pointer to the rectangle on the device context that would contain the stroke if the stroke were drawn with the [DrawStroke](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-drawstroke) method of the [InkRenderer](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class) object. The stroke must contain x- and y-coordinates to calculate the rectangle. Otherwise, the method returns an empty rectangle.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **REGDB_E_CLASSNOTREG** | The [InkRectangle](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class) object is not registered on the system. |
| **E_INK_INCOMPATIBLE_OBJECT** | [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) does not point to a compatible [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object, or *drawingAttributes* is an invalid input parameter. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | Invalid display handle. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## Remarks

This is accurate only if you pass the same arguments to both **MeasureStroke** and [DrawStroke](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-drawstroke).

Since the bounding box is affected by the pen width, this width is scaled appropriately for the [InkRenderer](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)'s view transform. To do this, the pen width is multiplied by the square root of the determinant of the view transform. The height and width of the bounding box are expanded by half this amount in each direction, and the right and bottom sides are incremented by one.

For example, consider that the pen width is originally 53, the square root of the determinant of the view transform is 50, and the bounding box is (0, 0, 1000, 1000). The pen width adjustment to the bounding box in each direction is calculated as (53 * 50) / 2, and the right and bottom sides are incremented by one. This results in a rendered bounding box of (-1325, -1325, 2326, 2326).

## See also

[Draw Method [InkRenderer Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-draw)

[DrawStroke Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-drawstroke)

[IInkRenderer](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrenderer)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[InkRenderer Class](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)

[Measure Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-measure)
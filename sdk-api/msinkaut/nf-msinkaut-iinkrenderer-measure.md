# IInkRenderer::Measure

## Description

Calculates the rectangle on the device context that would contain a collection of strokes if the strokes were drawn with the [InkRenderer](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class) object using the [DrawStroke](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-drawstroke) method.

## Parameters

### `Strokes` [in]

The collection of strokes to measure.

### `Rectangle` [out, retval]

When this method returns, contains a pointer to the rectangle on the device context that would contain the strokes if they were drawn with the [DrawStroke](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-drawstroke) method of the [InkRenderer](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class) object. The strokes must contain x- and y-coordinates to calculate the rectangle. Otherwise, the method returns an empty rectangle.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | Invalid display handle. |
| **E_INK_INCOMPATIBLE_OBJECT** | The *strokes* parameter does not point to a valid object. |
| **E_INK_MISMATCHED_INK_OBJECT** | The strokes parameter is associated with a different [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## Remarks

This is accurate only if you pass the same arguments to both **Measure** and [DrawStroke](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-drawstroke).

Since the bounding box is affected by the pen width, this width is scaled appropriately for the [InkRenderer](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)'s view transform. To do this, the pen width is multiplied by the square root of the determinant of the view transform. The height and width of the bounding box are expanded by half this amount in each direction, and the right and bottom sides are incremented by one.

For example, consider that the pen width is originally 53, the square root of the determinant of the view transform is 50, and the bounding box is (0, 0, 1000, 1000). The pen width adjustment to the bounding box in each direction is calculated as (53 * 50) / 2, and the right and bottom sides are incremented by one. This results in a rendered bounding box of (-1325, -1325, 2326, 2326).

## See also

[Draw Method [InkRenderer Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-draw)

[IInkRenderer](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrenderer)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[InkRenderer Class](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)

[MeasureStroke Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-measurestroke)
# IInkRenderer::DrawStroke

## Description

Draws the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object using the known device context, and optionally draws the **IInkStrokeDisp** object with the known [InkDrawingAttributes](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class) object.

## Parameters

### `hDC` [in]

 The [hWnd](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_hwnd) of the device context on which to draw.

### `Stroke` [in]

 The stroke to draw.

### `DrawingAttributes` [in, optional]

Optional. Specifies the [InkDrawingAttributes](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class) to use on the drawing. The default value is **NULL**. If **InkDrawingAttributes** is specified, they override the [DrawingAttributes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcursor-get_drawingattributes) on the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_MISMATCHED_INK_OBJECT** | The strokes parameter is associated with a different [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. |
| **E_INVALIDARG** | Invalid display handle. |
| **E_INK_INCOMPATIBLE_OBJECT** | The *stroke* or the *drawingAttributes* parameter does not point to a valid object. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## Remarks

The pen width is multiplied (or scaled) by the square root of the determinant of the view transform.

**Note** If you have not set the pen width explicitly, it is 53 by default. You must multiply the pen width by the square root of the determinant to yield the correct bounding box. The height and width of the bounding box are expanded by half this amount in each direction.

For example, consider that the pen width is 53, the square root of the determinant is 50, and the bounding box is (0,0,1000,1000). The pen width adjustment to the bounding box in each direction is calculated as (53*50)/2, and the right and bottom sides are incremented by one. This results in a rendered bounding box of (-1325,-1325,2326,2326).

The [InkRenderer](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class) forces the viewport and window origins to 0, 0. Any existing settings are saved and restored, but are not used by the **InkRenderer**. To perform scrolling, use the **InkRenderer** object's view and object transform methods.

## See also

[Draw Method [InkRenderer Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-draw)

[IInkRenderer](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrenderer)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[InkDrawingAttributes Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)

[InkRenderer Class](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)
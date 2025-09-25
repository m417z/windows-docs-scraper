# IInkRenderer::Draw

## Description

Draws ink strokes using the known device context.

## Parameters

### `hDC` [in]

Specifies the [hWnd](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_hwnd) of the device context on which to draw.

### `Strokes` [in]

Specifies the strokes to draw.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_MISMATCHED_INK_OBJECT** | The strokes parameter is associated with a different [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. |
| **E_INVALIDARG** | An argument is invalid. |
| **E_INK_INCOMPATIBLE_OBJECT** | The *hdc* or the *strokes* parameter does not point to a valid object. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## Remarks

The pen width is multiplied (or scaled) by the square root of the determinant of the view transform.

**Note** If you have not set the pen width explicitly, it is 53 by default. You must multiply the pen width by the square root of the determinant to yield the correct bounding box. The height and width of the bounding box are expanded by half this amount in each direction.

For example, consider that the pen width is 53, the square root of the determinant is 50, and the bounding box is (0,0,1000,1000). The pen width adjustment to the bounding box in each direction is calculated as (53*50)/2, and the right and bottom sides are incremented by one. This results in a rendered bounding box of (-1325,-1325,2326,2326).

**Note** Use the [DrawStroke](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-drawstroke) method to draw a single stroke.

The [InkRenderer](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class) forces the viewport and window origins to 0, 0. Any existing settings are saved and restored, but is not used by the **InkRenderer**. To perform scrolling, use the **InkRenderer** object's view and object transform methods.

## See also

[DrawStroke Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-drawstroke)

[IInkRenderer](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrenderer)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[InkDrawingAttributes Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)

[InkRenderer Class](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))
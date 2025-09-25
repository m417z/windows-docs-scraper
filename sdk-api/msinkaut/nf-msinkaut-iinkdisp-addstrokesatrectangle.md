# IInkDisp::AddStrokesAtRectangle

## Description

Adds a specified [Strokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection into this [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object at a specified rectangle.

## Parameters

### `SourceStrokes` [in]

 The strokes to add to the ink. These source strokes are appended to this [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

### `TargetRectangle` [in]

 The [InkRectangle](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class) in ink space coordinates where the strokes are added. A run-time error occurs if the coordinates of the rectangle are {0,0,0,0}.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INK_INCOMPATIBLE_OBJECT** | A pointer does not point at a valid object. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INVALIDARG** | The rectangle's top and bottom are equal. |

## Remarks

When inserted, the strokes are scaled from the bounding box of the strokes to the rectangle.

This method can be used to copy strokes within a single [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. The source ink strokes do not have to come from another **InkDisp** object.

## See also

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))
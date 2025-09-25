# IInkStrokeDisp::Move

## Description

Applies a translation to the ink of an [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object or [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection.

## Parameters

### `HorizontalComponent` [in]

The distance in ink space coordinates to translate the view transform in the X dimension.

### `VerticalComponent` [in]

The distance in ink space coordinates to translate the view transform in the Y dimension.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)
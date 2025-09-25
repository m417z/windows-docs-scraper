# IInkRenderer::Move

## Description

Applies a translation to the [view transform](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-getviewtransform) in ink space coordinates.

## Parameters

### `HorizontalComponent` [in]

The amount in ink space coordinates to translate the view transform in the X dimension.

### `VerticalComponent` [in]

The amount in ink space coordinates to translate the view transform in the Y dimension.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IInkRenderer](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrenderer)

[InkRenderer Class](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)
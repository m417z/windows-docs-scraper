# IInkPicture::HitTestSelection

## Description

Retrieves a member of the [SelectionHitResult](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-selectionhitresult) enumeration, which specifies which part of a selection, if any, was hit during a hit test.

## Parameters

### `x` [in]

The x-position, in pixels, of the hit test.

### `y` [in]

The y-position, in pixels, of the hit test.

### `SelArea` [out]

The value from the [SelectionHitResult](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-selectionhitresult) enumeration.

## Remarks

For further details about this method, refer to the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object's [HitTestSelection](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-hittestselection) method, which has the same functionality.

## See also

[IInkPicture](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkpicture)

[InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference)

[SelectionHitResult Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-selectionhitresult)
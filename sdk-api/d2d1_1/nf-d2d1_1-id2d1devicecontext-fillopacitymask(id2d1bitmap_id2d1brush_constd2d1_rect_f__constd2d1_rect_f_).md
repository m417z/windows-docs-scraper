# ID2D1DeviceContext::FillOpacityMask(ID2D1Bitmap,ID2D1Brush,const D2D1_RECT_F &,const D2D1_RECT_F &)

## Description

Fill using the alpha channel of the supplied opacity mask bitmap. The brush opacity will be modulated by the mask. The render target antialiasing mode must be set to aliased.

## Parameters

### `opacityMask` [in]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1bitmap)***

The bitmap that acts as the opacity mask

### `brush` [in]

Type: **[ID2D1Brush](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1brush)***

The brush to use for filling the primitive.

### `destinationRectangle` [in, ref, optional]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)**

The destination rectangle to output to in the render target

### `sourceRectangle` [in, ref, optional]

Type: **const [D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)**

The source rectangle from the opacity mask bitmap.

## See also

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)
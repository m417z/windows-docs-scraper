# TextureBrush::ResetTransform

## Description

The **TextureBrush::ResetTransform** method resets the transformation matrix of this texture brush to the identity matrix. This means that no transformation takes place.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the
**Status** enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Setting the transformation matrix to the identity matrix guarantees that no transformation is done. This method is often used to reset the transformation before making any adjustments (scaling, rotating, and so on) to it.

#### Examples

The following example creates a texture brush and sets the transformation of the brush. Next, the code uses the transformed brush to fill a rectangle. Then, the code resets the transformation of the brush and uses the untransformed brush to fill a rectangle.

```cpp
VOID Example_ResetTransform(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a texture brush, and set its transformation.
   Image image(L"HouseAndTree.Gif");
   TextureBrush textureBrush(&image);
   textureBrush.RotateTransform(30);

   // Fill a rectangle with the transformed texture brush.
   graphics.FillRectangle(&textureBrush, 0, 0, 200, 100);

   textureBrush.ResetTransform();

   // Fill a rectangle with the texture brush (no transformation).
   graphics.FillRectangle(&textureBrush, 250, 0, 200, 100);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Coordinate Systems and Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-coordinate-systems-and-transformations-about)

[Filling a Shape with an Image Texture](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-an-image-texture-use)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)

[TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush)

[TextureBrush::GetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-gettransform)

[TextureBrush::MultiplyTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-multiplytransform)

[TextureBrush::RotateTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-rotatetransform)

[TextureBrush::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-scaletransform)

[TextureBrush::SetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-settransform)

[TextureBrush::TranslateTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-translatetransform)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)
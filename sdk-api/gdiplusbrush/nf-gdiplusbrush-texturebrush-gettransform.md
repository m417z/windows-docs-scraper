# TextureBrush::GetTransform

## Description

The **TextureBrush::GetTransform** method gets the transformation matrix of this texture brush.

## Parameters

### `matrix` [out]

Type: **[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Pointer to a [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that receives the transformation matrix.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the
**Status** enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A
**TextureBrush** object maintains a transformation matrix that can store any affine transformation. When you use a texture brush to fill an area, GDI+ transforms the brush's image according to the brush's transformation matrix and then fills the area. The transformed image exists only during rendering; the image stored in the
**TextureBrush** object is not transformed. For example, suppose you call *someTextureBrush.ScaleTransform(3)* and then paint an area with *someTextureBrush*. The width of the brush's image triples when the area is painted, but the image stored in *someTextureBrush* remains unchanged.

#### Examples

The following example creates a texture brush and sets the transformation of the brush. The code then gets the brush's transformation matrix and proceeds to inspect or use the elements.

```cpp
VOID Example_GetTransform(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a texture brush, and set its transform.
   Image image(L"marble.jpg");
   TextureBrush textureBrush(&image);
   textureBrush.ScaleTransform(3, 2);

   // Obtain information about the texture brush.
   Matrix matrix;
   REAL elements[6];

   textureBrush.GetTransform(&matrix);
   matrix.GetElements(elements);

   for(INT j = 0; j <=5; ++j)
   {
      // Inspect or use the value in elements[j].
   }
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Coordinate Systems and Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-coordinate-systems-and-transformations-about)

[Filling a Shape with an Image Texture](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-an-image-texture-use)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush)

[TextureBrush::ResetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-resettransform)

[TextureBrush::SetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-texturebrush-settransform)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)
# Graphics::TranslateTransform

## Description

The **Graphics::TranslateTransform** method updates this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object's world transformation matrix with the product of itself and a translation matrix.

## Parameters

### `dx` [in]

Type: **REAL**

Real number that specifies the horizontal component of the translation.

### `dy` [in]

Type: **REAL**

Real number that specifies the vertical component of the translation.

### `order` [in, optional]

Type: **[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)**

Optional. Element of the [MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) enumeration that specifies the order of multiplication. [MatrixOrderPrepend](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) specifies that the translation matrix is on the left, and [MatrixOrderAppend](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder) specifies that the translation matrix is on the right. The default value is [MatrixOrderPrepend](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

**Note** GDI+ handles brushes differently when the world transform scale is less than 100%(1.0f) in either the x or y direction. If the world transform scale is less than 100%(1.0f), be sure to multiply the offset for TranslateTransform by the world transform scale.

#### Examples

The following example sets the world transformation of a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object to a rotation. The call to **Graphics::TranslateTransform** multiplies the **Graphics** object's existing world transformation matrix (rotation) by a translation matrix. The MatrixOrderAppend argument specifies that the multiplication is done with the translation matrix on the right. At that point, the world transformation matrix of the **Graphics** object represents a composite transformation: first rotate, then translate. The call to **DrawEllipse** draws a rotated and translated ellipse.

```cpp
VOID Example_TranslateTransform(HDC hdc)
{
   Graphics graphics(hdc);
   Pen pen(Color(255, 0, 0, 255));

   graphics.RotateTransform(30.0f);
   graphics.TranslateTransform(100.0f, 50.0f, MatrixOrderAppend);
   graphics.DrawEllipse(&pen, 0, 0, 200, 80);
}
```

## See also

[Coordinate Systems and Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-coordinate-systems-and-transformations-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-gettransform)

[Graphics::ResetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-resettransform)

[Graphics::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-scaletransform)

[Graphics::SetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-settransform)

[Graphics::TransformPoints](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-transformpoints(incoordinatespace_incoordinatespace_inoutpoint_inint))

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)
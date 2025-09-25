# Pen::SetTransform

## Description

The **Pen::SetTransform** method sets the world transformation of this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Parameters

### `matrix` [in]

Type: **const [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Pointer to a [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that specifies the world transformation.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

This method ignores the translation portion of the [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object.

#### Examples

The following example creates a scale matrix and a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object, and then draws a rectangle. The code then scales the pen by the matrix and draws a second rectangle.

```cpp
VOID Example_SetTransform(HDC hdc)
{
   Graphics graphics(hdc);

   Matrix matrix(20, 0, 0, 10, 0, 0);  // scale

   // Create a pen, and use it to draw a rectangle.
   Pen pen(Color(255, 0, 0, 255), 2);
   graphics.DrawRectangle(&pen, 10, 50, 150, 100);

   // Scale the pen width by a factor of 20 in the horizontal
   // direction and a factor of 10 in the vertical direction.
   pen.SetTransform(&matrix);

   // Draw a rectangle with the transformed pen.
   graphics.DrawRectangle(&pen, 200, 50, 150, 100);
}
```

## See also

[Coordinate Systems and Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-coordinate-systems-and-transformations-about)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::GetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-gettransform)

[Pen::MultiplyTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-multiplytransform)

[Pen::ResetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-resettransform)

[Pen::RotateTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-rotatetransform)

[Pen::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-scaletransform)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)
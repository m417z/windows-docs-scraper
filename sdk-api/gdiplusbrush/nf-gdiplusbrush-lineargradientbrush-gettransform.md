# LinearGradientBrush::GetTransform

## Description

The **LinearGradientBrush::GetTransform** method gets the transformation matrix of this linear gradient brush.

## Parameters

### `matrix` [out]

Type: **Matrix***

Pointer to a [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that receives the transformation matrix.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A
[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush) object maintains a transformation matrix that can store any affine transformation. When you use a linear gradient brush to fill an area, GDI+ transforms the brush's boundary lines according to the brush's transformation matrix and then fills the area. The transformed boundaries exist only during rendering; the boundaries stored in the
**LinearGradientBrush** object are not transformed.

#### Examples

The following example creates a linear gradient brush and sets its transformation matrix. Next, the code gets the brush's transformation matrix and proceeds to inspect or use the matrix elements.

```cpp
VOID Example_GetTransform(HDC hdc)
{
   Graphics myGraphics(hdc);

   // Construct a linear gradient brush, and set its transformation.
   LinearGradientBrush linGrBrush(
      Point(0, 0),
      Point(200, 0),
      Color(255, 255, 0, 0),    // red
      Color(255, 0, 0, 255));   // blue

   Matrix matrixSet(0, 1, -1, 0, 0, 0);

   linGrBrush.SetTransform(&matrixSet);

   // Obtain information about the linear gradient brush.
   Matrix matrixGet;
   REAL   elements[6];

   linGrBrush.GetTransform(&matrixGet);
   matrixGet.GetElements(elements);

   for(INT j = 0; j <= 5; ++j)
   {
       // Inspect or use the value in elements[j].
   }
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Filling Shapes with a Gradient Brush](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-shapes-with-a-gradient-brush-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[LinearGradientBrush::SetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-settransform)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Matrix Representation of Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-matrix-representation-of-transformations-about)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)
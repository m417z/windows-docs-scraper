# LinearGradientBrush::SetTransform

## Description

The **LinearGradientBrush::SetTransform** method sets the transformation matrix of this linear gradient brush.

## Parameters

### `matrix` [in]

Type: **const Matrix***

Pointer to a [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that specifies the transformation matrix.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A
[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush) object has a rectangle that specifies the starting and ending boundaries of the gradient and a mode or angle that affects the direction. If the brush's transformation matrix is set to represent any transformation other than the identity, then the boundaries and direction are transformed according to that matrix during rendering.

The transformation applies only during rendering. The boundaries stored by the
[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush) object are not altered by the **LinearGradientBrush::SetTransform** method.

#### Examples

The following example creates a linear gradient brush and uses it to fill a rectangle. Next, the code modifies the brush's transformation matrix and fills a rectangle with the transformed brush.

```cpp
VOID Example_SetTransform(HDC hdc)
{
   Graphics myGraphics(hdc);

   LinearGradientBrush linGrBrush(
      Rect(0, 0, 100, 50),
      Color(255, 255, 0, 0),  // red
      Color(255, 0, 0, 255),  // blue
      LinearGradientModeHorizontal);

   Matrix matrix(2.0, 0, 0, 1, 0, 0);  // horizontal doubling

   // Fill a large area with the linear gradient brush (no transformation).
   myGraphics.FillRectangle(&linGrBrush, 0, 0, 800, 50);

   linGrBrush.SetTransform(&matrix);

   // Fill a large area with the transformed linear gradient brush.
   myGraphics.FillRectangle(&linGrBrush, 0, 75, 800, 50);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Creating a Linear Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-linear-gradient-use)

[Filling Shapes with a Gradient Brush](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-shapes-with-a-gradient-brush-use)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[LinearGradientBrush::GetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-gettransform)

[LinearGradientBrush::ResetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-lineargradientbrush-resettransform)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Matrix Representation of Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-matrix-representation-of-transformations-about)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)
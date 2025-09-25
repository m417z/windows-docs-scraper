# PathGradientBrush::SetTransform

## Description

The **PathGradientBrush::SetTransform** method sets the transformation matrix of this path gradient brush.

## Parameters

### `matrix` [in]

Type: **const [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Pointer to a
**Matrix** object that specifies the transformation matrix.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object has a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object that serves as the boundary path for the brush. When you paint with a path gradient brush, only the area inside the boundary path is filled. If the brush's transformation matrix is set to represent any transformation other than the identity, then the boundary path is transformed according to that matrix during rendering, and only the area inside the transformed path is filled.

The transformation applies only during rendering. The boundary path stored by the
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object is not altered by the **PathGradientBrush::SetTransform** method.

#### Examples

The following example creates a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on a triangular path. The
[Graphics::FillRectangle](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillrectangle(inconstbrush_inconstrect_)) method uses the path gradient brush to paint a rectangle that contains the triangular path. Next, the code creates a
[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that represents a composite transformation (rotate, then translate) and passes the address of that
**Matrix** object to the **PathGradientBrush::SetTransform** method of the
**PathGradientBrush** object. The code calls
[FillRectangle](https://learn.microsoft.com/previous-versions/ms535957(v=vs.85)) a second time to paint the same rectangle using the transformed path gradient brush.

```cpp
VOID Example_SetTransform(HDC hdc)
{
   Graphics graphics(hdc);

   Point pts[] = {
      Point(0, 0),
      Point(100, 0),
      Point(100, 100)};

   Color cols[] = {
      Color(255, 255, 0, 0),  // red
      Color(255, 0, 255, 0),  // green
      Color(255, 0, 0, 0)};   // black

   INT count = 3;
   PathGradientBrush pthGrBrush(pts, 3);
   pthGrBrush.SetSurroundColors(cols, &count);

   // Fill an area with the path gradient brush (no transformation).
   graphics.FillRectangle(&pthGrBrush, 0, 0, 200, 200);

   // Set the transformation for the brush (rotate, then translate).
   Matrix matrix(0.0f, 1.0f, -1.0f, 0.0f, 150.0f, 60.0f);
   pthGrBrush.SetTransform(&matrix);

   // Fill the same area with the transformed path gradient brush.
   graphics.FillRectangle(&pthGrBrush, 0, 0, 200, 200);
}
```

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PathGradientBrush::GetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-gettransform)

[PathGradientBrush::MultiplyTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-multiplytransform)

[PathGradientBrush::ResetTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-resettransform)

[PathGradientBrush::RotateTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-rotatetransform)

[PathGradientBrush::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-scaletransform)

[PathGradientBrush::TranslateTransform](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-pathgradientbrush-translatetransform)
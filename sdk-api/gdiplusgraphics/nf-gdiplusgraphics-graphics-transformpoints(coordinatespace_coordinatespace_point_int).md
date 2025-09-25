# Graphics::TransformPoints(IN CoordinateSpace,IN CoordinateSpace,IN OUT Point,IN INT)

## Description

The **Graphics::TransformPoints** method converts an array of points from one coordinate space to another. The conversion is based on the current world and page transformations of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

## Parameters

### `destSpace` [in]

Type: **[CoordinateSpace](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-coordinatespace)**

Element of the [CoordinateSpace](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-coordinatespace) enumeration that specifies the destination coordinate space.

### `srcSpace` [in]

Type: **[CoordinateSpace](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-coordinatespace)**

Element of the [CoordinateSpace](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-coordinatespace) enumeration that specifies the source coordinate space.

### `pts` [in, out]

Type: **[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)***

Pointer to an array that, on input, holds the points to be converted and, on output, holds the converted points.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the *pts* array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The world transformation converts points from the world coordinate space to the page coordinate space. The page transformation converts points from the page coordinate space to the device coordinate space. For more information about coordinate spaces, see [Types of Coordinate Systems](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-types-of-coordinate-systems-about).

#### Examples

The following example creates a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object and sets its world transformation to a translation 40 units right and 30 units down. Then the code creates an array of points and passes the address of that array to the **Graphics::TransformPoints** method of the same **Graphics** object. The points in the array are transformed by the world transformation of the **Graphics** object. The code calls the [Graphics::DrawLine](https://learn.microsoft.com/previous-versions/ms536020(v=vs.85)) method twice: once to connect the two points before the transformation and once to connect the two points after the transformation.

```cpp
VOID Example_TransformPoints(HDC hdc)
{
   Graphics graphics(hdc);
   Pen pen(Color(255, 0, 0, 255));

   // Create an array of two Point objects.
   Point points[2] = {Point(0, 0), Point(100, 50)};

   // Draw a line that connects the two points.
   // No transformation has been performed yet.
   graphics.DrawLine(&pen, points[0], points[1]);

   // Set the world transformation of the Graphics object.
   graphics.TranslateTransform(40.0f, 30.0f);

   // Transform the points in the array from world to page coordinates.
   graphics.TransformPoints(
      CoordinateSpacePage,
      CoordinateSpaceWorld,
      points,
      2);

   // It is the world transformation that takes points from world
   // space to page space. Because the world transformation is a
   // translation 40 to the right and 30 down, the
   // points in the array are now (40, 30) and (140, 80).

   // Draw a line that connects the transformed points.
   graphics.ResetTransform();
   graphics.DrawLine(&pen, points[0], points[1]);
}
```

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-gettransform)

[Graphics::MultiplyTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-multiplytransform)

[Graphics::ResetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-resettransform)

[Graphics::RotateTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-rotatetransform)

[Graphics::ScaleTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-scaletransform)

[Graphics::SetTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-settransform)

[Graphics::TranslateTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-translatetransform)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[MatrixOrder](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-matrixorder)

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)

[Types of Coordinate Systems](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-types-of-coordinate-systems-about)
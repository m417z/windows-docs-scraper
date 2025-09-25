# Matrix::TransformVectors(IN OUT Point,IN INT)

## Description

The **Matrix::TransformVectors** method multiplies each vector in an array by this matrix. The translation elements of this matrix (third row) are ignored. Each vector is treated as a row matrix. The multiplication is performed with the row matrix on the left and this matrix on the right.

## Parameters

### `pts` [in, out]

Type: **[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)***

Pointer to an array of [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) objects that, on input, contains the vectors to be transformed and, on output, receives the transformed vectors. Each vector in the array is transformed (multiplied by this matrix) and updated with the result of the transformation.

### `count` [in]

Type: **INT**

Optional. Integer that specifies the number of vectors to be transformed. The default value is 1.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

While a point represents position, a vector represents an entity (for example, velocity or acceleration) that has a direction and a magnitude. Thus, the endpoints of a line segment are points, but their difference is a vector—the length and direction of that line segment.

Vectors are similar to points in many ways. Like points, they are represented by x- and y-coordinates, so GDI+ uses the same classes ([Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) and
[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)) to represent vectors as it uses to represent points. The subtle difference between vectors and points is the way they are affected by transformations. In the physical world, moving the origin of the coordinate system changes the coordinates of all position points, but it will not alter any velocity vectors. Vectors can be scaled, rotated, sheared or flipped, but not translated (moved). Thus, when an affine transformation is applied to a vector, the translation component (the last row of the matrix) is ignored.

#### Examples

The following example creates a vector and a point. The tip of the vector and the point are at the same location: (100, 50). The code creates a
[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object and initializes its elements so that it represents a clockwise rotation followed by a translation 100 units to the right. The code calls the
[Matrix::TransformPoints](https://learn.microsoft.com/previous-versions/ms535321(v=vs.85)) method of the matrix to transform the point and calls the **Matrix::TransformVectors** method of the matrix to transform the vector. The entire transformation (rotation followed by translation) is performed on the point, but only the rotation part of the transformation is performed on the vector. The elements of the matrix that represent translation are ignored by the **Matrix::TransformVectors** method.

```cpp
VOID Example_TransVectors(HDC hdc)
{
   Graphics graphics(hdc);

   Pen pen(Color(255, 0, 0, 255), 7);
   pen.SetEndCap(LineCapArrowAnchor);
   SolidBrush brush(Color(255, 0, 0, 255));

   // A point and a vector, same representation but different behavior
   Point point(100, 50);
   Point vector(100, 50);

   // Draw the original point and vector in blue.
   graphics.FillEllipse(&brush, point.X - 5, point.Y - 5, 10, 10);

   graphics.DrawLine(&pen, Point(0, 0), vector);

   // Transform.
   Matrix matrix(0.8f, 0.6f, -0.6f, 0.8f, 100.0f, 0.0f);
   matrix.TransformPoints(&point);
   matrix.TransformVectors(&vector);

   // Draw the transformed point and vector in red.
   pen.SetColor(Color(255, 255, 0, 0));
   brush.SetColor(Color(255, 255, 0, 0));
   graphics.FillEllipse(&brush, point.X - 5, point.Y - 5, 10, 10);
   graphics.DrawLine(&pen, Point(0, 0), vector);
}
```

## See also

[Global and Local Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-global-and-local-transformations-about)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Matrix Representation of Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-matrix-representation-of-transformations-about)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[TransformPoints Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nf-gdiplusmatrix-matrix-transformpoints(inoutpoint_inint))

[TransformVectors Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nf-gdiplusmatrix-matrix-transformvectors(inoutpoint_inint))

[Transformations](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-transformations-use)
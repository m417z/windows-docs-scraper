# GraphicsPath::GetPathPoints(OUT Point,IN INT)

## Description

The **GraphicsPath::GetPathPoints** method gets this path's array of points. The array contains the endpoints and control points of the lines and Bézier splines that are used to draw the path.

## Parameters

### `points` [out]

Type: **[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)***

Pointer to an array of [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) objects that receives the data points. You must allocate memory for this array. You can call the [GraphicsPath::GetPointCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpointcount) method to determine the required size of the array. The size, in bytes, should be the return value of **GraphicsPath::GetPointCount** multiplied by **sizeof**(**Point**).

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the *points* array. Set this parameter equal to the return value of the [GraphicsPath::GetPointCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpointcount) method.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object has an array of points and an array of types. Each element in the array of types is a byte that specifies the point type and a set of flags for the corresponding element in the array of points. Possible point types and flags are listed in the [PathPointType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pathpointtype) enumeration.

#### Examples

The following example creates and draws a path that has a line, a rectangle, an ellipse, and a curve. The code calls the path's [GraphicsPath::GetPointCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpointcount) method to determine the number of data points that are stored in the path. The code allocates a buffer large enough to receive the array of data points and passes the address of that buffer to the **GraphicsPath::GetPathPoints** method. Finally, the code draws each of the path's data points.

```cpp
VOID GetPathPointsExample(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a path that has a line, a rectangle, an ellipse, and a curve.
   GraphicsPath path;

   Point points[] = {
      Point(200, 200),
      Point(250, 240),
      Point(200, 300),
      Point(300, 310),
      Point(250, 350)};

   path.AddLine(20, 100, 150, 200);
   path.AddRectangle(Rect(40, 30, 80, 60));
   path.AddEllipse(Rect(200, 30, 200, 100));
   path.AddCurve(points, 5);

   // Draw the path.
   Pen pen(Color(255, 0, 0, 255));
   graphics.DrawPath(&pen, &path);

   // Get the path points.
   INT count = path.GetPointCount();
   Point* dataPoints = new Point[count];
   path.GetPathPoints(dataPoints, count);

   // Draw the path's data points.
   SolidBrush brush(Color(255, 255, 0, 0));
   for(INT j = 0; j < count; ++j)
   {
      graphics.FillEllipse(
         &brush,
         dataPoints[j].X - 3.0f,
         dataPoints[j].Y - 3.0f,
         6.0f,
         6.0f);
   }
   delete [] dataPoints;
}
Color(255, 255, 0,  0)
```

## See also

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPath::GetPathData](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathdata)

[GraphicsPath::GetPathTypes](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathtypes)

[GraphicsPath::GetPointCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpointcount)

[PathData](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pathdata)

[PathPointType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pathpointtype)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)
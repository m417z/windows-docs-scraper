# GraphicsPath::GetPointCount

## Description

The **GraphicsPath::GetPointCount** method gets the number of points in this path's array of data points. This is the same as the number of types in the path's array of point types.

## Return value

Type: **INT**

This method returns the number of points in the path's array of data points.

## Remarks

A [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object has an array of points and an array of types. Each element in the array of types is a byte that specifies the point type and a set of flags for the corresponding element in the array of points. Possible point types and flags are listed in the [PathPointType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pathpointtype) enumeration.

#### Examples

The following example creates a path that has one ellipse and one line. The code calls the **GraphicsPath::GetPointCount** method to determine the number of data points stored in the path. Then the code calls the [GraphicsPath::GetPathPoints](https://learn.microsoft.com/previous-versions/ms535581(v=vs.85)) method to retrieve those data points. Finally, the code fills a small ellipse at each of the data points.

```cpp
VOID GetPointCountExample(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a path that has one ellipse and one line.
   GraphicsPath path;
   path.AddEllipse(10, 10, 200, 100);
   path.AddLine(220, 120, 300, 160);

   // Find out how many data points are stored in the path.
   INT count = path.GetPointCount();

   // Draw the path points.
   SolidBrush redBrush(Color(255, 255, 0, 0));
   PointF* points = new PointF[count];
   path.GetPathPoints(points, count);

   for(INT j = 0; j < count; ++j)
      graphics.FillEllipse(
         &redBrush,
         points[j].X - 3.0f,
         points[j].Y - 3.0f,
         6.0f,
         6.0f);

   delete [] points;
}
```

## See also

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[GetPathPoints Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathpoints(outpoint_inint))

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPath::GetPathData](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathdata)

[GraphicsPath::GetPathTypes](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathtypes)

[PathData](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pathdata)

[PathPointType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pathpointtype)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)
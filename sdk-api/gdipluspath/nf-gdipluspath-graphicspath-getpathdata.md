# GraphicsPath::GetPathData

## Description

The **GraphicsPath::GetPathData** method gets an array of points and an array of point types from this path. Together, these two arrays define the lines, curves, figures, and markers of this path.

## Parameters

### `pathData` [out]

Type: **[PathData](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pathdata)***

Pointer to a [PathData](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pathdata) object that receives the path data. The *Points* data member of the **PathData** object receives a pointer to an array of [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) objects that contains the path points. The *Types* data member of the **PathData** object receives a pointer to an array of bytes that contains the point types. The *Count* data member of the **PathData** object receives an integer that indicates the number of elements in the *Points* array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object has an array of points and an array of types. Each element in the array of types is a byte that specifies the point type and a set of flags for the corresponding element in the array of points. Possible point types and flags are listed in the [PathPointType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pathpointtype) enumeration.

You do not have to allocate or deallocate memory for the array of points or the array of types. The **GraphicsPath::GetPathData** method allocates memory for the arrays (points and types) that it returns. The [PathData](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pathdata) destructor deallocates the memory for those arrays.

#### Examples

The following example creates and draws a path that has a line, a rectangle, an ellipse, and a curve. The code gets the path's points and types by passing the address of a [PathData](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pathdata) object to the **GraphicsPath::GetPathData** method. Then the code draws each of the path's data points.

```cpp
VOID GetPathDataExample(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a path that has a line, a rectangle, an ellipse, and a curve.
   GraphicsPath path;

   PointF points[] = {
      PointF(200, 200),
      PointF(250, 240),
      PointF(200, 300),
      PointF(300, 310),
      PointF(250, 350)};

   path.AddLine(20, 100, 150, 200);
   path.AddRectangle(Rect(40, 30, 80, 60));
   path.AddEllipse(Rect(200, 30, 200, 100));
   path.AddCurve(points, 5);

   // Draw the path.
   Pen pen(Color(255, 0, 0, 255));
   graphics.DrawPath(&pen, &path);

   // Get the path data.
   PathData pathData;
   path.GetPathData(&pathData);

   // Draw the path's data points.
   SolidBrush brush(Color(255, 255, 0, 0));
   for(INT j = 0; j < pathData.Count; ++j)
   {
      graphics.FillEllipse(
         &brush,
         pathData.Points[j].X - 3.0f,
         pathData.Points[j].Y - 3.0f,
         6.0f,
         6.0f);
   }
}
```

## See also

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[GetPathPoints Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathpoints(outpoint_inint))

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPath::GetPathTypes](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathtypes)

[GraphicsPath::GetPointCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpointcount)

[PathData](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pathdata)

[PathPointType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pathpointtype)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)
# GraphicsPathIterator::GetCount

## Description

The **GraphicsPathIterator::GetCount** method returns the number of data points in the path.

## Return value

Type: **INT**

This method returns the number of data points in the path.

## Remarks

This [GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator) object is associated with a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object. That **GraphicsPath** object has an array of points and an array of types. Each element in the array of types is a byte that specifies the point type and a set of flags for the corresponding element in the array of points. Possible point types and flags are listed in the [PathPointType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pathpointtype) enumeration.

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object and then adds a rectangle and an ellipse to the path. The code passes the address of that **GraphicsPath** object to a [GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator) constructor to create an iterator that is associated with the path. The code calls the iterator's **GraphicsPathIterator::GetCount** method to determine the number of data points in the path. The call to [GraphicsPathIterator::Enumerate](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-enumerate) retrieves two arrays from the path: one that holds the path's data points and one that holds the path's point types. After the data points have been retrieved, the code calls the [FillEllipse](https://learn.microsoft.com/previous-versions/ms535967(v=vs.85)) method of a object to draw each of the data points.

```cpp

VOID GetCountExample(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a path that has a rectangle and an ellipse.
   GraphicsPath path;
   path.AddRectangle(Rect(20, 20, 60, 30));
   path.AddEllipse(Rect(20, 70, 100, 50));

   // Create an iterator, and associate it with the path.
   GraphicsPathIterator iterator(&path);

   // Get the number of data points in the path.
   INT count = iterator.GetCount();

   // Get the data points.
   PointF* points = new PointF[count];
   BYTE* types = new BYTE[count];
   iterator.Enumerate(points, types, count);

   // Draw the data points.
   SolidBrush brush(Color(255, 255, 0, 0));
   for(INT j = 0; j < count; ++j)
      graphics.FillEllipse(
         &brush,
         points[j].X - 3.0f,
         points[j].Y - 3.0f,
         6.0f,
         6.0f);

   delete points;
   delete types;
}

```

## See also

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[GetPathData](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathdata)

[GetPathPoints Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathpoints(outpoint_inint))

[GetPathTypes](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathtypes)

[GetPointCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpointcount)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator)

[GraphicsPathIterator::CopyData](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-copydata)

[GraphicsPathIterator::Enumerate](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-enumerate)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)
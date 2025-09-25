# GraphicsPathIterator::Rewind

## Description

The **GraphicsPathIterator::Rewind** method rewinds this iterator to the beginning of its associated path.

## Remarks

The first time you call the
**NextSubpath** method of an iterator, it gets the first figure (subpath) of that iterator's associated path. The second time, it gets the second figure, and so on. When you call **GraphicsPathIterator::Rewind**, the sequence starts over; that is, after you call **GraphicsPathIterator::Rewind**, the next call to [GraphicsPathIterator::NextSubpath](https://learn.microsoft.com/previous-versions/ms535462(v=vs.85)) gets the first figure in the path. The [GraphicsPathIterator::NextMarker](https://learn.microsoft.com/previous-versions/ms535464(v=vs.85)) and [GraphicsPathIterator::NextPathType](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-nextpathtype) methods behave similarly.

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object and adds five figures to the path. The code passes the address of that **GraphicsPath** object to a [GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator) constructor to create an iterator that is associated with the path. The code calls the iterator's [GraphicsPathIterator::NextSubpath](https://learn.microsoft.com/previous-versions/ms535462(v=vs.85)) method twice to retrieve the second figure in the path. The [DrawPath](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawpath) method draws that path in blue. Next, the code calls the **GraphicsPathIterator::Rewind** method and then calls **GraphicsPathIterator::NextSubpath** once to obtain the first figure in the path. The **DrawPath** method draws that figure in red.

```cpp

VOID RewindExample(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a graphics path with five figures (subpaths).
   GraphicsPath path;

   path.AddRectangle(Rect(20, 20, 60, 30));   // Subpath count is 1.

   path.AddLine(100, 20, 160, 50);            // Subpath count is 2.
   path.AddArc(180, 20, 60, 30, 0.0f, 180.0f);

   path.AddRectangle(Rect(260, 20, 60, 30));  // Subpath count is 3.

   path.AddLine(340, 20, 400, 50);            // Subpath count is 4.
   path.AddArc(340, 20, 60, 30, 0.0f, 180.0f);
   path.CloseFigure();

   path.AddRectangle(Rect(420, 20, 60, 30));  // Subpath count is 5.

   // Create an iterator, and associate it with the path.
   GraphicsPathIterator iterator(&path);

   // Get the second subpath by calling NextSubpath twice.
   GraphicsPath subpath;
   BOOL isClosed;
   INT count;
   count = iterator.NextSubpath(&subpath, &isClosed);
   count = iterator.NextSubpath(&subpath, &isClosed);

   // Draw the second figure in blue.
   Pen bluePen(Color(255, 0, 0, 255));
   graphics.DrawPath(&bluePen, &subpath);

   // Rewind the iterator, and get the first figure in the path.
   iterator.Rewind();
   count = iterator.NextSubpath(&subpath, &isClosed);

   // Draw the first figure in red.
   Pen redPen(Color(255, 255, 0, 0));
   graphics.DrawPath(&redPen, &subpath);
}

```

## See also

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator)

[GraphicsPathIterator::NextMarker Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-nextmarker(outconstgraphicspath))

[GraphicsPathIterator::NextPathType](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-nextpathtype)

[GraphicsPathIterator::NextSubpath Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-nextsubpath(outconstgraphicspath_outbool))

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)
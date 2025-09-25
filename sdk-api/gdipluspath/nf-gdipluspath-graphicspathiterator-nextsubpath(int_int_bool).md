## Description

The **GraphicsPathIterator::NextSubpath** method gets the starting index and the ending index of the next subpath (figure) in this iterator's associated path.

## Parameters

### `startIndex`

Pointer to an **INT** that receives the starting index.

### `endIndex`

Pointer to an **INT** that receives the ending index.

### `isClosed`

Pointer to a **BOOL** that receives a value that indicates whether the obtained figure is closed.
If the figure is closed, the received value is **TRUE**; otherwise, the received value is **FALSE**.

## Return value

This method returns the number of data points in the next figure.
If there are no more figures in the path, this method returns 0.

## Remarks

The first time you call the **GraphicsPathIterator::NextSubpath** method of an iterator, it gets the indices for the first figure (subpath) of that iterator's associated path.
The second time, it gets the indices for the second figure, and so on.
Each time you call **GraphicsPathIterator::NextSubpath**, it returns the number of data points in the figure whose indices were retrieved.
When there are no figures remaining, it returns 0.

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object and adds five figures to the path.
The code passes the address of that *GraphicsPath* object to a **GraphicsPathIterator** constructor to create an iterator that is associated with the path. The code calls the iterator's **GraphicsPathIterator::NextSubpath** method three times to obtain the starting index and the ending index of the path's third figure.
Then the code calls the iterator's **GraphicsPathIterator::CopyData** method to retrieve the third figure's data points.

```cpp
VOID NextSubpathExample2(HDC hdc)
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

   // Call NextSubpath three times to get the starting and ending
   // indices for the third figure.
   INT start;
   INT end;
   BOOL isClosed;
   INT count;
   count = iterator.NextSubpath(&start, &end, &isClosed);
   count = iterator.NextSubpath(&start, &end, &isClosed);
   count = iterator.NextSubpath(&start, &end, &isClosed);

   // Get the third figure's data points.
   PointF* points = new PointF[count];
   BYTE* types = new BYTE[count];
   iterator.CopyData(points, types, start, end);

   // Draw the third figure's data points.
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

[GraphicsPath::GetPathData](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathdata)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator)

[GraphicsPathIterator::CopyData](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-copydata)

[GraphicsPathIterator::GetSubpathCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-getsubpathcount)

[GraphicsPathIterator::NextMarker Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-nextmarker(outconstgraphicspath))

[NextSubpath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-nextsubpath(outconstgraphicspath_outbool))

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)
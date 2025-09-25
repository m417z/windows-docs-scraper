# GraphicsPathIterator::NextMarker(OUT const GraphicsPath)

## Description

The **GraphicsPathIterator::NextMarker** method gets the next marker-delimited section of this iterator's associated path.

## Parameters

### `path` [out]

Type: **[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)***

Pointer to a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object. This method sets the data points of this **GraphicsPath** object to match the data points of the retrieved section.

## Return value

Type: **INT**

This method returns the number of data points in the retrieved section. If there are no more marker-delimited sections to retrieve, this method returns 0.

## Remarks

A path has an array of data points that define its lines and curves. You can call a path's [SetMarker](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-setmarker) method to designate certain points in the array as markers. Those marker points divide the path into sections.

The first time you call the **GraphicsPathIterator::NextMarker** method of an iterator, it gets the first marker-delimited section of that iterator's associated path. The second time, it gets the second section, and so on. Each time you call [GraphicsPathIterator::NextSubpath](https://learn.microsoft.com/previous-versions/ms535462(v=vs.85)), it returns the number of data points in the retrieved section. When there are no sections remaining, it returns 0.

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object and adds five figures to the path. The calls to the [SetMarker](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-setmarker) method place two markers in the path. The first marker is at the end of a figure, and the second marker is in the middle of a figure. The code passes the address of the **GraphicsPath** object to a [GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator) constructor to create an iterator that is associated with the path. Then the code calls the iterator's **GraphicsPathIterator::NextMarker** method twice to obtain the second marker-delimited section of the path. Finally, the code draws the retrieved section of the path.

```cpp

VOID NextMarkerExample(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a graphics path with five figures (subpaths).
   GraphicsPath path;

   path.AddRectangle(Rect(20, 20, 60, 30));
   path.SetMarker();                          // first marker

   path.AddLine(100, 20, 160, 50);
   path.AddArc(180, 20, 60, 30, 0.0f, 180.0f);

   path.AddRectangle(Rect(260, 20, 60, 30));

   path.AddLine(340, 20, 400, 50);
   path.SetMarker();                          // second marker
   path.AddArc(340, 20, 60, 30, 0.0f, 180.0f);
   path.CloseFigure();

   path.AddRectangle(Rect(420, 20, 60, 30));

   // Create an iterator, and associate it with the path.
   GraphicsPathIterator iterator(&path);

   // Get the second marker-delimited section by calling NextMarker twice.
   GraphicsPath section;
   INT count;
   count = iterator.NextMarker(&section);
   count = iterator.NextMarker(&section);

   // The variable "count" now holds the number of
   // data points in the second marker-delimited section.

   // Draw the retrieved section.
   Pen bluePen(Color(255, 0, 0, 255));
   graphics.DrawPath(&bluePen, &section);
}
```

## See also

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[GetPathData](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathdata)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator)

[GraphicsPathIterator::NextSubpath Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-nextsubpath(outconstgraphicspath_outbool))

[NextMarker](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-nextmarker(outconstgraphicspath))

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)
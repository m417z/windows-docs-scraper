# GraphicsPathIterator::NextSubpath(OUT const GraphicsPath,OUT BOOL)

## Description

The **GraphicsPathIterator::NextSubpath** method gets the next figure (subpath) from this iterator's associated path.

## Parameters

### `path` [out]

Type: **[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)***

Pointer to a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object. This method sets the data points of this **GraphicsPath** object to match the data points of the retrieved figure.

### `isClosed` [out]

Type: **BOOL***

Pointer to a **BOOL** that receives a value that indicates whether the retrieved figure is closed. If the figure is closed, the received value is **TRUE**; otherwise, the received value is **FALSE**.

## Return value

Type: **INT**

This method returns the number of data points in the retrieved figure. If there are no more figures to retrieve, this method returns 0.

## Remarks

The first time you call the **GraphicsPathIterator::NextSubpath** method of an iterator, it gets the first figure (subpath) of that iterator's associated path. The second time, it gets the second figure, and so on. Each time you call **GraphicsPathIterator::NextSubpath**, it returns the number of data points in the retrieved figure. When there are no figures remaining, it returns 0.

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object and adds five figures (also called subpaths) to the path. The code passes the address of the **GraphicsPath** object to a [GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator) constructor to create an iterator that is associated with the path. The code calls the iterator's **GraphicsPathIterator::NextSubpath** method twice to retrieve the second figure (subpath) from the path. Then the code calls the [DrawPath](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawpath) method of a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object to draw that individual subpath.

```cpp

VOID NextSubpathExample(HDC hdc)
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

   // The variable "count" now holds the number of
   // data points in the second subpath.

   // Draw the retrieved subpath.
   Pen bluePen(Color(255, 0, 0, 255));
   graphics.DrawPath(&bluePen, &subpath);
}

```

## See also

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[GetPathData](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathdata)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator)

[GraphicsPathIterator::GetSubpathCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-getsubpathcount)

[GraphicsPathIterator::NextMarker Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-nextmarker(outconstgraphicspath))

[NextSubpath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-nextsubpath(outconstgraphicspath_outbool))

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)
# CustomLineCap::GetStrokeJoin

## Description

The **CustomLineCap::GetStrokeJoin** method returns the style of [LineJoin](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linejoin) used to join multiple lines in the same [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object.

## Return value

Type: **[LineJoin](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linejoin)**

This method returns the style of line join.

## Remarks

The [CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap) object uses a path and a stroke to define the end cap. The stroke is contained in a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object, which can contain more than one figure. If there is more than one figure in the **GraphicsPath** object, the stroke join determines how their joint is graphically displayed.

#### Examples

The following example creates a [CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap) object with a stroke join. It then gets the stroke join and assigns it as the line join of a [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object that it then uses to draw a line.

```cpp
VOID Example_GetStrokeJoin(HDC hdc)
{
   Graphics graphics(hdc);

   //Create a Path, and add two lines to it.
   Point points[3] = {Point(-15, -15), Point(0, 0), Point(15, -15)};
   GraphicsPath capPath;
   capPath.AddLines(points, 3);

   // Create a CustomLineCap object.
   CustomLineCap custCap(NULL, &capPath);

   // Set the stroke join for custCap.
   custCap.SetStrokeJoin(LineJoinBevel);

   // Get the stroke join from custCap.
   LineJoin strokeJoin = custCap.GetStrokeJoin();

   // Create a Pen object, assign strokeJoin as the line join, and draw two
   // joined lines in a path.
   Pen strokeJoinPen(Color(255, 255, 0, 0), 15.1f);
   strokeJoinPen.SetLineJoin(strokeJoin);
   GraphicsPath joinPath;
   joinPath.AddLine(Point(10, 10), Point(10, 200));
   joinPath.AddLine(Point(10, 200), Point(200, 200));
   graphics.DrawPath(&strokeJoinPen, &joinPath);
}
```

## See also

[CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap)

[LineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linecap)

[LineJoin](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linejoin)
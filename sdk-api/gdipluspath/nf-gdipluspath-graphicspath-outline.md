# GraphicsPath::Outline

## Description

The **GraphicsPath::Outline** method transforms and flattens this path, and then converts this path's data points so that they represent only the outline of the path.

## Parameters

### `matrix` [in]

Type: **const [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Optional. Pointer to a [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that specifies the transformation. If this parameter is **NULL**, no transformation is applied. The default value is **NULL**.

### `flatness` [in]

Type: **REAL**

Optional. Real number that specifies the maximum error between the path and its flattened approximation. Reducing the flatness increases the number of line segments in the approximation. The default value is FlatnessDefault, which is a constant defined in Gdiplusenums.h.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object stores a collection of data points that represent lines and curves. The **GraphicsPath::Outline** method changes those data points, and the original data points are lost.

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object and calls the [GraphicsPath::AddClosedCurve](https://learn.microsoft.com/previous-versions/ms535615(v=vs.85)) method to add a closed cardinal spline to the path. The code calls the [GraphicsPath::Widen](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-widen) method to widen the path and then draws the path. Next, the code calls the path's **Outline** method. The code calls the [TranslateTransform](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-translatetransform) method of a Graphics object so that the outlined path drawn by the subsequent call to [DrawPath](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawpath) sits to the right of the first path.

```cpp

VOID OutlineExample(HDC hdc)
{
   Graphics graphics(hdc);

   Pen bluePen(Color(255, 0, 0, 255));
   Pen greenPen(Color(255, 0, 255,  0), 10);

   PointF points[] = {
      PointF(20.0f, 20.0f),
      PointF(160.0f, 100.0f),
      PointF(140.0f, 60.0f),
      PointF(60.0f, 100.0f)};

   GraphicsPath path;
   path.AddClosedCurve(points, 4);

   path.Widen(&greenPen);
   graphics.DrawPath(&bluePen, &path);

   path.Outline();

   graphics.TranslateTransform(180.0f, 0.0f);
   graphics.DrawPath(&bluePen, &path);
}

```

## See also

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPath::Flatten](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-flatten)

[GraphicsPath::Warp](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-warp)

[GraphicsPath::Widen](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-widen)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)
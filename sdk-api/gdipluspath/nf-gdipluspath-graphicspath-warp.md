# GraphicsPath::Warp

## Description

The **GraphicsPath::Warp** method applies a warp transformation to this path. The **GraphicsPath::Warp** method also flattens (converts to a sequence of straight lines) the path.

## Parameters

### `destPoints` [in]

Type: **const [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)***

Pointer to an array of points that, along with the *srcRect* parameter, defines the warp transformation.

### `count` [in]

Type: **INT**

Integer that specifies the number of points in the
*destPoints* array. The value of this parameter must be 3 or 4.

### `srcRect` [in, ref]

Type: **const [RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)**

Reference to a rectangle that, along with the *destPoints* parameter, defines the warp transformation.

### `matrix` [in]

Type: **const [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Optional. Pointer to a [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that represents a transformation to be applied along with the warp. If this parameter is **NULL**, no transformation is applied. The default value is **NULL**.

### `warpMode` [in]

Type: **[WarpMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-warpmode)**

Optional. Element of the [WarpMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-warpmode) enumeration that specifies the kind of warp to be applied. The default value is WarpModePerspective.

### `flatness` [in]

Type: **REAL**

Optional. Real number that influences the number of line segments that are used to approximate the original path. Small values specify that many line segments are used, and large values specify that few line segments are used. The default value is FlatnessDefault, which is a constant defined in Gdiplusenums.h.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object stores a collection of data points that represent lines and curves. The **GraphicsPath::Warp** method converts those data points so that they represent only lines. The *flatness* parameter influences the number of lines that are stored. The original data points that represented curves are lost.

If the
*count* parameter has a value of 4, the warp transformation is defined as shown in the following table.

| Source point | Destination point |
| --- | --- |
| Upper-left corner of *srcRect* | *destPoints*[0] |
| Upper-right corner of *srcRect* | *destPoints*[1] |
| Lower-left corner of *srcRect* | *destPoints*[2] |
| Lower-right corner of *srcRect* | *destPoints*[3] |

A transformation specified by a source rectangle and four destination points is capable of mapping a rectangle to an arbitrary quadrilateral that is not necessarily a parallelogram.

If the count parameter has a value of 3, the warp transformation is defined as shown in the following table.

| Source point | Destination point |
| --- | --- |
| Upper-left corner of *srcRect* | *destPoints*[0] |
| Upper-right corner of *srcRect* | *destPoints*[1] |
| Lower-left corner of *srcRect* | *destPoints*[2] |

A transformation specified by a source rectangle and three destination points maps rectangles to parallelograms.

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object and adds a closed figure to the path. The code defines a warp transformation by specifying a source rectangle and an array of four destination points. The source rectangle and destination points are passed to the **Warp** method. The code draws the path twice: once before it has been warped and once after it has been warped.

```cpp

VOID WarpExample(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a path.
   PointF points[] ={
      PointF(20.0f, 60.0f),
      PointF(30.0f, 90.0f),
      PointF(15.0f, 110.0f),
      PointF(15.0f, 145.0f),
      PointF(55.0f, 145.0f),
      PointF(55.0f, 110.0f),
      PointF(40.0f, 90.0f),
      PointF(50.0f, 60.0f)};

   GraphicsPath path;
   path.AddLines(points, 8);
   path.CloseFigure();

   // Draw the path before applying a warp transformation.
   Pen bluePen(Color(255, 0, 0, 255));
   graphics.DrawPath(&bluePen, &path);

   // Define a warp transformation, and warp the path.
   RectF srcRect(10.0f, 50.0f, 50.0f, 100.0f);

   PointF destPts[] = {
      PointF(220.0f, 10.0f),
      PointF(280.0f, 10.0f),
      PointF(100.0f, 150.0f),
      PointF(400.0f, 150.0f)};

   path.Warp(destPts, 4, srcRect);

   // Draw the warped path.
   graphics.DrawPath(&bluePen, &path);

   // Draw the source rectangle and the destination polygon.
   Pen blackPen(Color(255, 0, 0, 0));
   graphics.DrawRectangle(&blackPen, srcRect);
   graphics.DrawLine(&blackPen, destPts[0], destPts[1]);
   graphics.DrawLine(&blackPen, destPts[0], destPts[2]);
   graphics.DrawLine(&blackPen, destPts[1], destPts[3]);
   graphics.DrawLine(&blackPen, destPts[2], destPts[3]);
}

```

## See also

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Flattening Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-flattening-paths-about)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPath::Flatten](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-flatten)

[GraphicsPath::Outline](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-outline)

[GraphicsPath::Widen](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-widen)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[WarpMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-warpmode)
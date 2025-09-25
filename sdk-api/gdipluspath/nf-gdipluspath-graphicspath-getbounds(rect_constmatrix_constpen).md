# GraphicsPath::GetBounds(OUT Rect,IN const Matrix,IN const Pen)

## Description

The **GraphicsPath::GetBounds** method gets a bounding rectangle for this path.

## Parameters

### `bounds` [out]

Type: **[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)***

Pointer to a [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect) object that receives the bounding rectangle.

### `matrix` [in]

Type: **const [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Optional. Pointer to a [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that specifies a transformation to be applied to this path before the bounding rectangle is calculated. This path is not permanently transformed; the transformation is used only during the process of calculating the bounding rectangle. The default value is **NULL**.

### `pen` [in]

Type: **const [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)***

Optional. Pointer to a [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object that influences the size of the bounding rectangle. The bounding rectangle received in *bounds* will be large enough to enclose this path when the path is drawn with the pen specified by this parameter. This ensures that the path is enclosed by the bounding rectangle even if the path is drawn with a wide pen. The default value is **NULL**.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The rectangle returned by this method might be larger than necessary to enclose the path as drawn by the specified pen. The rectangle is calculated to allow for the pen's miter limit at sharp corners and to allow for the pen's end caps.

#### Examples

The following example creates a path that has one curve and one ellipse. The code draws the path with a thick yellow pen and a thin black pen. The **GraphicsPath::GetBounds** method receives the address of the thick yellow pen and calculates a bounding rectangle for the path. Then the code draws the bounding rectangle.

```cpp
VOID GetBoundsExample(HDC hdc)
{
   Graphics graphics(hdc);
   Pen blackPen(Color(255, 0, 0, 0), 1);
   Pen yellowPen(Color(255, 255, 255, 0), 10);
   Pen redPen(Color(255, 255, 0, 0), 1);

   Point pts[] = {Point(120,120),
                  Point(200,130),
                  Point(150,200),
                  Point(130,180)};

   // Create a path that has one curve and one ellipse.
   GraphicsPath path;
   path.AddClosedCurve(pts, 4);
   path.AddEllipse(120, 220, 100, 40);

   // Draw the path with a thick yellow pen and a thin black pen.
   graphics.DrawPath(&yellowPen, &path);
   graphics.DrawPath(&blackPen, &path);

   // Get the path's bounding rectangle.
   Rect rect;
   path.GetBounds(&rect, NULL, &yellowPen);
   graphics.DrawRectangle(&redPen, rect);
}

Color(255, 0, 0, 0)Color(255, 255, 0,  0)
```

## See also

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)
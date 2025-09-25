# GraphicsPath::AddPath

## Description

The **GraphicsPath::AddPath** method adds a path to this path.

## Parameters

### `addingPath` [in]

Type: **const [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)***

Pointer to the path to be added.

### `connect` [in]

Type: **BOOL**

**BOOL** value that specifies whether the first figure in the added path is part of the last figure in this path.

#### TRUE

Specifies that (if possible) the first figure in the added path is part of the last figure in this path.

#### FALSE

Specifies that the first figure in the added path is separate from the last figure in this path.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Even if the value of the *connect* parameter is **TRUE**, this method might not be able to make the first figure of the added path part of the last figure of this path. If either of those figures is closed, then they must remain separate figures.

#### Examples

The following example creates two [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) objects: *path1* and *path2*. The code adds an open figure consisting of an arc and a Bézier spline to each path. The code calls the **GraphicsPath::AddPath** method of *path1* to add *path2* to *path1*. The second argument is **TRUE**, which specifies that all four items (two arcs and two Bézier splines) belong to the same figure.

```cpp
VOID AddPathExample(HDC hdc)
{
   Graphics graphics(hdc);

   GraphicsPath path1;
   path1.AddArc(10, 10, 50, 20, 0.0f, 150.0f);
   path1.AddBezier(10, 50, 60, 50, 10, 80, 60, 80);

   GraphicsPath path2;
   path2.AddArc(10, 110, 50, 20, 0.0f, 150.0f);
   path2.AddBezier(10, 150, 60, 150, 10, 180, 60, 180);

   path1.AddPath(&path2, TRUE);

   Pen pen(Color(255, 0, 0, 255));
   graphics.DrawPath(&pen, &path1);
}
```

## See also

[AddEllipse Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addellipse(inconstrect_))

[AddRectangle Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-addrectangle(inconstrect_))

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)
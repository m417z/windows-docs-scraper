# GraphicsPath::GetPathTypes

## Description

The **GraphicsPath::GetPathTypes** method gets this path's array of point types.

## Parameters

### `types` [out]

Type: **BYTE***

Pointer to an array that receives the point types. You must allocate memory for this array. You can call the [GraphicsPath::GetPointCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpointcount) method to determine the required size of the array.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the *types* array. Set this parameter equal to the return value of the [GraphicsPath::GetPointCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpointcount) method.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object has an array of points and an array of types. Each element in the array of types is a byte that specifies the point type and a set of flags for the corresponding element in the array of points. Possible point types and flags are listed in the [PathPointType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pathpointtype) enumeration.

#### Examples

The following example creates a path and adds a sequence of three connected lines to the path. The code calls the [GraphicsPath::GetPointCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpointcount) method to determine the number of bytes in the path's array of point types and then allocates a buffer large enough to hold that array. Then the code calls the **GraphicsPath::GetPathTypes** method to fill the buffer with the array of point types.

```cpp
GraphicsPath path;
Point pts[] = {Point(0, 0), Point(2, 2), Point(3, 3), Point(0, 5)};
path.AddLines(pts, 4);
INT num = path.GetPointCount();
BYTE* pTypes = new BYTE[num];
path.GetPathTypes(pTypes, num);
```

## See also

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[GetPathPoints Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathpoints(outpoint_inint))

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPath::GetPathData](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathdata)

[GraphicsPath::GetPointCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpointcount)

[PathData](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pathdata)

[PathPointType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pathpointtype)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)
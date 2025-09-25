# GraphicsPathIterator::Enumerate

## Description

The **GraphicsPathIterator::Enumerate** method copies the path's data points to a [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) array and copies the path's point types to a **BYTE** array.

## Parameters

### `points` [out]

Type: **[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)***

Pointer to an array that receives the path's data points.

### `types` [out]

Type: **BYTE***

Pointer to an array that receives the path's point types.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the *points* array. This is the same as the number of elements in the *types* array.

## Return value

Type: **INT**

This method returns the number of points retrieved.

## Remarks

This
[GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator) object is associated with a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object. That **GraphicsPath** object has an array of points and an array of types. Each element in the array of types is a byte that specifies the point type and a set of flags for the corresponding element in the array of points. Possible point types and flags are listed in the [PathPointType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pathpointtype) enumeration.

You can call the [GraphicsPathIterator::GetCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-getcount) method to determine the number of data points in the path. The *points* parameter points to a buffer that receives the data points, and the *types* parameter points to a buffer that receives the types. Before you call the **GraphicsPathIterator::Enumerate** method, you must allocate memory for those buffers. The size of the *points* buffer should be the return value of **GraphicsPathIterator::GetCount** multiplied by **sizeof(PointF)**. The size of the types buffer should be the return value of **GraphicsPathIterator::GetCount**.

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object and adds three lines to the path. The code creates a [GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator) object and calls its **GraphicsPathIterator::Enumerate** method to retrieve the path's data points and point types. Then the code displays the count returned by the **GraphicsPathIterator::Enumerate** method.

```cpp

#define BUFFER_SIZE 30
TCHAR numPointsEnum[BUFFER_SIZE];

// Add some lines to a path.
Point pts[] = {Point(20, 20),
                Point(100, 20),
                Point(100, 50),
                Point(20, 50)};
GraphicsPath path;
path.AddLines(pts, 4);

// Create a GraphicsPathIterator object, and associate it with the path.
GraphicsPathIterator pathIterator(&path);

// Create destination arrays, and copy the path data to them.
UINT c = pathIterator.GetCount();
PointF* pEnumPoints = new PointF[c];
BYTE* pTypes = new BYTE[c];
INT count = pathIterator.Enumerate(pEnumPoints, pTypes, c);

// Confirm that the points were enumerated.
StringCchPrintf(
   numPointsEnum, BUFFER_SIZE, TEXT("%d points were enumerated."), count);

MessageBox(hWnd, numPointsEnum, TEXT("Enumerate"), NULL);

delete[] pEnumPoints;
delete[] pTypes;

```

## See also

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[GetPathData](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathdata)

[GetPathPoints Methods](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathpoints(outpoint_inint))

[GetPathTypes](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpathtypes)

[GetPointCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-getpointcount)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator)

[GraphicsPathIterator::CopyData](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-copydata)

[GraphicsPathIterator::GetCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-getcount)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)
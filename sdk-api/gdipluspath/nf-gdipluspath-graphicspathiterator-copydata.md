# GraphicsPathIterator::CopyData

## Description

The **GraphicsPathIterator::CopyData** method copies a subset of the path's data points to a [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) array and copies a subset of the path's point types to a **BYTE** array.

## Parameters

### `points` [out]

Type: **[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)***

Pointer to an array that receives a subset of the path's data points.

### `types` [out]

Type: **BYTE***

Pointer to an array that receives a subset of the path's point types.

### `startIndex` [in]

Type: **INT**

Integer that specifies the starting index of the points and types to be copied.

### `endIndex` [in]

Type: **INT**

Integer that specifies the ending index of the points and types to be copied.

## Return value

Type: **INT**

This method returns the number of points copied. This is the same as the number of types copied.

## Remarks

This [GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator) object is associated with a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object. That **GraphicsPath** object has an array of points and an array of types. Each element in the array of types is a byte that specifies the point type and a set of flags for the corresponding element in the array of points. Possible point types and flags are listed in the [PathPointType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pathpointtype) enumeration.

You can call the [GraphicsPathIterator::GetCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-getcount) method to determine the number of data points in the path.

#### Examples

The following example creates a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object and adds three lines to the path. The code creates a [GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator)> object and calls its **GraphicsPathIterator::CopyData** method to retrieve the path's points and point types. Then the code displays the count returned by the **GraphicsPathIterator::CopyData** method.

```cpp

#define BUFFER_SIZE 30
TCHAR numPointsCopied[BUFFER_SIZE];

// Create the points for three lines in a path.
Point pts[] = { Point(20, 20),
                Point(100, 20),
                Point(100, 50),
                Point(20, 50) };
GraphicsPath path;
path.AddLines(pts, 4); // Add the lines to the path.

// Create a GraphicsPathIterator object and associate it with the path.
GraphicsPathIterator pathIterator(&path);

// Create destination arrays, and copy the path data to them.
PointF* pCopiedPoints = new PointF[4];
BYTE* pTypes = new BYTE[4];
INT count = pathIterator.CopyData(pCopiedPoints, pTypes, 0, 3);

// Confirm that the points copied.
StringCchPrintf(
   numPointsCopied, BUFFER_SIZE, TEXT("%d points were copied."), count);

MessageBox(hWnd, numPointsCopied, TEXT("CopyData"), NULL);

delete[] pCopiedPoints;
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

[GraphicsPathIterator::Enumerate](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-enumerate)

[GraphicsPathIterator::GetCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-getcount)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)
# Region::GetRegionScans(Matrix*,RectF*,INT*)

## Description

The **Region::GetRegionScans** method gets an array of rectangles that approximate this region.
The region is transformed by a specified matrix before the rectangles are calculated.

## Parameters

### `matrix`

Pointer to a [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix) object that is used to transform the region.

### `rects`

Pointer to an array of [RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf) objects that receives the rectangles.

### `count`

Pointer to an **INT** that receives a value that indicates the number of rectangles that approximate this region.
The value is valid even if **rects** is a **NULL** pointer.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The **Region::GetRegionScansCount** method can be used first to determine the number of rectangles.
Then, you can allocate a buffer that is the correct size and set the *rects* parameter to point to the buffer.

#### Examples

The following example creates a region from a path and gets a set of rectangles that approximate the region.
The code then draws each of the rectangles.

```cpp
VOID Example_GetRegionScansRectF(HDC hdc)
{
   Graphics graphics(hdc);

   SolidBrush solidBrush(Color(255, 255, 0, 0));
   Pen pen(Color(255, 0, 0, 0));
   GraphicsPath path;
   Matrix matrix;
   RectF* rects = NULL;
   INT count = 0;

   // Create a region from a path.
   path.AddEllipse(10, 10, 50, 300);
   Region pathRegion(&path);
   graphics.FillRegion(&solidBrush, &pathRegion);

   // Get the rectangles.
   graphics.GetTransform(&matrix);
   count = pathRegion.GetRegionScansCount(&matrix);
   rects = (RectF*)malloc(count*sizeof(RectF));
   pathRegion.GetRegionScans(&matrix, rects, &count);

   // Draw the rectangles.
   for(INT j = 0; j < count; ++j)
      graphics.DrawRectangle(&pen, rects[j]);

   free(rects);
}
```

## See also

[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)

[Region::GetRegionScansCount](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-region-getregionscanscount)

[Hit Testing with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-hit-testing-with-a-region-use)

[Regions](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-regions-about)
# Region::GetRegionScansCount

## Description

The **Region::GetRegionScansCount** method gets the number of rectangles that approximate this region. The region is transformed by a specified matrix before the rectangles are calculated.

## Parameters

### `matrix` [in]

Type: **const [Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)***

Pointer to a matrix that is used to transform the region.

## Return value

Type: **UINT**

This method returns an integer that indicates the number of rectangles that approximate this region.

## Remarks

The **Region::GetRegionScansCount** method can be used before the [GetRegionScans](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-region-getregionscans(inconstmatrix_outrect_outint)) method to determine the number of rectangles. Then, you can allocate a buffer that is the correct size to store the rectangles that are obtained with the GetRegionScans method.

#### Examples

The following example creates a region from a path and gets a set of rectangles that approximate the region. The code then draws each of the rectangles.

```cpp
VOID Example_GetRegionScansCount(HDC hdc)
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

[Matrix](https://learn.microsoft.com/windows/desktop/api/gdiplusmatrix/nl-gdiplusmatrix-matrix)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)

[Region::GetRegionScans Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-region-getregionscans(inconstmatrix_outrect_outint))
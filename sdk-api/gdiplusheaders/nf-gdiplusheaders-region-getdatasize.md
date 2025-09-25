# Region::GetDataSize

## Description

The **Region::GetDataSize** method gets the number of bytes of data that describes this region.

## Return value

Type: **UINT**

This method returns the number of bytes of region data.

## Remarks

The **Region::GetDataSize** method can be used before the [Region::GetData](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-region-getdata) method to determine the number of bytes needed to store the region data. Then, you can allocate a buffer that is the correct size to store the region data that is obtained by the **Region::GetData**.

#### Examples

The following example creates a region from a path and then gets the data that describes the region.

```cpp
VOID Example_GetData(HDC)
{
   Point points[] =
      Point(110, 20),
      Point(120, 30),
      Point(100, 60),
      Point(120, 70),
      Point(150, 60),
      Point(140, 10)};

   GraphicsPath path;
   path.AddClosedCurve(points, 6);

   // Create a region from a path.
   Region pathRegion(&path);

   // Get the region data.
   UINT bufferSize = 0;
   UINT sizeFilled = 0;
   BYTE* pData = NULL;

   bufferSize = pathRegion.GetDataSize();
   pData = (BYTE*)malloc(bufferSize*sizeof(BYTE));
   pathRegion.GetData(pData, bufferSize, &sizeFilled);
}
```

## See also

[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)

[Region::GetData](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-region-getdata)
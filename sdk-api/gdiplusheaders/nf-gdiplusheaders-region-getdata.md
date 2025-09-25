# Region::GetData

## Description

The **Region::GetData** method gets data that describes this region.

## Parameters

### `buffer` [out]

Type: **BYTE***

Pointer to an array of
**BYTE** values that receives the region data.

### `bufferSize` [in]

Type: **UINT**

Integer that specifies the size, in bytes, of the
*buffer* array. The size of the
*buffer* array can be greater than or equal to the number of bytes required to store the region data. The exact number of bytes required can be determined by calling the
[Region::GetDataSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-region-getdatasize) method.

### `sizeFilled` [out]

Type: **UINT***

Optional. Pointer to an
**INT** that receives the number of bytes of data actually received by the
*buffer* array. The default value is **NULL**.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the
**Status** enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The
[Region::GetDataSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-region-getdatasize) method can be used before the **Region::GetData** method to determine the number of bytes needed to store the region data. Then, you can allocate a buffer that is the correct size to store the region data and set the
*buffer* parameter to point to the buffer.

#### Examples

The following example creates a region from a path and then gets the data that describes the region.

```cpp
VOID Example_GetData(HDC)

{
   Point points[] = {
      Point(110, 20)
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

   pData = new BYTE[bufferSize];
   pathRegion.GetData(pData, bufferSize, &sizeFilled);

   // Inspect or use the region data.
   ...
   delete pData;
}
```
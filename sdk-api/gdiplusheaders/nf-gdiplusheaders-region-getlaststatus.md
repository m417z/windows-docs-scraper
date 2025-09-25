# Region::GetLastStatus

## Description

The **Region::GetLastStatus** method returns a value that indicates the nature of this
[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region) object's most recent method failure.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

The **Region::GetLastStatus** method returns an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If no methods invoked on this
[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region) object have failed since the previous call to **Region::GetLastStatus**, then **Region::GetLastStatus** returns **Ok**.

If at least one method invoked on this
[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region) object has failed since the previous call to **Region::GetLastStatus**, then **Region::GetLastStatus** returns a value that indicates the nature of the most recent failure.

## Remarks

You can call **Region::GetLastStatus** immediately after constructing a
[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region) object to determine whether the constructor succeeded.

The first time you call the **Region::GetLastStatus** method of a
[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region) object, it returns **Ok** if the constructor succeeded and all methods invoked so far on the
**Region** object succeeded. Otherwise, it returns a value that indicates the nature of the most recent failure.

#### Examples

The following example creates a region from a path. Next, the code calls [Region::GetBounds Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-region-getbounds(outrectf_inconstgraphics)), followed by a call to [Region::GetDataSize](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-region-getdatasize). The code then calls **Region::GetLastStatus**. If all method calls have been successful up to this point, **Region::GetLastStatus** returns **Ok**.

```cpp
VOID Example_GetLastStatus(HDC hdc)
{
   Graphics graphics(hdc);

   Point points[] = {
      Point(110, 20),
      Point(120, 30),
      Point(100, 60),
      Point(120, 70),
      Point(150, 60),
      Point(140, 10)};

   Rect rect;
   UINT size;
   GraphicsPath path;

   path.AddClosedCurve(points, 6);

   // Create a region from a path.
   Region pathRegion(&path);

   pathRegion.GetBounds(&rect, &graphics);
   size = pathRegion.GetDataSize();

   if(pathRegion.GetLastStatus() == Ok)
   {
       // All methods called thus far have been successful.
   }
}
```
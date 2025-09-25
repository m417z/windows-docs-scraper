# CachedBitmap::GetLastStatus

## Description

The **CachedBitmap::GetLastStatus** method returns a value that indicates whether this
[CachedBitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-cachedbitmap) object was constructed successfully.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If this
[CachedBitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-cachedbitmap) object was constructed successfully, the
**CachedBitmap::GetLastStatus** method returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the
**Status** enumeration.

If this
[CachedBitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-cachedbitmap) object was not constructed successfully, the **CachedBitmap::GetLastStatus** method returns an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration that indicates the nature of the failure.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[CachedBitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-cachedbitmap)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Using a Cached Bitmap to Improve Performance](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-cached-bitmap-to-improve-performance-use)
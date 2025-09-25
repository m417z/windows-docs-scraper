# CustomLineCap::GetLastStatus

## Description

The **CustomLineCap::GetLastStatus** method returns a value that indicates the nature of this [CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap) object's most recent method failure.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

The **CustomLineCap::GetLastStatus** method returns an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If no methods invoked on this [CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap) object have failed since the previous call to **CustomLineCap::GetLastStatus**, then **CustomLineCap::GetLastStatus** returns Ok.

If at least one method invoked on this [CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap) object has failed since the previous call to **CustomLineCap::GetLastStatus**, then **CustomLineCap::GetLastStatus** returns a value that indicates the nature of the most recent failure.

## Remarks

You can call **CustomLineCap::GetLastStatus** immediately after constructing a [CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap) object to determine whether the constructor succeeded.

The first time you call the **CustomLineCap::GetLastStatus** method of a [CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap) object, it returns Ok if the constructor succeeded and all methods invoked so far on the **CustomLineCap** object succeeded. Otherwise, it returns a value that indicates the nature of the most recent failure.
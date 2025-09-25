# Graphics::GetLastStatus

## Description

The **Graphics::GetLastStatus** method returns a value that indicates the nature of this
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object's most recent method failure.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

The **Graphics::GetLastStatus** method returns an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If no methods invoked on this
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object have failed since the previous call to **GetLastStatus**, then **Graphics::GetLastStatus** returns Ok.

If at least one method invoked on this
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object has failed since the previous call to **GetLastStatus**, then **Graphics::GetLastStatus** returns a value that indicates the nature of the most recent failure.

## Remarks

You can call **Graphics::GetLastStatus** immediately after constructing a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object to determine whether the constructor succeeded.

The first time you call the **Graphics::GetLastStatus** method of a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object, it returns Ok if the constructor succeeded and all methods invoked so far on the
**Graphics** object succeeded. Otherwise, it returns a value that indicates the nature of the most recent failure.

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)
# GraphicsPath::GetLastStatus

## Description

The **GraphicsPath::GetLastStatus** method returns a value that indicates the nature of this [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object's most recent method failure.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

The **GraphicsPath::GetLastStatus** method returns an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If no methods invoked on this [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object have failed since the previous call to **GraphicsPath::GetLastStatus**, then **GraphicsPath::GetLastStatus** returns Ok.

If at least one method invoked on this [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object has failed since the previous call to **GraphicsPath::GetLastStatus**, then **GraphicsPath::GetLastStatus** returns a value that indicates the nature of the most recent failure.

## Remarks

You can call **GraphicsPath::GetLastStatus** immediately after constructing a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object to determine whether the constructor succeeded.

The first time you call the **GraphicsPath::GetLastStatus** method of a [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object, it returns Ok if the constructor succeeded and all methods invoked so far on the **GraphicsPath** object succeeded. Otherwise, it returns a value that indicates the nature of the most recent failure.

## See also

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)
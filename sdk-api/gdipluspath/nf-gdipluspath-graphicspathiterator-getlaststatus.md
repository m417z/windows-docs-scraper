# GraphicsPathIterator::GetLastStatus

## Description

The **GraphicsPathIterator::GetLastStatus** method returns a value that indicates the nature of this [GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator) object's most recent method failure.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

The **GraphicsPathIterator::GetLastStatus** method returns an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If no methods invoked on this [GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator) object have failed since the previous call to **GetLastStatus**, then **GetLastStatus** returns Ok.

If at least one method invoked on this [GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator) object has failed since the previous call to **GraphicsPathIterator::GetLastStatus** then **GraphicsPathIterator::GetLastStatus** returns a value that indicates the nature of the most recent failure.

## Remarks

You can call **GraphicsPathIterator::GetLastStatus** immediately after constructing a [GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator) object to determine whether the constructor succeeded.

The first time you call the **GraphicsPathIterator::GetLastStatus** method of a [GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator) object, it returns Ok if the constructor succeeded and all methods invoked so far on the **GraphicsPathIterator** object succeeded. Otherwise, it returns a value that indicates the nature of the most recent failure.

## See also

[Constructing and Drawing Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constructing-and-drawing-paths-use)

[GraphicsPathIterator](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspathiterator)

[Paths](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-paths-about)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)
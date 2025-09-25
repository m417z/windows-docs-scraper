# CustomLineCap::SetStrokeJoin

## Description

The **CustomLineCap::SetStrokeJoin** method sets the style of line join for the stroke. The line join specifies how two lines that intersect within the [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object that makes up the custom line cap are joined.

## Parameters

### `lineJoin` [in]

Type: **[LineJoin](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linejoin)**

Element of the [LineJoin](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linejoin) enumeration that specifies the line join that will be used for two lines that are drawn by the same pen and that have overlapping ends.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap)

[LineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linecap)

[LineJoin](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linejoin)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)
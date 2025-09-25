# CustomLineCap::SetStrokeCap

## Description

The **CustomLineCap::SetStrokeCap** method sets the [LineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linecap) object used to start and end lines within the [GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) object that defines this [CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap) object.

## Parameters

### `strokeCap` [in]

Type: **[LineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linecap)**

Element of the [LineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linecap) enumeration that specifies the line cap that will be used on the ends of the line to be drawn.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap)

[LineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linecap)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)
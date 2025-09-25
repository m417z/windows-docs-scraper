# StringFormat::SetAlignment

## Description

The **StringFormat::SetAlignment** method sets the character alignment of this
[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object in relation to the origin of the layout rectangle. A layout rectangle is used to position the displayed string.

## Parameters

### `align` [in]

Type: **[StringAlignment](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringalignment)**

Element of the [StringAlignment](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringalignment) enumeration that specifies how a string is aligned in reference to the bounding rectangle.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)

[StringAlignment](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringalignment)

[StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)
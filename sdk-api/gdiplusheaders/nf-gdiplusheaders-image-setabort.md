# Image::SetAbort

## Description

The **Image::SetAbort** method sets the object whose **Abort** method is called periodically during time-consuming rendering operation.

## Parameters

### `pIAbort`

Type: **[GdiplusAbort](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ns-gdiplustypes-gdiplusabort)***

Pointer to an application-defined descendant of the [GdiplusAbort](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ns-gdiplustypes-gdiplusabort) structure.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)
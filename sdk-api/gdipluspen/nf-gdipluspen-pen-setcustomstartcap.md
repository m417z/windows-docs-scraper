# Pen::SetCustomStartCap

## Description

The **Pen::SetCustomStartCap** method sets the custom start cap for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Parameters

### `customCap` [in]

Type: **const [CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap)***

Pointer to a
[CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap) object that specifies the custom start cap for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Drawing a Custom Dashed Line](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-a-custom-dashed-line-use)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::GetCustomEndCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getcustomendcap)

[Pen::GetCustomStartCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getcustomstartcap)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)
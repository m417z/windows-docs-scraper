# Pen::GetCustomEndCap

## Description

The **Pen::GetCustomEndCap** method gets the custom end cap currently set for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Parameters

### `customCap` [out]

Type: **[CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap)***

Pointer to a
[CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap) object that receives the custom end cap of this
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

[Pen::GetCustomStartCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getcustomstartcap)

[Pen::GetEndCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getendcap)

[Pen::GetStartCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getstartcap)

[Pen::SetCustomEndCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setcustomendcap)

[Pen::SetCustomStartCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setcustomstartcap)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)
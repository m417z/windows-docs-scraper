# Pen::SetLineCap

## Description

The **Pen::SetLineCap** method sets the cap styles for the start, end, and dashes in a line drawn with this pen.

## Parameters

### `startCap` [in]

Type: **[LineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linecap)**

Element of the [LineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linecap) enumeration that specifies the start cap of a line.

### `endCap` [in]

Type: **[LineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linecap)**

Element of the [LineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linecap) enumeration that specifies the end cap of a line.

### `dashCap` [in]

Type: **[DashCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-dashcap)**

Element of the
[DashCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-dashcap) enumeration that specifies the start and end caps of the dashes in a dashed line.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Drawing a Line with Line Caps](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-a-line-with-line-caps-use)

[LineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-linecap)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::GetEndCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getendcap)

[Pen::GetStartCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getstartcap)

[Pen::SetCustomEndCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setcustomendcap)

[Pen::SetCustomStartCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setcustomstartcap)

[Pen::SetEndCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setendcap)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)
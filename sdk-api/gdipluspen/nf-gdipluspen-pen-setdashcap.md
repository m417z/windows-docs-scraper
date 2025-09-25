# Pen::SetDashCap

## Description

The **Pen::SetDashCap** method sets the dash cap style for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Parameters

### `dashCap` [in]

Type: **[DashCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-dashcap)**

Element of the
[DashCap](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-dashcap) enumeration that specifies the dash cap for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

If you set the alignment of a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object to **PenAlignmentInset**, you cannot use that pen to draw triangular dash caps.

#### Examples

The following example creates a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object, sets the dash style and the dash cap, and draws a dashed line.

```cpp
VOID Example_SetCustomStartCap(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a pen.
   Pen pen(Color(255, 0, 0, 255), 20);

   // Set the dash style for the pen.
   pen.SetDashStyle(DashStyleDash);

   // Set a triangular dash cap for the pen.
   pen.SetDashCap(DashCapTriangle);

   // Draw a line using the pen.
   graphics.DrawLine(&pen, 20, 20, 200, 100);
}
```

## See also

[Drawing a Custom Dashed Line](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-a-custom-dashed-line-use)

[Drawing a Line with Line Caps](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-a-line-with-line-caps-use)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::GetCustomEndCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getcustomendcap)

[Pen::GetCustomStartCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getcustomstartcap)

[Pen::GetDashCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getdashcap)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)
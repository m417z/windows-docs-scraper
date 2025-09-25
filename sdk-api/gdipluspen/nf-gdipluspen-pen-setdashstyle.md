# Pen::SetDashStyle

## Description

The **Pen::SetDashStyle** method sets the dash style for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Parameters

### `dashStyle` [in]

Type: **[DashStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-dashstyle)**

Element of the
[DashStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-dashstyle) enumeration that specifies the dash style for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The length of the dashes in a dashed line is dependent on the dash style and the width of the
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object. The length of the space that separates two dashes in a dashed line is equal to the width of the
**Pen** object.

#### Examples

The following example creates a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object, sets the dash style, and draws a line. The code then resets the dash style, draws a second line, resets dash style again, and draws a third line.

```cpp
VOID Example_SetDashStyle(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Pen object.
   Pen pen(Color(255, 0, 0, 255), 15);

   // Set the dash style for the pen, and draw a dashed line.
   pen.SetDashStyle(DashStyleDash);
   graphics.DrawLine(&pen, 0, 50, 400, 150);

   // Reset the dash style for the pen, and draw a second line.
   pen.SetDashStyle(DashStyleDot);
   graphics.DrawLine(&pen, 0, 80, 400, 180);

   // Reset the dash style for the pen, and draw a third line.
   pen.SetDashStyle(DashStyleDashDot);
   graphics.DrawLine(&pen, 0, 110, 400, 210);
}
```

## See also

[Drawing a Custom Dashed Line](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-a-custom-dashed-line-use)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::GetDashCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getdashcap)

[Pen::GetDashOffset](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getdashoffset)

[Pen::GetDashPattern](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getdashpattern)

[Pen::GetDashPatternCount](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getdashpatterncount)

[Pen::GetDashStyle](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getdashstyle)

[Pen::SetDashCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setdashcap)

[Pen::SetDashOffset](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setdashoffset)

[Pen::SetDashPattern](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setdashpattern)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)
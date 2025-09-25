# Pen::SetDashOffset

## Description

The **Pen::SetDashOffset** method sets the distance from the start of the line to the start of the first dash in a dashed line.

## Parameters

### `dashOffset` [in]

Type: **REAL**

Real number that specifies the number of times to shift the spaces in a dashed line. Each shift is equal to the length of a space in the dashed line.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A positive
*dashOffset* value shifts the first dash forward along the path, and a negative
*dashOffset* value shifts the start of the path forward along the first dash.

#### Examples

The following example creates a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object, sets the dash style, and draws a line. The code then sets the pen's offset value and draws a second line.

```cpp
VOID Example_SetDashOffset(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Pen object, set the dash style, and draw a line.
   Pen pen(Color(255, 0, 0, 255), 15);
   pen.SetDashStyle(DashStyleDash);
   graphics.DrawLine(&pen, 0, 50, 400, 50);

   // Set the dash offset value for the pen, and draw a second line.
   pen.SetDashOffset(10);
   graphics.DrawLine(&pen, 0, 80, 400, 80);
}
```

## See also

[Drawing a Custom Dashed Line](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-a-custom-dashed-line-use)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::GetDashOffset](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getdashoffset)

[Pen::GetDashPattern](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getdashpattern)

[Pen::GetDashPatternCount](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getdashpatterncount)

[Pen::GetDashStyle](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getdashstyle)

[Pen::SetDashCap](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setdashcap)

[Pen::SetDashPattern](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setdashpattern)

[Pen::SetDashStyle](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setdashstyle)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)
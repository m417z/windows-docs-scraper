# Pen::GetWidth

## Description

The **Pen::GetWidth** method gets the width currently set for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Return value

Type: **REAL**

This method returns a real number that indicates the width of this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Remarks

If you pass the address of a pen to one of the draw methods of a
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object, the width of the pen's stroke is dependent on the unit of measure specified in the
**Graphics** object. The default unit of measure is UnitPixel, which is an element of the
[Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit) enumeration.

#### Examples

The following example creates a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object with a specified width and draws a line. The code then gets the width of the pen, creates a second pen based on the width of the first pen, and draws a second line.

```cpp
VOID Example_GetWidth(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a pen with a width of 15, and
   // use that pen to draw a line.
   Pen pen(Color(255, 0, 0, 255), 15);
   graphics.DrawLine(&pen, 20, 20, 200, 100);

   // Get the width of the pen.
   REAL width = pen.GetWidth();

   // Create another pen that has the same width.
   Pen pen2(Color(255, 0, 255, 0), width);

   // Draw a second line.
   graphics.DrawLine(&pen2, 20, 60, 200, 140);
}
```

## See also

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::SetWidth](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setwidth)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Setting Pen Width and Alignment](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-setting-pen-width-and-alignment-use)
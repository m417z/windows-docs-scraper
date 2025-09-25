# Pen::GetPenType

## Description

The **Pen::GetPenType** method gets the type currently set for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Return value

Type: **[PenType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pentype)**

This method returns an element of the
[PenType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pentype) enumeration that indicates the style of pen currently set for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Remarks

A
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object is created with a default pen type of **PenTypeSolidColor**, which is an element of the
[PenType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-pentype) enumeration.

#### Examples

The following example creates a
[HatchBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-hatchbrush) object and then passes the address of that
**HatchBrush** object to a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) constructor. The code uses the pen, which has a width of 15, to draw a line. The code calls the **Pen::GetPenType** method to determine the pen's type, and then checks to see whether the type is PenTypeHatchFill.

```cpp
VOID Example_GetPenType(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a HatchBrush object.
   HatchBrush hatchBrush(
      HatchStyleVertical,
      Color(255, 255, 0, 0),
      Color(255, 0, 0, 255));

   // Create a pen based on a hatch brush, and use that
   // pen to draw a line.
   Pen pen(&hatchBrush, 15);
   graphics.DrawLine(&pen, 20, 20, 200, 100);

   // Obtain information about the pen.
   PenType penType = pen.GetPenType();

   if(penType == PenTypeHatchFill)
   {
      // The pen will draw with a hatch pattern.
   }
}
```

## See also

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::GetBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getbrush)

[Pen::SetBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setbrush)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Using a Pen to Draw Lines and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-pen-to-draw-lines-and-rectangles-use)
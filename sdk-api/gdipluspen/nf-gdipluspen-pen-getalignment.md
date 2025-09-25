# Pen::GetAlignment

## Description

The **Pen::GetAlignment** method gets the alignment currently set for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Return value

Type: **[PenAlignment](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-penalignment)**

This method returns an element of the [PenAlignment](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-penalignment) enumeration that indicates the current alignment setting for this [Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Remarks

The default value of [PenAlignment](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-penalignment) is PenAlignmentCenter.

#### Examples

The following example creates a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object, sets the alignment, draws a line, and then gets the pen alignment settings.

```cpp
VOID Example_GetAlignment(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Pen object and set its alignment.
   Pen pen(Color(255, 0, 255, 0), 15);
   pen.SetAlignment(PenAlignmentCenter);

   // Draw a line.
   graphics.DrawLine(&pen, 0, 0, 100, 50);

   // Obtain information about the Pen object.
   PenAlignment penAlignment;
   penAlignment = pen.GetAlignment();

   if(penAlignment == PenAlignmentCenter)
      ;  // The pixels will be centered on the theoretical line.
   else if(penAlignment == PenAlignmentInset)
      ;  // The pixels will lie inside the filled area  of the theoretical line.
}
```

## See also

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::SetAlignment](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setalignment)

[PenAlignment](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-penalignment)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Setting Pen Width and Alignment](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-setting-pen-width-and-alignment-use)
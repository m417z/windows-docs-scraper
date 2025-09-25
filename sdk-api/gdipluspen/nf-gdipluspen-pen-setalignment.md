# Pen::SetAlignment

## Description

The **Pen::SetAlignment** method sets the alignment for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object relative to the line.

## Parameters

### `penAlignment` [in]

Type: **[PenAlignment](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-penalignment)**

Element of the [PenAlignment](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-penalignment) enumeration that specifies the alignment setting of the pen relative to the line that is drawn. The default value is **PenAlignmentCenter**.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

If you set the alignment of a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object to **PenAlignmentInset**, you cannot use that pen to draw compound lines or triangular dash caps.

#### Examples

The following example creates two
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) objects and sets the alignment for one of the pens. The code then draws two lines using each of the pens.

```cpp
VOID Example_SetAlignment(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a black and a green pen.
   Pen blackPen(Color(255, 0, 0, 0), 1);
   Pen greenPen(Color(255, 0, 255, 0), 15);

   // Set the alignment of the green pen.
   greenPen.SetAlignment(PenAlignmentInset);

   // Draw two lines using each pen.
   graphics.DrawEllipse(&greenPen, 0, 0, 100, 200);
   graphics.DrawEllipse(&blackPen, 0, 0, 100, 200);
}
```

## See also

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::GetAlignment](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getalignment)

[PenAlignment](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-penalignment)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)

[Setting Pen Width and Alignment](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-setting-pen-width-and-alignment-use)
# Pen::GetDashOffset

## Description

The **Pen::GetDashOffset** method gets the distance from the start of the line to the start of the first space in a dashed line.

## Return value

Type: **REAL**

This method returns a real number that indicates the distance from the start of the line to the start of the dashes.

## Remarks

A positive return value shifts the first dash forward along the path, and a negative return value shifts the start of the path forward along the first dash.

#### Examples

The following example assumes that
*dashPen* has been defined with a certain dash style and gets the dash offset value.

```cpp
REAL dashOffset = dashPen.GetDashOffset();
```

## See also

[Drawing a Custom Dashed Line](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-a-custom-dashed-line-use)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::SetDashOffset](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setdashoffset)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)
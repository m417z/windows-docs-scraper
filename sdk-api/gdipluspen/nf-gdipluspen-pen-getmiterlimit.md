# Pen::GetMiterLimit

## Description

The **Pen::GetMiterLimit** method gets the miter length currently set for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Return value

Type: **REAL**

This method returns a real number that indicates the miter limit of this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Remarks

The miter length is the distance from the intersection of the line walls on the inside of the join to the intersection of the line walls outside of the join. The miter length can be large when the angle between two lines is small. The miter limit is the maximum allowed ratio of miter length to line width. The default value is 10.

#### Examples

The following example creates a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object and gets the miter limit.

```cpp
Pen pen(Color(255,255,0,0), 4.0f);
REAL miterLimit = pen.GetMiterLimit();
```

## See also

[Joining Lines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-joining-lines-use)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::SetMiterLimit](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setmiterlimit)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)
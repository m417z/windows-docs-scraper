# Pen::SetMiterLimit

## Description

The **Pen::SetMiterLimit** method sets the miter limit of this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Parameters

### `miterLimit` [in]

Type: **REAL**

Real number that specifies the miter limit of this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object. A real number value that is less than 1.0f will be replaced with 1.0f.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The miter length is the distance from the intersection of the line walls on the inside of the join to the intersection of the line walls outside of the join. The miter length can be large when the angle between two lines is small. The miter limit is the maximum allowed ratio of miter length to stroke width. The default value is 10.0f.

If the miter length of the join of the intersection exceeds the limit of the join, then the join will be beveled to keep it within the limit of the join of the intersection.

#### Examples

The following example creates a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object and sets the miter limit for the pen.

```cpp
Pen pen(Color(255,255,0,0), 4.0f);
Status stat = pen.SetMiterLimit(10.0f);
```

## See also

[Joining Lines](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-joining-lines-use)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::GetMiterLimit](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getmiterlimit)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)
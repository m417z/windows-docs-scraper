# Pen::GetCompoundArray

## Description

The **Pen::GetCompoundArray** method gets the compound array currently set for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Parameters

### `compoundArray` [out]

Type: **REAL***

Pointer to an array that receives the compound array.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*compoundArray* array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Suppose that a compound array contains the values 0.0, 0.2, 0.7, and 1.0 and that the pen has a width of 100. When you use the pen to draw, you get two parallel lines. The first line has a width of 20, the space between the two lines has a width of 50, and the second line has a width of 30.

For a more complex example, suppose that a compound array contains the values 0.0, 0.2, 0.3, 0.6, 0.85, and 1.0 and that the pen has a width of 100. When you use the pen to draw, you get three parallel lines. The widths of the three lines are 20, 30, and 15 respectively. The widths of the two spaces between the lines are 10 and 25 respectively.

#### Examples

The following example gets the compound array for a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object. Assuming that a compound array has been set for this **Pen** object, the code then gets the entries that have been set for this pen.

```cpp
INT count = pen.GetCompoundCount();
REAL * distances = new REAL[count];
Status stat = pen.GetCompoundArray(distances, count);
```

## See also

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::SetCompoundArray](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setcompoundarray)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)
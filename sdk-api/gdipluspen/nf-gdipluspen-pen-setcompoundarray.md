# Pen::SetCompoundArray

## Description

The **Pen::SetCompoundArray** method sets the compound array for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Parameters

### `compoundArray` [in]

Type: **const REAL***

Pointer to an array of real numbers that specifies the compound array. The elements in the array must be in increasing order, not less than 0, and not greater than 1.

### `count` [in]

Type: **INT**

Positive even integer that specifies the number of elements in the
*compoundArray* array. The integer must not be greater than the number of elements in the compound array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Suppose you want a pen to draw two parallel lines where the width of the first line is 20 percent of the pen's width, the width of the space that separates the two lines is 50 percent of the pen' s width, and the width of the second line is 30 percent of the pen's width. Start by creating a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object and an array of real numbers. You can then set the compound array by passing the array with the values 0.0, 0.2, 0.7, and 1.0 to the **Pen::SetCompoundArray** method of the
**Pen** object.

If you set the alignment of a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object to **PenAlignmentInset**, you cannot use that pen to draw compound lines.

#### Examples

The following example creates a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object and sets the compound array for the pen. The code then draws a line using the
**Pen** object.

```cpp
VOID Example_SetCompoundArray(HDC hdc)
{
   Graphics graphics(hdc);

   // Create an array of real numbers and a Pen object.
   REAL compVals[6] = {0.0f, 0.2f, 0.5f, 0.7f, 0.9f, 1.0f};
   Pen pen(Color(255, 0, 0, 255), 30);

   // Set the compound array of the pen.
   pen.SetCompoundArray(compVals, 6);

   // Draw a line with the pen.
   graphics.DrawLine(&pen, 5, 20, 405, 200);
}
```

## See also

[Drawing a Custom Dashed Line](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-a-custom-dashed-line-use)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::GetCompoundArray](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getcompoundarray)

[Pen::GetCompoundArrayCount](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getcompoundarraycount)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)
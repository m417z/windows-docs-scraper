# Pen::SetDashPattern

## Description

The **Pen::SetDashPattern** method sets an array of custom dashes and spaces for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Parameters

### `dashArray` [in]

Type: **const REAL***

Pointer to an array of real numbers that specifies the length of the custom dashes and spaces. All elements in the array must be positive real numbers.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*dashArray* array. The integer must be greater than 0 and not greater than the total number of elements in the array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

This method will set the
[DashStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-dashstyle) enumeration for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object to **DashStyleCustom**.

The elements in the
*dashArray* array set the length of each dash and space in the dash pattern. The first element sets the length of a dash, the second element sets the length of a space, the third element sets the length of a dash, and so forth.

The length of each dash and space in the dash pattern is the product of the element value in the array and the width of the
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

#### Examples

The following example creates an array of real numbers. The code then creates a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object, sets the dash pattern based on the array, and then draws the custom dashed line.

```cpp
VOID Example_SetDashPattern(HDC hdc)
{
   Graphics graphics(hdc);

   // Create and set an array of real numbers.
   REAL dashVals[4] = {
      5.0f,   // dash length 5
      2.0f,   // space length 2
      15.0f,  // dash length 15
      4.0f};  // space length 4

   // Create a Pen object.
   Pen pen(Color(255, 0, 0, 0), 5);

   // Set the dash pattern for the custom dashed line.
   pen.SetDashPattern(dashVals, 4);

   // Draw the custom dashed line.
   graphics.DrawLine(&pen, 5, 20, 405, 200);
}
```

## See also

[Drawing a Custom Dashed Line](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-a-custom-dashed-line-use)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::GetDashPattern](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getdashpattern)

[Pen::GetDashPatternCount](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getdashpatterncount)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)
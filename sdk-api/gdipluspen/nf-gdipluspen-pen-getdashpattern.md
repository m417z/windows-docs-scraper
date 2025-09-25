# Pen::GetDashPattern

## Description

The **Pen::GetDashPattern** method gets an array of custom dashes and spaces currently set for this
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

## Parameters

### `dashArray` [out]

Type: **REAL***

Pointer to an array that receives the length of the dashes and spaces in a custom dashed line.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*dashArray* array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The elements in the
*dashArray* array set the length of each dash and space in the dash pattern. The first element sets the length of a dash, the second element sets the length of a space, the third element sets the length of a dash, and so forth.

The length of each dash and space in the dash pattern is the product of each element in the array and the width of the
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object.

#### Examples

The following example creates an array of real numbers and a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object, sets the dash pattern, and draws a custom dashed line. The code then gets the dash pattern currently set for the pen.

```cpp
VOID Example_GetDashPattern(HDC hdc
{
   Graphics graphics(hdc);

   // Create a custom dashed pen, and use it to draw a line.
   REAL dashVals[4] = {5, 2, 15, 4};
   Pen pen(Color(255, 0, 0, 0), 5);
   pen.SetDashPattern(dashVals, 4);
   graphics.DrawLine(&pen, 5, 20, 405, 200);

   // Obtain information about the pen.
   INT count = 0;
   REAL* dashValues = NULL;

   count = pen.GetDashPatternCount();
   dashValues = new REAL[count];
   pen.GetDashPattern(dashValues, count);

   for(INT j = 0; j < count; ++j)
   {
      // Inspect or use the value in dashValues[j].
   }
   delete [] dashValues;
}
```

## See also

[Drawing a Custom Dashed Line](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-a-custom-dashed-line-use)

[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen)

[Pen::GetDashPatternCount](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-getdashpatterncount)

[Pen::SetDashPattern](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nf-gdipluspen-pen-setdashpattern)

[Pens, Lines, and Rectangles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-pens-lines-and-rectangles-about)
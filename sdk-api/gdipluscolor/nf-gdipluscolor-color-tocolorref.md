# Color::ToCOLORREF

## Description

The **Color::ToCOLORREF** method converts this [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object's **ARGB** value to a Windows Graphics Device Interface (GDI)**COLORREF** value.

## Return value

Type: **COLORREF**

This method returns a GDI **COLORREF** value that has the same red, green, and blue components as this color's **ARGB** value.

## Remarks

When the **ARGB** value is converted to a **COLORREF** value, the alpha component of the **ARGB** value is ignored.

#### Examples

The following example creates two [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) objects and converts the **ARGB** value of the first **Color** object into a GDI **COLORREF** value. The code then passes that **COLORREF** value to the [Color::SetFromCOLORREF](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nf-gdipluscolor-color-setfromcolorref) method of the second **Color** object. Finally, the code uses the second **Color** object to fill a rectangle.

```cpp
VOID Example_ToCOLORREF(HDC hdc)
{
   Graphics graphics(hdc);

   // Create two Color objects.
   Color firstColor(255, 128, 128, 255);
   Color secondColor(255, 255, 255, 255);

   // Convert the ARGB value of the first color to a COLORREF value.
   COLORREF colorRef = firstColor.ToCOLORREF();

   // Use the COLORREF value to set the color of secondColor.
   secondColor.SetFromCOLORREF(colorRef);

   // Create a SolidBrush object based on secondColor, and fill a rectangle.
   SolidBrush colorRefBrush(secondColor);
   graphics.FillRectangle(&colorRefBrush, Rect(0, 0, 100, 100));
}
```

## See also

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Color::SetFromCOLORREF](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nf-gdipluscolor-color-setfromcolorref)
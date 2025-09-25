## Description

The **Color::SetFromCOLORREF** method uses a Windows Graphics Device Interface (GDI)**COLORREF** value to set the **ARGB** value of this [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object.

## Parameters

### `rgb` [in]

Type: **COLORREF**

GDI **COLORREF** value that specifies the red, green, and blue components of this [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object's **ARGB** value. The default value of the alpha component for this **Color** object is 255.

## Remarks

A 32-bit GDI **COLORREF** value contains three, 8-bit color components. The most significant 8 bits are zeros and are not used, the next 8 bits contain the blue component, the next 8 bits contain the green component, and the last 8 bits (the least significant) contain the red component. Note that the ordering (starting with the high-order bits) of the components in a **COLORREF** value is blue, green, red; whereas, the ordering of an **ARGB** value is alpha, red, green, blue.

#### Examples

The following example creates a [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object and sets a GDI **COLORREF** value. The code then sets the **Color** object to the value of the GDI **COLORREF** value, creates a pen, and draws a line.

```cpp
VOID Example_SetFromCOLORREF(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a color object.
   Color gdipColor(255, 0, 0, 255);

   // COLORREF is defined as an unsigned long in Wingdi.h
   unsigned long gdiColorRef = RGB(0, 0, 0);   // Set a GDI COLORREF value.

   // Set the color object to the COLORREF value.
   gdipColor.SetFromCOLORREF(gdiColorRef);

   // Create a Pen object based on the Color object.
   Pen pen((gdipColor), 10);

   // Draw a line.
   graphics.DrawLine(&pen, 0, 0, 200, 100);
}
```

## See also

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Color::MakeARGB](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nf-gdipluscolor-color-makeargb)

[Color::ToCOLORREF](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nf-gdipluscolor-color-tocolorref)
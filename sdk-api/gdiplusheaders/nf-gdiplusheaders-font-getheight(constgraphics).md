# Font::GetHeight(Graphics*)

## Description

The **Font::GetHeight** method gets the line spacing of this font in the current unit of a specified [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.
The line spacing is the vertical distance between the base lines of two consecutive lines of text.
Thus, the line spacing includes the blank space between lines along with the height of the character itself.

## Parameters

### `graphics`

Pointer to a **Graphics** object whose unit and vertical resolution are used in the height calculation.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

If the font unit is set to anything other than **UnitPixel**, the height, in pixels, is calculated using the vertical resolution of the specified Graphics object.
For example, suppose the font unit is inches and the font size is 0.3.
Also suppose that for the corresponding font family, the em height is 2048 and the line spacing is 2355.
If the unit of the Graphics object is **UnitPixel** and the vertical resolution of the **Graphics** object is 96 dots per inch, the height is calculated as follows:

`2355*(0.3/2048)*96 = 33.1171875`

Continuing with the same example, suppose the unit of the **Graphics** object is something other than **UnitPixel**, say **UnitMillimeter**.
Then (using 1 inch = 25.4 millimeters) the height, in millimeters, is calculated as follows:

`2355*(0.3/2048)25.4 = 8.762256`

#### Examples

The following example creates a Font object, retrieves the height of the Font object, and uses the height to position two lines of text, with the second line directly below the first.

```cpp
VOID Example_GetHeight(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Font object.
   Font myFont(L"Arial", 16);

   // Draw text with myFont.
   SolidBrush solidbrush_1(Color(255, 0, 0, 0));
   WCHAR string[] = L"The first line of text";
   graphics.DrawString(string, 22, &myFont, PointF(0, 0), &solidbrush_1);

   // Get the height of myFont.
   REAL height = myFont.GetHeight(&graphics);

   // Draw text immediately below the first line of text.
   SolidBrush solidbrush_2(Color(255, 255, 0, 0));
   WCHAR string[] = L"The second line of text";
   graphics.DrawString(string2, 23, &myFont, PointF(0, height),
                       &solidbrush_2);
}
```

## See also

[Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Using Text and Fonts](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-text-and-fonts-use)
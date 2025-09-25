# TextOutA function

## Description

The **TextOut** function writes a character string at the specified location, using the currently selected font, background color, and text color.

## Parameters

### `hdc` [in]

A handle to the device context.

### `x` [in]

The x-coordinate, in logical coordinates, of the reference point that the system uses to align the string.

### `y` [in]

The y-coordinate, in logical coordinates, of the reference point that the system uses to align the string.

### `lpString` [in]

A pointer to the string to be drawn. The string does not need to be zero-terminated, because *cchString* specifies the length of the string.

### `c` [in]

The [length of the string](https://learn.microsoft.com/windows/desktop/gdi/specifying-length-of-text-output-string) pointed to by *lpString*, in characters.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The interpretation of the reference point depends on the current text-alignment mode. An application can retrieve this mode by calling the [GetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextalign) function; an application can alter this mode by calling the [SetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextalign) function. You can use the following values for text alignment. Only one flag can be chosen from those that affect horizontal and vertical alignment. In addition, only one of the two flags that alter the current position can be chosen.

| Term | Description |
| --- | --- |
| TA_BASELINE | The reference point will be on the base line of the text. |
| TA_BOTTOM | The reference point will be on the bottom edge of the bounding rectangle. |
| TA_TOP | The reference point will be on the top edge of the bounding rectangle. |
| TA_CENTER | The reference point will be aligned horizontally with the center of the bounding rectangle. |
| TA_LEFT | The reference point will be on the left edge of the bounding rectangle. |
| TA_RIGHT | The reference point will be on the right edge of the bounding rectangle. |
| TA_NOUPDATECP | The current position is not updated after each text output call. The reference point is passed to the text output function. |
| TA_RTLREADING | **Middle East language edition of Windows:** The text is laid out in right to left reading order, as opposed to the default left to right order. This applies only when the font selected into the device context is either Hebrew or Arabic. |
| TA_UPDATECP | The current position is updated after each text output call. The current position is used as the reference point. |

By default, the current position is not used or updated by this function. However, an application can call the [SetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextalign) function with the *fMode* parameter set to TA_UPDATECP to permit the system to use and update the current position each time the application calls **TextOut** for a specified device context. When this flag is set, the system ignores the *nXStart* and *nYStart* parameters on subsequent **TextOut** calls.

When the **TextOut** function is placed inside a path bracket, the system generates a path for the TrueType text that includes each character plus its character box. The region generated is the character box minus the text, rather than the text itself. You can obtain the region enclosed by the outline of the TrueType text by setting the background mode to transparent before placing the **TextOut** function in the path bracket. Following is sample code that demonstrates this procedure.

```cpp

// Obtain the window's client rectangle
GetClientRect(hwnd, &r);

// THE FIX: by setting the background mode
// to transparent, the region is the text itself
// SetBkMode(hdc, TRANSPARENT);

// Bracket begin a path
BeginPath(hdc);

// Send some text out into the world
TCHAR text[ ] = "Defenestration can be hazardous";
TextOut(hdc,r.left,r.top,text, ARRAYSIZE(text));

// Bracket end a path
EndPath(hdc);

// Derive a region from that path
SelectClipPath(hdc, RGN_AND);

// This generates the same result as SelectClipPath()
// SelectClipRgn(hdc, PathToRegion(hdc));

// Fill the region with grayness
FillRect(hdc, &r, GetStockObject(GRAY_BRUSH));

```

#### Examples

For an example, see [Enumerating the Installed Fonts](https://learn.microsoft.com/windows/desktop/gdi/enumerating-the-installed-fonts).

> [!NOTE]
> The wingdi.h header defines TextOut as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextalign)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)

[SetBkColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkcolor)

[SetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextalign)

[SetTextColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextcolor)

[TabbedTextOut](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-tabbedtextouta)
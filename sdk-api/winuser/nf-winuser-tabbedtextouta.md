# TabbedTextOutA function

## Description

The **TabbedTextOut** function writes a character string at a specified location, expanding tabs to the values specified in an array of tab-stop positions. Text is written in the currently selected font, background color, and text color.

## Parameters

### `hdc` [in]

A handle to the device context.

### `x` [in]

The x-coordinate of the starting point of the string, in logical units.

### `y` [in]

The y-coordinate of the starting point of the string, in logical units.

### `lpString` [in]

A pointer to the character string to draw. The string does not need to be zero-terminated, since *nCount* specifies the length of the string.

### `chCount` [in]

The [length of the string](https://learn.microsoft.com/windows/desktop/gdi/specifying-length-of-text-output-string) pointed to by *lpString*.

### `nTabPositions` [in]

The number of values in the array of tab-stop positions.

### `lpnTabStopPositions` [in]

A pointer to an array containing the tab-stop positions, in logical units. The tab stops must be sorted in increasing order; the smallest x-value should be the first item in the array.

### `nTabOrigin` [in]

The x-coordinate of the starting position from which tabs are expanded, in logical units.

## Return value

If the function succeeds, the return value is the dimensions, in logical units, of the string. The height is in the high-order word and the width is in the low-order word.

If the function fails, the return value is zero.

## Remarks

If the *nTabPositions* parameter is zero and the *lpnTabStopPositions* parameter is **NULL**, tabs are expanded to eight times the average character width.

If *nTabPositions* is 1, the tab stops are separated by the distance specified by the first value in the *lpnTabStopPositions* array.

If the *lpnTabStopPositions* array contains more than one value, a tab stop is set for each value in the array, up to the number specified by *nTabPositions*.

The *nTabOrigin* parameter allows an application to call the **TabbedTextOut** function several times for a single line. If the application calls **TabbedTextOut** more than once with the *nTabOrigin* set to the same value each time, the function expands all tabs relative to the position specified by *nTabOrigin*.

By default, the current position is not used or updated by the **TabbedTextOut** function. If an application needs to update the current position when it calls **TabbedTextOut**, the application can call the [SetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextalign) function with the *wFlags* parameter set to TA_UPDATECP. When this flag is set, the system ignores the *X* and *Y* parameters on subsequent calls to the **TabbedTextOut** function, using the current position instead.

**Note** For Windows Vista and later, **TabbedTextOut** ignores text alignment when it draws text.

> [!NOTE]
> The winuser.h header defines TabbedTextOut as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DrawText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtext)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTabbedTextExtent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-gettabbedtextextenta)

[GrayString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-graystringa)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)

[SetBkColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkcolor)

[SetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextalign)

[SetTextColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextcolor)

[TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta)
# GrayStringA function

## Description

The **GrayString** function draws gray text at the specified location. The function draws the text by copying it into a memory bitmap, graying the bitmap, and then copying the bitmap to the screen. The function grays the text regardless of the selected brush and background. **GrayString** uses the font currently selected for the specified device context.

If thelpOutputFuncparameter is **NULL**, GDI uses the [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta) function, and thelpDataparameter is assumed to be a pointer to the character string to be output. If the characters to be output cannot be handled by **TextOut** (for example, the string is stored as a bitmap), the application must supply its own output function.

## Parameters

### `hDC` [in]

A handle to the device context.

### `hBrush` [in]

A handle to the brush to be used for graying. If this parameter is **NULL**, the text is grayed with the same brush that was used to draw window text.

### `lpOutputFunc` [in]

A pointer to the application-defined function that will draw the string, or, if [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta) is to be used to draw the string, it is a **NULL** pointer. For details, see the [OutputProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-graystringproc) callback function.

### `lpData` [in]

A pointer to data to be passed to the output function. If the *lpOutputFunc* parameter is **NULL**, *lpData* must be a pointer to the string to be output.

### `nCount` [in]

The number of characters to be output. If the *nCount* parameter is zero, **GrayString** calculates the length of the string (assuming *lpData* is a pointer to the string). If *nCount* is 1 and the function pointed to by *lpOutputFunc* returns **FALSE**, the image is shown but not grayed.

### `X` [in]

The device x-coordinate of the starting position of the rectangle that encloses the string.

### `Y` [in]

The device y-coordinate of the starting position of the rectangle that encloses the string.

### `nWidth` [in]

The width, in device units, of the rectangle that encloses the string. If this parameter is zero, **GrayString** calculates the width of the area, assuming *lpData* is a pointer to the string.

### `nHeight` [in]

The height, in device units, of the rectangle that encloses the string. If this parameter is zero, **GrayString** calculates the height of the area, assuming *lpData* is a pointer to the string.

## Return value

If the string is drawn, the return value is nonzero.

If either the [TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta) function or the application-defined output function returned zero, or there was insufficient memory to create a memory bitmap for graying, the return value is zero.

## Remarks

Without calling **GrayString**, an application can draw grayed strings on devices that support a solid gray color. The system color COLOR_GRAYTEXT is the solid-gray system color used to draw disabled text. The application can call the [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor) function to retrieve the color value of COLOR_GRAYTEXT. If the color is other than zero (black), the application can call the [SetTextColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextcolor) function to set the text color to the color value and then draw the string directly. If the retrieved color is black, the application must call **GrayString** to gray the text.

> [!NOTE]
> The winuser.h header defines GrayString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DrawText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtext)

[GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor)

[OutputProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-graystringproc)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[SetTextColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-settextcolor)

[TabbedTextOut](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-tabbedtextouta)

[TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta)
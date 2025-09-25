# DrawStatusTextA function

## Description

The **DrawStatusText** function draws the specified text in the style of a status window with borders.

## Parameters

### `hDC`

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the display context for the window.

### `lprc`

Type: **LPCRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the position, in client coordinates, of the rectangle in which the text is drawn. The function draws the borders just inside the edges of the specified rectangle.

### `pszText`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a null-terminated string that specifies the text to display. Tab characters in the string determine whether the string is left-aligned, right-aligned, or centered.

### `uFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Text drawing flags. This parameter can be a combination of these values:

| Value | Meaning |
| --- | --- |
| **SBT_NOBORDERS** | Prevents borders from being drawn around the specified text. |
| **SBT_POPOUT** | Draws highlighted borders that make the text stand out. |
| **SBT_RTLREADING** | Indicates that the string pointed to by *pszText* will be displayed in the opposite direction to the text in the parent window. |

## Remarks

Normal windows display text left-to-right (LTR). Windows can be *mirrored* to display languages such as Hebrew or Arabic that read right-to-left (RTL). Normally, the *pszText* string will be displayed in the same direction as the text in its parent window. If SBT_RTLREADING is set, the *pszText* string will read in the opposite direction from the text in the parent window.

> [!NOTE]
> The commctrl.h header defines DrawStatusText as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
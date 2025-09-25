# DrawStateA function

## Description

The **DrawState** function displays an image and applies a visual effect to indicate a state, such as a disabled or default state.

## Parameters

### `hdc` [in]

A handle to the device context to draw in.

### `hbrFore` [in]

A handle to the brush used to draw the image, if the state specified by the *fuFlags* parameter is DSS_MONO. This parameter is ignored for other states.

### `qfnCallBack` [in]

A pointer to an application-defined callback function used to render the image. This parameter is required if the image type in *fuFlags* is DST_COMPLEX. It is optional and can be **NULL** if the image type is DST_TEXT. For all other image types, this parameter is ignored. For more information about the callback function, see the [DrawStateProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-drawstateproc) function.

### `lData` [in]

Information about the image. The meaning of this parameter depends on the image type.

### `wData` [in]

Information about the image. The meaning of this parameter depends on the image type. It is, however, zero extended for use with the [DrawStateProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-drawstateproc) function.

### `x` [in]

The horizontal location, in device units, at which to draw the image.

### `y` [in]

The vertical location, in device units, at which to draw the image.

### `cx` [in]

The width of the image, in device units. This parameter is required if the image type is DST_COMPLEX. Otherwise, it can be zero to calculate the width of the image.

### `cy` [in]

The height of the image, in device units. This parameter is required if the image type is DST_COMPLEX. Otherwise, it can be zero to calculate the height of the image.

### `uFlags` [in]

The image type and state. This parameter can be one of the following type values.

| Value (type) | Meaning |
| --- | --- |
| **DST_BITMAP** | The image is a bitmap. The *lData* parameter is the bitmap handle. Note that the bitmap cannot already be selected into an existing device context. |
| **DST_COMPLEX** | The image is application defined. To render the image, **DrawState** calls the callback function specified by the *lpOutputFunc* parameter. |
| **DST_ICON** | The image is an icon. The *lData* parameter is the icon handle. |
| **DST_PREFIXTEXT** | The image is text that may contain an accelerator mnemonic. **DrawState** interprets the ampersand (&) prefix character as a directive to underscore the character that follows. The *lData* parameter is a pointer to the string, and the *wData* parameter specifies the length. If *wData* is zero, the string must be null-terminated. |
| **DST_TEXT** | The image is text. The *lData* parameter is a pointer to the string, and the *wData* parameter specifies the length. If *wData* is zero, the string must be null-terminated. |

This parameter can also be one of the following state values.

| Value (state) | Meaning |
| --- | --- |
| **DSS_DISABLED** | Embosses the image. |
| **DSS_HIDEPREFIX** | Ignores the ampersand (&) prefix character in the text, thus the letter that follows will not be underlined. This must be used with DST_PREFIXTEXT. |
| **DSS_MONO** | Draws the image using the brush specified by the *hbr* parameter. |
| **DSS_NORMAL** | Draws the image without any modification. |
| **DSS_PREFIXONLY** | Draws only the underline at the position of the letter after the ampersand (&) prefix character. No text in the string is drawn. This must be used with DST_PREFIXTEXT. |
| **DSS_RIGHT** | Aligns the text to the right. |
| **DSS_UNION** | Dithers the image. |

For all states except DSS_NORMAL, the image is converted to monochrome before the visual effect is applied.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[DrawStateProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-drawstateproc)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

## Remarks

> [!NOTE]
> The winuser.h header defines DrawState as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
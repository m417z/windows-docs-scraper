## Description

Retrieves the PostScript Level 2 color [rendering intent](https://learn.microsoft.com/windows/win32/wcs/r) from an ICC color profile.

## Parameters

### `hProfile`

Specifies a handle to the ICC color profile in question.

### `dwIntent`

Specifies the desired rendering intent to retrieve. Valid values are:

INTENT\_PERCEPTUAL

INTENT\_SATURATION

INTENT\_RELATIVE\_COLORIMETRIC

INTENT\_ABSOLUTE\_COLORIMETRIC

For more information, see [Rendering Intents](https://learn.microsoft.com/windows/win32/wcs/rendering-intents).

### `pBuffer`

Points to a buffer in which the color rendering intent is to be placed. If the *pBuffer* pointer is set to **NULL**, the buffer size required is returned in *\*pcbSize*.

### `pcbPS2ColorRenderingIntent`

Points to a variable containing the buffer size in bytes. On return, this variable contains the number of bytes actually copied.

## Return value

If this function succeeds, the return value is **TRUE**. If this function succeeds, the return value is **TRUE**. It also returns **TRUE** if the *pBuffer* parameter is **NULL** and the size required for the buffer is copied into *pcbSize.*

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

The rendering intent returned by **GetPS2ColorRenderingIntent** can be used as the operand for the PostScript Level 2 findcolorrendering operator.

This method does not support WCS profiles.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
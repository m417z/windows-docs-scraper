## Description

Retrieves the PostScript Level 2 color rendering intent from a profile.

## Parameters

### `hProfile`

Specifies the profile to use.

### `dwIntent`

Specifies the desired rendering intent to retrieve. Can be one of the following values:

INTENT\_PERCEPTUAL
INTENT\_SATURATION
INTENT\_RELATIVE\_COLORIMETRIC
INTENT\_ABSOLUTE\_COLORIMETRIC

For more information, see [Rendering Intents](https://learn.microsoft.com/windows/win32/wcs/rendering-intents).

### `lpBuffer`

Points to a buffer in which the color rendering intent is to be placed. If the pointer is NULL, the function returns the size required for this buffer in *\*lpcbSize*.

### `lpcbSize`

Points to a variable specifying the size of the buffer. On return, the variable contains has the number of bytes actually copied to the buffer.

## Return value

If this function succeeds, the return value is TRUE. It also returns TRUE if it is called with *lpBuffer* set to NULL and the size of the required buffer is copied into *lpcbSize*.

If this function fails, the return value is FALSE. When this occurs, the CMM should call **SetLastError** to set the last error to a valid error value defined in Winerror.h.

## Remarks

This function is optional for all CMMs.

If a CMM does not support this function, Windows uses the default CMM to get the color rendering intent.

If the tag is not present in the profile indicated by *hProfile*, the CMM creates it. The resulting rendering intent can be used as the operand for the PostScript Level 2 **findcolorrendering** operator.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
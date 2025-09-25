## Description

Retrieves the PostScript Level 2 color rendering dictionary from the specified ICC color profile.

## Parameters

### `hProfile`

Specifies a handle to the ICC color profile in question.

### `dwIntent`

Specifies the desired rendering intent for the color rendering dictionary. Valid values are:

* INTENT\_PERCEPTUAL
* INTENT\_SATURATION
* INTENT\_RELATIVE\_COLORIMETRIC
* INTENT\_ABSOLUTE\_COLORIMETRIC

For more information, see [Rendering intents](https://learn.microsoft.com/windows/win32/wcs/rendering-intents).

### `pPS2ColorRenderingDictionary`

Pointer to a buffer in which the color rendering dictionary is to be placed. If the *pBuffer* pointer is set to **NULL**, the required buffer size is returned in *\*pcbSize*.

### `pcbPS2ColorRenderingDictionary`

Pointer to a variable containing the size of the buffer in bytes. On return, the variable contains the number of bytes actually copied.

### `pbBinary`

Pointer to a Boolean variable. If **TRUE**, the color rendering dictionary could be copied in binary form. If **FALSE**, the dictionary will be encoded in ASCII85 form. On return, this Boolean variable indicates whether the dictionary was actually binary (**TRUE**) or ASCII85 (**FALSE**).

## Return value

If this function succeeds, the return value is **TRUE**. It also returns **TRUE** if the *pBuffer* parameter is **NULL** and the size required for the buffer is copied into *pcbSize.*

If this function fails, the return value is **FALSE**.

## Remarks

If the dictionary is not available in the profile, the **GetPS2ColorRenderingDictionary** function builds one using the profile contents. This dictionary can then be used as the operand for the PostScript Level 2 **setcolorrendering** operator.

This method does not support WCS profiles.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
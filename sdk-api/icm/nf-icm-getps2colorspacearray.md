## Description

Retrieves the PostScript Level 2 [color space](https://learn.microsoft.com/windows/win32/wcs/color-spaces) array from an ICC color profile.

## Parameters

### `hProfile`

Specifies a handle to the ICC profile from which to retrieve the PostScript Level 2 color space array.

### `dwIntent`

Specifies the desired rendering intent for the color space array. This field may take one of the following values:

INTENT\_PERCEPTUAL

INTENT\_SATURATION

INTENT\_RELATIVE\_COLORIMETRIC

INTENT\_ABSOLUTE\_COLORIMETRIC

For more information, see [Rendering Intents](https://learn.microsoft.com/windows/win32/wcs/rendering-intents).

### `dwCSAType`

Specifies the type of color space array. See [Color Space Type Identifiers](https://learn.microsoft.com/windows/win32/wcs/color-space-type-identifiers).

### `pPS2ColorSpaceArray`

Pointer to a buffer in which the color space array is to be placed. If the *pBuffer* pointer is set to **NULL**, the function returns the required size of the buffer in the memory location pointed to by *pcbSize*.

### `pcbPS2ColorSpaceArray`

Pointer to a variable containing the size of the buffer in bytes. On return, it contains the number of bytes copied into the buffer.

### `pbBinary`

Pointer to a Boolean variable. If set to **TRUE**, the data copied could be binary. If set to **FALSE**, data should be encoded as ASCII85. On return, the memory location pointed to by *pbBinary* indicates whether the data returned actually is binary (**TRUE**) or ASCII85 (**FALSE**).

## Return value

If this function succeeds, the return value is **TRUE**. It also returns **TRUE** if the *pBuffer* parameter is **NULL** and the size required for the buffer is copied into *pcbSize.*

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

If the color space array is not available in the profile, the **GetPS2ColorSpaceArray** function builds a PostScript Level 2 color space array using the profile contents. This array can then be used as the operand for the PostScript Level2 setcolorspace operator.

This method does not support WCS profiles.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
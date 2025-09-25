## Description

\[**CMTranslateRGBs** is no longer available for use as of Windows Vista.\]

Translates a bitmap from one [color space](https://learn.microsoft.com/windows/win32/wcs/c#color-space) to another using a color transform.

## Parameters

### `hcmTransform`

Specifies the color transform to use.

### `lpSrcBits`

Points to the bitmap to translate.

### `bmInput`

Specifies the input bitmap format.

### `dwWidth`

Specifies the number of pixels per scan line in the input bitmap.

### `dwHeight`

Specifies the number of scan lines in the input bitmap.

### `dwStride`

Specifies the number of bytes from the beginning of one scan line to the beginning of the next in the input bitmap. If *dwStride* is set to zero, the CMM should assume that scan lines are padded so as to be **DWORD**-aligned.

### `lpDestBits`

Points to a destination buffer in which to place the translated bitmap.

### `bmOutput`

Specifies the output bitmap format.

### `dwTranslateDirection`

Specifies the direction of the transform being used for the translation. This parameter must take one of the following values.

| Value | Meaning |
| --- | --- |
| **CMS_FORWARD** | Use forward transform |
| **CMS_BACKWARD** | Use reverse transform |

## Return value

Beginning with Windows Vista, the default CMM (Icm32.dll) will return **FALSE** and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) will report ERROR\_NOT\_SUPPORTED.

**Windows Server 2003, Windows XP and Windows 2000:**

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. If the function is not successful, the CMM should call [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) to set the last error to a valid error value defined in Winerror.h.

## Remarks

Beginning with Windows Vista, CMM Implementors are no longer required to implement this method.

**Windows Server 2003, Windows XP and Windows 2000:**

Every CMM is required to export this function.

When writing into the destination buffer, the CMM should make sure that scan lines are padded to be **DWORD**-aligned.

If the input and output formats are not compatible with the color transform, this function fails.

If both input and output bitmap formats are 3-channel, 4 bytes-per-pixel as in the case of BM\_xRGBQUADS, the 4th byte should be preserved and copied to the output buffer.

Note that this function must support in-place translation. That is, whenever the memory footprint of the output is less than or equal to the memory footprint of the input, this function must be able to translate the bitmap colors even if the source and destination buffers are the same.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
## Description

Translates the colors of a bitmap having a defined format so as to produce another bitmap in a requested format.

## Parameters

### `hColorTransform`

Identifies the color transform to use.

### `pSrcBits`

Pointer to the bitmap to translate.

### `bmInput`

Specifies the format of the input bitmap. Must be set to one of the values of the [**BMFORMAT**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-bmformat) enumerated type.

> [!Note]
> This function doesn't support [**BM\_XYZTRIPLETS**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-bmformat) or **BM\_YxyTRIPLETS** as inputs.

### `dwWidth`

Specifies the number of pixels per scan line in the input bitmap.

### `dwHeight`

Specifies the number of scan lines in the input bitmap.

### `dwInputStride`

Specifies the number of bytes from the beginning of one scan line to the beginning of the next in the input bitmap; if set to zero, the function assumes that scan lines are padded so as to be **DWORD**-aligned.

### `pDestBits`

Pointer to the buffer in which to place the translated bitmap.

### `bmOutput`

Specifies the format of the output bitmap. Must be set to one of the values of the [**BMFORMAT**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-bmformat) enumerated type.

### `dwOutputStride`

Specifies the number of bytes from the beginning of one scan line to the beginning of the next in the output bitmap; if set to zero, the function assumes that scan lines should be padded to be **DWORD**-aligned.

### `pfnCallBack`

Pointer to a callback function called periodically by **TranslateBitmapBits** to report progress and allow the calling process to cancel the translation. (See [**ICMProgressProcCallback**](https://learn.microsoft.com/windows/win32/wcs/icmprogressproccallback) )

### `ulCallbackData`

Data passed back to the callback function, for example, to identify the translation that is reporting progress.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

If the input and output formats are not compatible with the color transform, this function fails.

When either of the floating point BMFORMATs, BM\_32b\_scARGB or BM\_32b\_scRGB are used, the color data being translated should not contain NaN or infinity. NaN and infinity are not considered to represent legitimate color component values, and the result of translating pixels containing NaN or infinity is meaningless in color terms. NaN or infinity values in the color data being processed will be handled silently, and an error will not be returned.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [ICMProgressProcCallback](https://learn.microsoft.com/windows/win32/wcs/icmprogressproccallback)
* [Windows bitmap header structures](https://learn.microsoft.com/windows/win32/wcs/using-structures-in-wcs-1-0)
* [BMFORMAT](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-bmformat)
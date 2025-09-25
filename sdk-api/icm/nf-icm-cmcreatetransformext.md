## Description

Creates a color transform that maps from an input [**LOGCOLORSPACEA**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-logcolorspacea) to an optional target space and then to an output device, using a set of flags that define how the transform should be created.

## Parameters

### `lpColorSpace`

Pointer to an input logical color space structure.

### `lpDevCharacter`

Pointer to a memory-mapped device profile.

### `lpTargetDevCharacter`

Pointer to a memory-mapped target profile.

### `dwFlags`

Specifies flags to used control creation of the transform. For details, see [CMM transform creation flags](https://learn.microsoft.com/windows/win32/wcs/cmm-transform-creation-flags).

## Return value

If this function succeeds, the return value is a color transform in the range 256 to 65,535. Since only the low **WORD** of the transform is retained, valid transforms cannot exceed this range.

If this function fails, the return value is an error code having a value less than 256. When the return value is less than 256, signaling an error, the CMM should use **SetLastError** to set the last error to a valid error value as defined in Winerror.h.

## Remarks

The Unicode equivalent of **CMCreateTransformExt** is [CMCreateTransformExtW](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-cmcreatetransformextw).

Every CMM is required to export this function.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [CMCreateTransformExtW](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-cmcreatetransformextw)
## Description

Translates an array of colors from a source [color space](https://learn.microsoft.com/windows/win32/wcs/color-spaces) to a destination color space using a color transform.

## Parameters

### `hcmTransform`

Specifies the color transform to use.

### `lpaInputColors`

Points to an array of [**COLOR**](https://learn.microsoft.com/windows/win32/api/icm/ns-icm-color) structures to translate.

### `nColors`

Specifies the number of elements in the array.

### `ctInput`

Specifies the color type of the input.

### `lpaOutputColors`

Points to a buffer in which an array of translated **COLOR** structures is to be placed.

### `ctOutput`

Specifies the output color type.

## Return value

If this function succeeds, the return value is TRUE.

If this function fails, the return value is FALSE. The CMM should call **SetLastError** to set the last error to a valid error value defined in Winerror.h.

## Remarks

Every CMM is required to export this function.

If the input and the output color types are not compatible with the color transform, this function should fail.

Note that this function must support in-place translation. That is, whenever the memory footprint of the output is less than or equal to the memory footprint of the input, this function must be able to translate the bitmap colors even if the source and destination buffers are the same.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
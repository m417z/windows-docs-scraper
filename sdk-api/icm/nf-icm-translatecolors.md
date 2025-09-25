## Description

Translates an array of colors from the source [color space](https://learn.microsoft.com/windows/win32/wcs/c#color-space) to the destination color space as defined by a color transform.

## Parameters

### `hColorTransform`

Identifies the color transform to use.

### `paInputColors`

Pointer to an array of *nColors*[**COLOR**](https://learn.microsoft.com/windows/win32/api/icm/ns-icm-color) structures to translate.

### `nColors`

Contains the number of elements in the arrays pointed to by *paInputColors* and *paOutputColors*.

### `ctInput`

Specifies the input color type.

### `paOutputColors`

Pointer to an array of *nColors* **COLOR** structures that receive the translated colors.

### `ctOutput`

Specifies the output color type.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

If the input and the output color types are not compatible with the color transform, this function fails.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
## Description

Determines whether the colors in an array are within the output gamut of a specified WCS color transform.

## Parameters

### `hColorTransform`

A handle to the specified WCS color transform.

### `nColors`

The number of elements in the array pointed to by *pInputData* and *paResult*.

### `nInputChannels`

The number of channels per element in the array pointed to by *pInputData*.

### `cdtInput`

The input COLORDATATYPE color data type.

### `cbInput`

The buffer size of *pInputData*.

### `pInputData`

A pointer to an array of input colors. Colors in this array correspond to the color space of the source profile. The size of the buffer for this array will be the number of bytes indicated by *cbInput*.

### `paResult`

A pointer to an array of *nColors* bytes that receives the results of the test.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

If the input and the output color data types are not compatible with the color transform, this function will convert the input color data as required.

This function fails if you use an International Color Consortium (ICC) transform is used.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [Windows Color System schemas and algorithms](https://learn.microsoft.com/windows/win32/wcs/windows-color-system-schemas-and-algorithms)
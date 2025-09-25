## Description

Translates an array of colors from the source color space to the destination color space as defined by a color transform.

## Parameters

### `hColorTransform`

A handle for the WCS color transform.

### `nColors`

The number of elements in the array to which *pInputData* and *pOutputData* point.

### `nInputChannels`

The number of channels per element in the array to which *pInputData* points.

### `cdtInput`

The input [**COLORDATATYPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colordatatype) color data type.

### `cbInput`

The buffer size, in bytes, of *pInputData*.

### `pInputData`

A pointer to an array of input colors. The size of the buffer for this array, in bytes, is the **DWORD** value of *cbInput*.

### `nOutputChannels`

The number of channels per element in the array to which *pOutputData* points.

### `cdtOutput`

The [**COLORDATATYPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colordatatype) output that specified the color data type.

### `cbOutput`

The buffer size, in bytes, of *pOutputData*.

### `pOutputData`

A pointer to an array of colors that receives the results of the color translation.The size of the buffer for this array, in bytes, is the **DWORD** value of *cbOutput*.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

If the input and the output color data types are not compatible with the color transform, this function fails. This function will fail if an ICC transform is used.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Windows Color System schemas and algorithms](https://learn.microsoft.com/windows/win32/wcs/windows-color-system-schemas-and-algorithms)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
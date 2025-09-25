# MFConvertFromFP16Array function

## Description

Converts an array of 16-bit floating-point numbers into an array of 32-bit floating-point numbers.

## Parameters

### `pDest` [in]

Pointer to an array of **float** values. The array must contain at least *dwCount* elements.

### `pSrc` [in]

Pointer to an array of 16-bit floating-point values, typed as **WORD** values. The array must contain at least *dwCount* elements.

### `dwCount` [in]

Number of elements in the *pSrc* array to convert.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The function converts *dwCount* values in the *pSrc* array and writes them into the *pDest* array.

**Note** Prior to Windows 7, this function was exported from evr.dll. Starting in Windows 7, this function is exported from mfplat.dll, and evr.dll exports a stub function that calls into mfplat.dll. For more information, see [Library Changes in Windows 7](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-headers-and-libraries).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)
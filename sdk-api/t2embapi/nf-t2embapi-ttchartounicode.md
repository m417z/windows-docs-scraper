# TTCharToUnicode function

## Description

Converts an array of 8-bit character code values to 16-bit Unicode values.

## Parameters

### `hDC` [in]

A device context handle.

### `pucCharCodes` [in]

A pointer to an array of 8-bit character codes to convert to 16-bit Unicode values. Must be set to a non-null value.

### `ulCharCodeSize` [in]

The size of an 8-bit character code array.

### `pusShortCodes` [out]

A pointer to an array that will be filled by this function with the Unicode equivalents of the 8-bit values in the *pucCharCodesarray*. This parameter must be set to a non-null value.

### `ulShortCodeSize` [in]

The size, in wide characters, of the character code array.

### `ulFlags` [in]

This parameter is currently unused.

## Return value

If successful, returns E_NONE.

Array **pusShortCodes* is filled with 16-bit Unicode values that correspond to the 8-bit character codes in **pusCharCodes*.*ulShortCodeSize* contains the size, in wide characters, of **pusShortCodes*.

Otherwise, returns an error code described in [Embedding Function Error Messages](https://learn.microsoft.com/windows/desktop/gdi/font-embedding-function-error-messages).

## Remarks

This function may be useful to clients when creating a list of symbol characters to be subsetted.

## See also

[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar)

[WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte)
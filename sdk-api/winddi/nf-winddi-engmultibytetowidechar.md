# EngMultiByteToWideChar function

## Description

The **EngMultiByteToWideChar** function converts an ANSI source string into a wide character string using the specified code page.

## Parameters

### `CodePage` [in]

Specifies the code page to use to perform the translation.

### `WideCharString` [out, optional]

Pointer to the buffer into which the translated character string is copied.

### `BytesInWideCharString` [in]

Specifies the size, in bytes, of *WideCharString*. If *WideCharString* is not large enough to contain the translation, **EngMultiByteToWideChar** truncates the string, and does not report an error.

### `MultiByteString` [in, optional]

Pointer to the buffer containing the multibyte string to be translated.

### `BytesInMultiByteString` [in]

Specifies the number of bytes in *MultiByteString.*

## Return value

The **EngMultiByteToWideChar** function returns the number of bytes it converted to wide character form, if successful. Otherwise, the function returns -1.

## See also

[EngUnicodeToMultiByteN](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engunicodetomultibyten)

[EngWideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engwidechartomultibyte)
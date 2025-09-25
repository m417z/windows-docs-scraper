# EngWideCharToMultiByte function

## Description

The **EngWideCharToMultiByte** function converts a wide character string into an ANSI source string using the specified code page.

## Parameters

### `CodePage` [in]

Specifies the code page to use to perform the translation.

### `WideCharString` [in, optional]

Pointer to a buffer containing the wide character string to be translated.

### `BytesInWideCharString` [in]

Specifies the size, in bytes, of *WideCharString*.

### `MultiByteString` [out, optional]

Pointer to a buffer into which the translated character string is to be copied

### `BytesInMultiByteString` [in]

Specifies the number of bytes in *MultiByteString*. If *MultiByteString* is not large enough to contain the translation, **EngWideCharToMultiByte** truncates the string, and does not report an error.

## Return value

**EngWideCharToMultiByte** returns the number of bytes converted into multibyte form, if successful. Otherwise, it returns -1.

## See also

[EngMultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmultibytetowidechar)

[EngUnicodeToMultiByteN](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engunicodetomultibyten)
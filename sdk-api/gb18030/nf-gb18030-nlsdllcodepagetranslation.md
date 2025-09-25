# NlsDllCodePageTranslation function

## Description

Used to get code page information or do conversion, depending on flag settings.

**Note** Do not use this function. It can behave differently in different versions of Windows. To convert GB18030 bytes to Unicode characters or Unicode characters to GB18030 bytes, use the [MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) and [WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte) functions.

## Parameters

### `CodePage` [in]

The value of the code page. The code page value should be 54936. Otherwise, the function returns an error code.

### `dwFlags` [in]

Flags specifying the translation. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **NLS_CP_CPINFO** | Retrieve code page information in the buffer pointed to by *lpCPInfo*. The *lpMultiByteStr*, *cchMultiByte*, *lpWideCharStr*, and *cchWideChar* parameters are not used. |
| **NLS_CP_MBTOWC** | Convert GB18030 bytes to Unicode characters. The source GB18030 characters should be pointed to by *lpMultiByteStr*, and *cchMultiByte* should contain the byte count of the buffer. The Unicode result is stored in the buffer pointed to by *lpWideCharStr*, and *cchWideChar* should contain the character count of the Unicode buffer. If *lpWideCharStr* or *cchWideChar* is 0, the expected character count of the Unicode result is returned, and no conversion is done. The *lpCPInfo* parameter is not used in this case. |
| **NLS_CP_WCTOMB** | Convert Unicode characters to GB18030 bytes. The source Unicode string should be pointed to by *lpWideCharStr*, and *cchWideChar* should contain the character count of the buffer. The GB18030 result is stored in the buffer pointed to by *lpMultiByteStr*, and *cchMultiByte* should contain the byte count of the GB18030 buffer. If *lpMultiByteStr* or *cchMultiByte* is 0, the byte count of the GB18030 result is returned, and no conversion is done. The *lpCPInfo* parameter is not used in this case. |

### `lpMultiByteStr` [in, out]

Pointer to a buffer that contains multibyte GB18030 characters. This can be a source buffer or target buffer, depending on the value of *dwFlags*.

### `cchMultiByte` [in]

Byte count of the multibyte buffer.

### `lpWideCharStr` [in, out]

Pointer to a buffer that contains Unicode characters. This can be a source buffer or target buffer, depending on the value of *dwFlags*.

### `cchWideChar` [in]

Character count of the Unicode buffer.

### `lpCPInfo` [in]

Pointer to a [CPINFO](https://learn.microsoft.com/windows/desktop/api/winnls/ns-winnls-cpinfo) structure.

## Return value

Returns 1 if successful. If the function does not succeed, it returns 0. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## See also

[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar)

[WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte)
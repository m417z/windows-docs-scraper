# UnicodeToBytes function

## Description

Deprecated. Converts Unicode characters to GB18030 bytes.

**Note** When converting Unicode characters to GB18030 bytes, an application to run on Windows Vista and later should use the [WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte) function.

```cpp
DWORD UnicodeToBytes(
  _In_ LPWSTR lpWideCharStr,
  _In_ UINT   cchWideChar,
  _In_ LPSTR  lpMultiByteStr,
  _In_ UINT   cchMultiByte
);
```

## Parameters

### lpWideCharStr [in]

Pointer to the Unicode string to convert.

### cchWideChar [in]

Character count of the Unicode string to convert.

### lpMultiByteStr [in]

Pointer to the target multibyte buffer.
If *lpMultiByteStr* is 0, the byte count of the GB18030 result is returned, and no conversion is done.

### cchMultiByte [in]

Byte count of the target multibyte buffer.
If *cchMultiByte* is 0, the byte count of the GB18030 result is returned, and no conversion is done.

## Returns

Returns the byte count of the multibyte characters that are generated, if successful.

## Remarks

## See also

[WideCharToMultiByte](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte)

[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar)
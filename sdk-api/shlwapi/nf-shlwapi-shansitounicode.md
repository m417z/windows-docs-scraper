# SHAnsiToUnicode function

## Description

[This function is available through Windows XP and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Converts a string from the ANSI code page to the Unicode code page.

## Parameters

### `pszSrc` [in]

Type: **PCSTR**

A pointer to a null-terminated ANSI string to be converted to Unicode.

### `pwszDst` [out]

Type: **PWSTR**

A pointer to a buffer that, when this function returns successfully, receives the string specified by *pszSrc*, after the ANSI characters have been converted to Unicode (WCHAR). The buffer must be large enough to contain the number of Unicode characters specified by the *cwchBuf* parameter, including a terminating null character.

### `cwchBuf`

Type: **int**

The number of Unicode characters that can be contained by the buffer pointed to by *pwszDst*. This parameter must be greater than zero.

## Return value

Type: **int**

Returns the number of Unicode characters written to *pwszDst*, including the terminating null character. Returns 0 if unsuccessful.

## Remarks

**Security Warning:** Using this function incorrectly can compromise the security of your application. For example, if *pwszDst* buffer is not large enough to contain the number of characters specified by *cwchBuf*, a buffer overrun can occur. Buffer overruns can cause a denial of service attack against an application if an access violation occurs. In the worst case, a buffer overrun might allow an attacker to inject executable code into your process, especially if *pwszDst* is a stack-based buffer. When copying an entire string, note that sizeof returns the number of bytes, which is not the correct value to use for the *cwchBuf* parameter. Instead, use sizeof(pwszDst)/sizeof(WCHAR). Note that this technique assumes that *pwszDst* is an array, not a pointer.

If the *pwszDst* buffer is not large enough to contain the entire converted output string, the string is truncated to fit the buffer. There is no way to detect that the return string has been truncated. The string is always null-terminated, even if it has been truncated. This ensures that no more than *cwchBuf* characters are copied to *pwszDst*. No attempt is made to avoid truncating the string in the middle of a Unicode surrogate pair.

If the *pszSrc* and *pwszDst* buffers overlap, the function's behavior is undefined.

**Note** Do not assume that the function has not changed any of the characters in the output buffer that follow the string's terminating null character. The contents of the output buffer following the string's terminating null character are undefined, up to and including the last character in the buffer.

**SHAnsiToTChar** is defined to be the same as **SHAnsiToUnicode**.

## See also

[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar)

[StringCbCopy](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopya)

[StringCbCopyEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopyexa)

[StringCbCopyN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopyna)

[StringCbCopyNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopynexa)

[StringCbLength](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcblengtha)

[StringCchCopy](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopya)

[StringCchCopyEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopyexa)

[StringCchCopyN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopyna)

[StringCchCopyNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopynexa)

**StringCchLength**
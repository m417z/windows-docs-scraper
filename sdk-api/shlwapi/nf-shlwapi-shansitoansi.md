# SHAnsiToAnsi function

## Description

[This function is available through Windows XP and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Copies an ANSI string.

## Parameters

### `pszSrc` [in]

Type: **LPCSTR**

A pointer to a null-terminated ANSI string to be converted to Unicode.

### `pszDst` [out]

Type: **LPWSTR**

A pointer to a buffer that, when this function returns successfully, receives the characters copied from *pszSrc*. The buffer must be large enough to contain the number of characters specified by the *cchBuf* parameter, including a room for a terminating null character.

### `cchBuf`

Type: **int**

The number of characters that can be contained by the buffer pointed to by *pszDst*. This parameter must be greater than zero.

## Return value

Type: **int**

Returns the number of characters written to *pszDst*, including the terminating null character. Returns 0 if unsuccessful.

## Remarks

**Security Warning:** Using this function incorrectly can compromise the security of your application. For example, if *pszDst* buffer is not large enough to contain the number of characters specified by *cchBuf*, a buffer overrun can occur. Buffer overruns can cause a denial of service attack against an application if an access violation occurs. In the worst case, a buffer overrun might allow an attacker to inject executable code into your process, especially if *pszDst* is a stack-based buffer. Note that the output string is silently truncated if the buffer is not large enough. This can result in canonicalization or other security vulnerabilities.

If the *pszDst* buffer is not large enough to contain the entire converted output string, the string is truncated to fit the buffer. There is no way to detect that the return string has been truncated. The string will always be null-terminated, even if it has been truncated. This function takes care to not truncate between the lead and trail bytes of a DBCS character pair. In that case, only cchBuf-1 characters are returned.

If the *pszSrc* and *pszDst* buffers overlap, the function's behavior is undefined.

**Note** Do not assume that the function has not changed any of the characters in the output buffer that follow the string's terminating null character. The contents of the output buffer following the string's terminating null character are undefined, up to and including the last character in the buffer.

## See also

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
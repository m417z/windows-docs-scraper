# SHUnicodeToUnicode function

## Description

[This function is available through Windows XP and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Copies a Unicode string.

## Parameters

### `pwzSrc` [in]

Type: **PCWSTR**

A pointer to a null-terminated Unicode string to be copied to the output buffer.

### `pwzDst` [out]

Type: **PWSTR**

A pointer to an output buffer to receive the copied characters. The buffer must be large enough to contain the number of **WCHAR** characters specified by *cwchBuf*, including room for a terminating null character.

### `cwchBuf`

Type: **int**

The number of **WCHAR** characters that can be contained by the buffer pointed to by *pwzDst* parameter. This parameter must be greater than zero.

## Return value

Type: **int**

Returns the number of **WCHAR** characters written to the output buffer, including the terminating null character. Returns 0 if unsuccessful.

## Remarks

**Security Warning:** Using this function incorrectly can compromise the security of your application. For example, if *pwzDst* buffer is not large enough to contain the number of characters specified by *cwchBuf*, a buffer overrun can occur. Buffer overruns can cause a denial of service attack against an application if an access violation occurs. In the worst case, a buffer overrun might allow an attacker to inject executable code into your process, especially if *pwzDst* is a stack-based buffer. When copying an entire string, note that sizeof returns the number of bytes, which is not the correct value to use for the *cwchBuf* parameter. Instead, use sizeof(pwzDst)/sizeof(WCHAR). Note that this technique assumes that *pwzDst* is an array, not a pointer. Note also that the function silently truncates the output string if the buffer is not large enough. This can result in canonicalization or other security vulnerabilities.

If the *pwzDst* buffer is not large enough to contain the entire converted output string, the string is truncated to fit the buffer. There is no way to detect that the return string has been truncated. The string will always be null-terminated, even if it has been truncated. This ensures that no more than *cwchBuf* characters are copied to *pwzDst*. No attempt is made to avoid truncating the string in the middle of a Unicode surrogate pair.

If the *pwzSrc* and *pwzDst* buffers overlap, the function's behavior is undefined.

**Note** Do not assume that the function has not changed any of the characters in the output buffer that follow the string's terminating null character. The contents of the output buffer following the string's terminating null character are undefined, up to and including the last character in the buffer.

**SHTCharToUnicode** is defined to be the same as **SHUnicodeToUnicode**.

**SHUnicodeToTChar** is defined to be the same as **SHUnicodeToUnicode**.

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
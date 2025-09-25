# lstrcpynA function

## Description

Copies a specified number of characters from a source string into a buffer.

**Warning** Do not use. Consider using [StringCchCopy](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopya) instead. See Remarks.

## Parameters

### `lpString1` [out]

Type: **LPTSTR**

The destination buffer, which receives the copied characters. The buffer
must be large enough to contain the number of **TCHAR** values
specified by *iMaxLength*, including room
for a terminating null character.

### `lpString2` [in]

Type: **LPCTSTR**

The source string from which the function is to copy characters.

### `iMaxLength` [in]

Type: **int**

The number of **TCHAR** values to be copied from the
string pointed to by *lpString2* into the
buffer pointed to by *lpString1*, including
a terminating null character.

## Return value

Type: **LPTSTR**

If the function succeeds, the return value is a pointer to the buffer.
The function can succeed even if the source string is greater than
*iMaxLength* characters.

If the function fails, the return value is **NULL**
and *lpString1* may not be null-terminated.

## Remarks

The buffer pointed to by *lpString1* must
be large enough to include a terminating null character, and the string length
value specified by *iMaxLength* includes room
for a terminating null character.

The **lstrcpyn** function has an undefined behavior if source
and destination buffers overlap.

### Security Warning

Using this function incorrectly can compromise the security
of your application. This function uses structured exception handling (SEH) to catch
access violations and other errors. When this function catches SEH errors, it returns
**NULL** without null-terminating the string and without notifying the
caller of the error. The caller is not safe to assume that insufficient space is
the error condition.

If the buffer pointed to by *lpString1* is not large
enough to contain the copied string, a buffer overrun can occur. When copying an entire
string, note that **sizeof** returns the number of bytes.
For example, if *lpString1* points to a buffer
*szString1* which is declared as
`TCHAR szString[100]`, then sizeof(szString1) gives the size of
the buffer in bytes rather than **WCHAR**, which could lead to a buffer
overflow for the Unicode version of the function.

Buffer overflow situations are the cause
of many security problems in applications and can cause a denial of service attack against
the application if an access violation occurs. In the worst case, a buffer overrun may
allow an attacker to inject executable code into your process, especially if
*lpString1* is a stack-based buffer.

Using `sizeof(szString1)/sizeof(szString1[0])`
gives the proper size of the buffer.

Consider using [StringCchCopy](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopya) instead; use either
`StringCchCopy(buffer, sizeof(buffer)/sizeof(buffer[0]), src);`,
being aware that `buffer` must not be a pointer or
use `StringCchCopy(buffer, ARRAYSIZE(buffer), src);`,
being aware that, when copying to a pointer, the caller is responsible for
passing in the size of the pointed-to memory in characters.

Review [Security Considerations: Windows User Interface](https://learn.microsoft.com/windows/desktop/AppUIStart/sec-ui) before continuing.

> [!NOTE]
> The winbase.h header defines lstrcpyn as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

**Reference**

[StringCbCopy](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopya)

[StringCbCopyEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopyexa)

[StringCbCopyN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopyna)

[StringCbCopyNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopynexa)

[StringCbLength](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcblengtha)

[StringCchCopy](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopya)

[StringCchCopyEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopyexa)

[StringCchCopyN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopyna)

[StringCchCopyNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopynexa)

[StringCchLength](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchlengtha)

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)

[lstrcmp](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcmpa)

[lstrcmpi](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcmpia)

[lstrlen](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrlena)
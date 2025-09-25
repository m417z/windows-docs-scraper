# lstrcpyA function

## Description

Copies a string to a buffer.

**Warning** Do not use. Consider using [StringCchCopy](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopya) instead. See Remarks.

## Parameters

### `lpString1` [out]

Type: **LPTSTR**

A buffer to receive the contents of the string pointed to by the
*lpString2* parameter.
The buffer must be large enough to contain the string, including the
terminating null character.

### `lpString2` [in]

Type: **LPTSTR**

The null-terminated string to be copied.

## Return value

Type: **LPTSTR**

If the function succeeds, the return value is a pointer to the buffer.

If the function fails, the return value is **NULL**
and *lpString1* may not be null-terminated.

## Remarks

With a double-byte character set (DBCS) version of the system, this function can be used
to copy a DBCS string.

The **lstrcpy** function has an
undefined behavior if source and destination buffers overlap.

### Security Remarks

Using this function incorrectly can compromise the security
of your application. This function uses structured exception handling (SEH) to catch
access violations and other errors. When this function catches SEH errors, it returns
**NULL** without null-terminating the string and without notifying the
caller of the error. The caller is not safe to assume that insufficient space is
the error condition.

*lpString1* must be large enough to hold *lpString2*
and the closing '\0', otherwise a buffer overrun may occur.

Buffer overflow situations are the cause of many security problems in applications and
can cause a denial of service attack against the application if an access violation occurs.
In the worst case, a buffer overrun may allow an attacker to inject executable code into
your process, especially if *lpString1* is a stack-based buffer.

Consider using [StringCchCopy](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopya) instead; use either
`StringCchCopy(buffer, sizeof(buffer)/sizeof(buffer[0]), src);`,
being aware that `buffer` must not be a pointer or
use `StringCchCopy(buffer, ARRAYSIZE(buffer), src);`,
being aware that, when copying to a pointer, the caller is responsible for
passing in the size of the pointed-to memory in characters.

> [!NOTE]
> The winbase.h header defines lstrcpy as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

**Reference**

[StringCbCopy](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopya)

[StringCbCopyEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopyexa)

[StringCbCopyN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopyna)

[StringCbCopyNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopynexa)

[StringCchCopy](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopya)

[StringCchCopyEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopyexa)

[StringCchCopyN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopyna)

[StringCchCopyNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopynexa)

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)

[lstrcmp](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcmpa)

[lstrcmpi](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcmpia)

[lstrlen](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrlena)
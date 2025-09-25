# lstrcatA function

## Description

Appends one string to another.

**Warning** Do not use. Consider using [StringCchCat](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcata) instead. See Security Considerations.

## Parameters

### `lpString1` [in, out]

Type: **LPTSTR**

The first null-terminated string. This buffer must be large enough
to contain both strings.

### `lpString2` [in]

Type: **LPTSTR**

The null-terminated string to be appended to the string
specified in the *lpString1* parameter.

## Return value

Type: **LPTSTR**

If the function succeeds, the return value is a pointer to the buffer.

If the function fails, the return value is **NULL**
and *lpString1* may not be null-terminated.

## See also

**Conceptual**

**Reference**

[StringCbCat](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcata)

[StringCbCatEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatexa)

[StringCbCatN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatna)

[StringCbCatNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatnexa)

[StringCchCat](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcata)

[StringCchCatEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcatexa)

[StringCchCatN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcatna)

[StringCchCatNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcatnexa)

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)

[lstrcmp](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcmpa)

[lstrcmpi](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcmpia)

[lstrlen](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrlena)

## Remarks

> [!NOTE]
> The winbase.h header defines lstrcat as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
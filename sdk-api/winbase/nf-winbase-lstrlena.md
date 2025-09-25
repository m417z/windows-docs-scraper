# lstrlenA function

## Description

Determines the length of the specified string (not including the terminating null character).

## Parameters

### `lpString` [in]

Type: **LPCTSTR**

The null-terminated string to be checked.

## Return value

Type: **int**

The function returns the length of the string, in characters. If *lpString* is **NULL**, the function returns 0.

## See also

**Conceptual**

**Reference**

[StringCbLength](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcblengtha)

[StringCchLength](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchlengtha)

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)

[lstrcat](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcata)

[lstrcmp](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcmpa)

[lstrcmpi](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcmpia)

[lstrcpy](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcpya)

## Remarks

> [!NOTE]
> The winbase.h header defines lstrlen as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
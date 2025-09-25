# FindAtomW function

## Description

Searches the local atom table for the specified character string and retrieves the atom associated with that string.

## Parameters

### `lpString` [in]

Type: **LPCTSTR**

The character string for which to search.

Alternatively, you can use an integer atom that has been converted using the [MAKEINTATOM](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-makeintatom) macro. See Remarks for more information.

## Return value

Type: **ATOM**

If the function succeeds, the return value is the atom associated with the given string.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Even though the system preserves the case of a string in an atom table, the search performed by the **FindAtom** function is not case sensitive.

If
*lpString* was created by the [MAKEINTATOM](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-makeintatom) macro, the low-order word must be in the range 0x0001 through 0xBFFF. If the low-order word is not in this range, the function fails.

> [!NOTE]
> The winbase.h header defines FindAtom as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-addatomw)

[DeleteAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deleteatom)

[GlobalAddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaladdatoma)

[GlobalDeleteAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaldeleteatom)

[GlobalFindAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfindatoma)

**Reference**
# AddAtomW function

## Description

Adds a character string to the local atom table and returns a unique value (an atom) identifying the string.

## Parameters

### `lpString` [in]

Type: **LPCTSTR**

The null-terminated string to be added. The string can have a maximum size of 255 bytes. Strings differing only in case are considered identical. The case of the first string added is preserved and returned by the [GetAtomName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getatomnamea) function.

Alternatively, you can use an integer atom that has been converted using the [MAKEINTATOM](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-makeintatom) macro. See the Remarks for more information.

## Return value

Type: **ATOM**

If the function succeeds, the return value is the newly created atom.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **AddAtom** function stores no more than one copy of a given string in the atom table. If the string is already in the table, the function returns the existing atom and, in the case of a string atom, increments the string's reference count.

If
*lpString* has the form "#1234", **AddAtom** returns an integer atom whose value is the 16-bit representation of the decimal number specified in the string (0x04D2, in this example). If the decimal value specified is 0x0000 or is greater than or equal to 0xC000, the return value is zero, indicating an error. If
*lpString* was created by the [MAKEINTATOM](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-makeintatom) macro, the low-order word must be in the range 0x0001 through 0xBFFF. If the low-order word is not in this range, the function fails.

If
*lpString* has any other form, **AddAtom** returns a string atom.

> [!NOTE]
> The winbase.h header defines AddAtom as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DeleteAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deleteatom)

[FindAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findatoma)

[GetAtomName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getatomnamea)

[GlobalAddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaladdatoma)

[GlobalDeleteAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaldeleteatom)

[GlobalFindAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfindatoma)

[GlobalGetAtomName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalgetatomnamea)

[MAKEINTATOM](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-makeintatom)

**Reference**
# GlobalAddAtomExW function

## Description

Adds a character string to the global atom table and returns a unique value (an atom) identifying the string.

## Parameters

### `lpString` [in, optional]

The null-terminated string to be added. The string can have a maximum size of 255 bytes. Strings that differ only in case are considered identical. The case of the first string of this name added to the table is preserved and returned by the [GlobalGetAtomName](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globalgetatomnamea) function.

Alternatively, you can use an integer atom that has been converted using the [MAKEINTATOM](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-makeintatom) macro. See the Remarks for more information.

### `Flags` [in]

## Return value

If the function succeeds, the return value is the newly created atom.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[GlobalAddAtom](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globaladdatoma)

## Remarks

> [!NOTE]
> The winbase.h header defines GlobalAddAtomEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
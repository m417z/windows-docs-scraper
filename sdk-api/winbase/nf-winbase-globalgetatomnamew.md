# GlobalGetAtomNameW function

## Description

Retrieves a copy of the character string associated with the specified global atom.

## Parameters

### `nAtom` [in]

Type: **ATOM**

The global atom associated with the character string to be retrieved.

### `lpBuffer` [out]

Type: **LPTSTR**

The buffer for the character string.

### `nSize` [in]

Type: **int**

The size, in
characters, of the buffer.

## Return value

Type: **UINT**

If the function succeeds, the return value is the length of the string copied to the buffer, in
characters, not including the terminating null character.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The string returned for an integer atom (an atom whose value is in the range 0x0001 to 0xBFFF) is a null-terminated string in which the first character is a pound sign (#) and the remaining characters represent the unsigned integer atom value.

### Security Considerations

Using this function incorrectly might compromise the security of your program. Incorrect use of this function includes not correctly specifying the size of the *lpBuffer* parameter. Also, note that a global atom is accessible by anyone; thus, privacy and the integrity of its contents is not assured.

> [!NOTE]
> The winbase.h header defines GlobalGetAtomName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-addatomw)

[DeleteAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deleteatom)

[FindAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findatoma)

[GlobalAddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaladdatoma)

[GlobalDeleteAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaldeleteatom)

[GlobalFindAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfindatoma)

[MAKEINTATOM](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-makeintatom)

**Reference**
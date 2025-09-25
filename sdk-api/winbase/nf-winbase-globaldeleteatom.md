# GlobalDeleteAtom function

## Description

Decrements the reference count of a global string atom. If the atom's reference count reaches zero, **GlobalDeleteAtom** removes the string associated with the atom from the global atom table.

## Parameters

### `nAtom` [in]

Type: **ATOM**

The atom and character string to be deleted.

## Return value

Type: **ATOM**

The function always returns (**ATOM**) 0.

To determine whether the function has failed, call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) with **ERROR_SUCCESS** before calling **GlobalDeleteAtom**, then call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the last error code is still **ERROR_SUCCESS**, **GlobalDeleteAtom** has succeeded.

## Remarks

A string atom's reference count specifies the number of times the string has been added to the atom table. The [GlobalAddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaladdatoma) function increments the reference count of a string that already exists in the global atom table each time it is called.

Each call to [GlobalAddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaladdatoma) should have a corresponding call to **GlobalDeleteAtom**. Do not call **GlobalDeleteAtom** more times than you call **GlobalAddAtom**, or you may delete the atom while other clients are using it. Applications using Dynamic Data Exchange (DDE) should follow the rules on global atom management to prevent leaks and premature deletion.

**GlobalDeleteAtom** has no effect on an integer atom (an atom whose value is in the range 0x0001 to 0xBFFF). The function always returns zero for an integer atom.

#### Examples

For an example, see [Initiating a Conversation](https://learn.microsoft.com/windows/desktop/dataxchg/using-dynamic-data-exchange).

## See also

[AddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-addatomw)

[DeleteAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deleteatom)

[FindAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findatoma)

[GlobalAddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaladdatoma)

[GlobalFindAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfindatoma)

[MAKEINTATOM](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-makeintatom)

**Reference**
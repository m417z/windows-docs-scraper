# DeleteAtom function

## Description

Decrements the reference count of a local string atom. If the atom's reference count is reduced to zero, **DeleteAtom** removes the string associated with the atom from the local atom table.

## Parameters

### `nAtom` [in]

Type: **ATOM**

The atom to be deleted.

## Return value

Type: **ATOM**

If the function succeeds, the return value is zero.

If the function fails, the return value is the
*nAtom* parameter. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A string atom's reference count specifies the number of times the atom has been added to the atom table. The [AddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-addatomw) function increments the count on each call. The **DeleteAtom** function decrements the count on each call but removes the string only if the atom's reference count is zero.

Each call to [AddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-addatomw) should have a corresponding call to **DeleteAtom**. Do not call **DeleteAtom** more times than you call **AddAtom**, or you may delete the atom while other clients are using it.

The **DeleteAtom** function has no effect on an integer atom (an atom whose value is in the range 0x0001 to 0xBFFF). The function always returns zero for an integer atom.

## See also

[AddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-addatomw)

[FindAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findatoma)

[GlobalAddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaladdatoma)

[GlobalDeleteAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaldeleteatom)

[GlobalFindAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfindatoma)

[MAKEINTATOM](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-makeintatom)

**Reference**
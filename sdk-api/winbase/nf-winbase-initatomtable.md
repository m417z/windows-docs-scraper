# InitAtomTable function

## Description

Initializes the local atom table and sets the number of hash buckets to the specified size.

## Parameters

### `nSize` [in]

Type: **DWORD**

The number of hash buckets to use for the atom table. If this parameter is zero, the default number of hash buckets are created.

To achieve better performance, specify a prime number in
*nSize*.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

An application need not use this function to use a local atom table. The default number of hash buckets used is 37. If an application does use **InitAtomTable**, however, it should call the function before any other atom-management function.

If an application uses a large number of local atoms, it can reduce the time required to add an atom to the local atom table or to find an atom in the table by increasing the size of the table. However, this increases the amount of memory required to maintain the table.

The number of buckets in the global atom table cannot be changed. If the atom table has already been initialized, either explicitly by a prior call to **InitAtomTable**, or implicitly by the use of any atom-management function, **InitAtomTable** returns success without changing the number of hash buckets.

## See also

[AddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-addatomw)

[DeleteAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deleteatom)

[FindAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findatoma)

[GetAtomName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getatomnamea)

[GlobalAddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaladdatoma)

[GlobalDeleteAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaldeleteatom)

[GlobalFindAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfindatoma)

[GlobalGetAtomName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalgetatomnamea)

**Reference**
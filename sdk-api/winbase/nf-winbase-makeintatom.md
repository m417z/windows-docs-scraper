# MAKEINTATOM macro

## Description

Converts the specified atom into a string, so it can be passed to functions which accept either atoms or strings.

## Parameters

### `i`

The numeric value to be made into an integer atom. This parameter can be either an integer atom or a string atom.

## Remarks

Although the return value of the **MAKEINTATOM** macro is cast as an **LPTSTR** value, it cannot be used as a string pointer except when it is passed to atom-management functions that require an **LPTSTR** argument.

## See also

[AddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-addatomw)

[DeleteAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deleteatom)

[GetAtomName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getatomnamea)

[GlobalAddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaladdatoma)

[GlobalDeleteAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaldeleteatom)

[GlobalGetAtomName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalgetatomnamea)

**Reference**
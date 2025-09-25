# ITypeInfo::GetDllEntry

## Description

Retrieves a description or specification of an entry point for a function in a DLL.

## Parameters

### `memid` [in]

The ID of the member function whose DLL entry description is to be returned.

### `invKind` [in]

The kind of member identified by *memid*. This is important for properties, because one *memid* can identify up to three separate functions.

### `pBstrDllName` [out]

If not null, the function sets *pBstrDllName* to the name of the DLL.

### `pBstrName` [out]

If not null, the function sets *pBstrName* to the name of the entry point. If the entry point is specified by an ordinal, this argument is null.

### `pwOrdinal` [out]

If not null, and if the function is defined by an ordinal, the function sets *pwOrdinal* to the ordinal.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The caller passes in a member ID, which represents the member function whose entry description is desired. If the function has a DLL entry point, the name of the DLL that contains the function, as well as its name or ordinal identifier, are placed in the passed-in pointers allocated by the caller. If there is no DLL entry point for the function, an error is returned.

If the type description inherits from another type description, this function is recursive to the base type description, if necessary, to find the item with the requested member ID.

The caller should use [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the BSTRs referenced by *pBstrName* and *pBstrDllName*.

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)
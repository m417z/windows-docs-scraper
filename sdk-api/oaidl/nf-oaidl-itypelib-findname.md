# ITypeLib::FindName

## Description

Finds occurrences of a type description in a type library. This may be used to quickly verify that a name exists in a type library.

## Parameters

### `szNameBuf` [in, out]

The name to search for.

### `lHashVal` [in]

A hash value to speed up the search, computed by the [LHashValOfNameSys](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-lhashvalofnamesys) function. If *lHashVal* = 0, a value is computed.

### `ppTInfo` [out]

An array of pointers to the type descriptions that contain the name specified in *szNameBuf*. This parameter cannot be null.

### `rgMemId` [out]

An array of the found items; *rgMemId*[*i*] is the MEMBERID that indexes into the type description specified by *ppTInfo*[*i*]. This parameter cannot be null.

### `pcFound` [in, out]

On entry, indicates how many instances to look for. For example, **pcFound* = 1 can be called to find the first occurrence. The search stops when one is found.

On exit, indicates the number of instances that were found. If the in and out values of **pcFound* are identical, there may be more type descriptions that contain the name.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

Passing **pcFound* = *n* indicates that there is enough room in the *ppTInfo* and *rgMemId* arrays for *n* (*ptinfo*, *memid*) pairs. The function returns MEMBERID_NIL in *rgMemId*[*i*], if the name in *szNameBuf* is the name of the type information in *ppTInfo*[*i*].

## See also

[ITypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypelib)
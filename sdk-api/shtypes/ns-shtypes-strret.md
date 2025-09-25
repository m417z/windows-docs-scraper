# STRRET structure

## Description

Contains strings returned from the [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) interface methods.

## Members

### `uType`

Type: **UINT**

A value that specifies the desired format of the string. This can be one of the following values.

#### STRRET_CSTR

The string is returned in the **cStr** member.

#### STRRET_OFFSET

The **uOffset** member value indicates the number of bytes from the beginning of the item identifier list where the string is located.

#### STRRET_WSTR

The string is at the address specified by **pOleStr** member.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.pOleStr`

Type: **LPWSTR**

A pointer to the string. This memory must be allocated with [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). It is the calling application's responsibility to free this memory with [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) when it is no longer needed.

### `DUMMYUNIONNAME.uOffset`

Type: **UINT**

The offset into the item identifier list.

### `DUMMYUNIONNAME.cStr`

Type: **CHAR[MAX_PATH]**

The buffer to receive the display name.

## See also

[IShellFolder::GetDisplayNameOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getdisplaynameof)
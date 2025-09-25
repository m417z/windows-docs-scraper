## Description

Retrieves a list of property pages that can be displayed in this object's property sheet.

## Parameters

### `pPages` [out]

A pointer to a caller-allocated [CAUUID](https://learn.microsoft.com/windows/win32/api/ocidl/ns-ocidl-cauuid) structure that the function initializes and fills in before it returns. The **pElems** member in the structure is allocated by the function with [CoTaskMemAlloc](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc), and should be freed by the caller with [CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

This method can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | The address in *pPages* is not valid. For example, it may be **NULL**. |

## Remarks

The [CAUUID](https://learn.microsoft.com/windows/win32/api/ocidl/ns-ocidl-cauuid) structure is caller-allocated, but is not initialized by the caller. The **GetPages** method fills the **cElements** member in the structure. This method also allocates memory for the array pointed to by the **pElems** member using [CoTaskMemAlloc](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc). Then, it fills the newly allocated array. After this method returns successfully, the structure contains a counted array of UUIDs, each UUID specifying a property page CLSID.

### Notes to Callers

The caller must release the memory pointed to by the **pElems** member of [CAUUID](https://learn.microsoft.com/windows/win32/api/ocidl/ns-ocidl-cauuid), using [CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree) when it is no longer needed.

### Notes to Implementers

E_NOTIMPL is not allowed as a return value, because an object with no property pages should not expose the [ISpecifyPropertyPages](https://learn.microsoft.com/windows/win32/api/ocidl/nn-ocidl-ispecifypropertypages) interface.

## See also

[ISpecifyPropertyPages](https://learn.microsoft.com/windows/win32/api/ocidl/nn-ocidl-ispecifypropertypages)
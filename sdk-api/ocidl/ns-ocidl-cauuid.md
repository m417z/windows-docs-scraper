# CAUUID structure

## Description

Specifies a counted array of UUID or GUID types used to receive an array of CLSIDs for the property pages that the object wants to display.

## Members

### `cElems`

The size of the array pointed to by **pElems**.

### `pElems`

A pointer to an array of values, each of which specifies a CLSID of a particular property page. This array is allocated by the callee using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and is freed by the caller using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## See also

[ISpecifyPropertyPages::GetPages](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ispecifypropertypages-getpages)
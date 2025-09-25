# CALPOLESTR structure

## Description

Specifies a counted array of strings used to specify the predefined strings that a property can accept.

## Members

### `cElems`

The size of the array pointed to by **pElems**.

### `pElems`

A pointer to an array of [LPOLESTR](https://learn.microsoft.com/windows/desktop/api/wtypesbase/nf-wtypesbase-olestr) values, each of which corresponds to an allowable value that a particular property can accept. The caller can use these string values in user interface elements, such as drop-down list boxes. This array, as well as the strings in the array, are allocated by the callee using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and is freed by the caller using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## See also

[IPerPropertyBrowsing::GetPredefinedStrings](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedstrings)

[LPOLESTR](https://learn.microsoft.com/windows/desktop/api/wtypesbase/nf-wtypesbase-olestr)
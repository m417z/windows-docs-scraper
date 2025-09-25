# CADWORD structure

## Description

Specifies a counted array of values that can be used to obtain the value corresponding to one of the predefined strings for a property.

## Members

### `cElems`

The size of the array pointed to by **pElems**.

### `pElems`

A pointer to an array of values, each of which can be passed to the [IPerPropertyBrowsing::GetPredefinedValue](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedvalue) method to obtain the corresponding value for one of the property's predefined strings. This array is allocated by the callee using [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and is freed by the caller using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## See also

[CALPOLESTR](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-calpolestr)

[IPerPropertyBrowsing::GetPredefinedStrings](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedstrings)

[IPerPropertyBrowsing::GetPredefinedValue](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iperpropertybrowsing-getpredefinedvalue)
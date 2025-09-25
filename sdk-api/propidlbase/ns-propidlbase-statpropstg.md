# STATPROPSTG structure

## Description

The
**STATPROPSTG** structure contains data about a single property in a property set. This data is the property ID and type tag, and the optional string name that may be associated with the property.

[IPropertyStorage::Enum](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-enum) supplies a pointer to the
[IEnumSTATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropstg) interface on an enumerator object that can be used to enumerate the
**STATPROPSTG** structures for the properties in the current property set.
**STATPROPSTG** is defined as:

## Members

### `lpwstrName`

A wide-character null-terminated Unicode string that contains the optional string name associated with the property. May be **NULL**. This member must be freed using
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `propid`

A 32-bit identifier that uniquely identifies the property within the property set. All properties within property sets must have unique property identifiers.

### `vt`

The property type.

## See also

[IEnumSTATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ienumstatpropstg)

[IPropertyStorage::Enum](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-enum)
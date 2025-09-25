# PROPSPEC structure

## Description

The
**PROPSPEC** structure is used by many of the methods of
[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) to specify a property either by its property identifier (ID) or the associated string name.

## Members

### `ulKind`

Indicates the union member used. This member can be one of the following values.

| Name | Meaning |
| --- | --- |
| **PRSPEC_LPWSTR**<br><br>Value: 0 | The **lpwstr** member is used and set to a string name. |
| **PRSPEC_PROPID**<br><br>Value: 1 | The **propid** member is used and set to a property ID value. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.propid`

Specifies the value of the property ID. Use either this value or the following **lpwstr**, not both.

### `DUMMYUNIONNAME.lpwstr`

Specifies the string name of the property as a null-terminated Unicode string.

## Remarks

String names are optional and can be assigned to a set of properties when the property is created with a call to [IPropertyStorage::WriteMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-writemultiple) or later with a call to [IPropertyStorage::WritePropertyNames](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-writepropertynames).

## See also

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)
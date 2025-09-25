# IPropertyStorage::ReadPropertyNames

## Description

The **ReadPropertyNames** method retrieves any existing string names for the specified property IDs.

## Parameters

### `cpropid` [in]

The number of elements on input of the array *rgpropid*. The value of this parameter can be set to zero, however that defeats the purpose of this method as no property names are thereby read.

### `rgpropid` [in]

An array of property IDs for which names are to be retrieved.

### `rglpwstrName` [in, out]

A caller-allocated array of size *cpropid* of **LPWSTR** members. On return, the implementation fills in this array. A given entry contains either the corresponding string name of a property ID or it can be empty if the property ID has no string names.

Each **LPWSTR** member of the array should be freed using the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

This method supports the standard return value E_UNEXPECTED, in addition to the following:

## Remarks

For each property ID in the list of property IDs supplied in the *rgpropid* array, **ReadPropertyNames** retrieves the corresponding string name, if there is one. String names are created either by specifying the names in calls to
[IPropertyStorage::WriteMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-writemultiple) when creating the property, or through a call to [IPropertyStorage::WritePropertyNames](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-writepropertynames). In either case, the string name is optional, however all properties must have a property ID.

String names mapped to property IDs must be unique within the set.

## See also

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[IPropertyStorage::WriteMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-writemultiple)

[IPropertyStorage::WritePropertyNames](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-writepropertynames)
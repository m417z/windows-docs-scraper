# IPropertyStorage::DeletePropertyNames

## Description

The **DeletePropertyNames** method deletes specified string names from the current property set.

## Parameters

### `cpropid` [in]

The size on input of the array *rgpropid*. If 0, no property names are deleted.

### `rgpropid` [in]

Property identifiers for which string names are to be deleted.

## Return value

This method supports the standard return value E_UNEXPECTED, in addition to the following:

## Remarks

For each property identifier in *rgpropid*, **IPropertyStorage::DeletePropertyNames** removes any corresponding name-to-property ID mapping. An attempt is silently ignored to delete the name of a property that either does not exist or does not currently have a string name associated with it. This method has no effect on the properties themselves.

**Note** All the stored string property names can be deleted by deleting property identifier zero, but *cpropid* must be equal to 1 for this to be a valid parameter error.

## See also

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[IPropertyStorage::ReadPropertyNames](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-readpropertynames)
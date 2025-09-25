# ICatalogObject::get_Key

## Description

Retrieves the key property of the object.

This property is read-only.

## Parameters

## Remarks

The key property serves as the primary identifier for a collection. In some cases, it is a GUID, such as CLSID for a component; in some cases, it is the object name, as with roles. The key property of a collection is identified in the documentation for each specific collection of the [COM+ Administration Collections](https://learn.microsoft.com/windows/desktop/cossdk/com--administration-collections).

If you add a new object and save it with the key property of an existing object, you overwrite the existing object.

## See also

[ICatalogObject](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogobject)
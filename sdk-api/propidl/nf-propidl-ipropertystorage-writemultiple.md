# IPropertyStorage::WriteMultiple

## Description

The
**WriteMultiple** method
writes a specified group of properties to the current property set. If a property with a specified name or property identifier already exists, it is replaced, even when the old and new types for the property value are different. If a property of a given name or property ID does not exist, it is created.

## Parameters

### `cpspec` [in]

The number of properties set. The value of this parameter can be set to zero; however, this defeats the purpose of the method as no properties are then written.

### `rgpspec` [in]

An array of the property IDs ([PROPSPEC](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propspec)) to which properties are set. These need not be in any particular order, and may contain duplicates, however the last specified property ID is the one that takes effect. A mixture of property IDs and string names is permitted.

### `rgpropvar` [in]

An array (of size *cpspec*) of
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures that contain the property values to be written. The array must be the size specified by *cpspec*.

### `propidNameFirst` [in]

The minimum value for the property IDs that the method must assign if the *rgpspec* parameter specifies string-named properties for which no property IDs currently exist. If all string-named properties specified already exist in this set, and thus already have property IDs, this value is ignored. When not ignored, this value must be greater than, or equal to, two and less than 0x80000000. Property IDs 0 and 1 and greater than 0x80000000 are reserved for special use.

## Return value

This method supports the standard return value E_UNEXPECTED, in addition to the following:

This function can also return any file system errors or Win32 errors wrapped in an **HRESULT** data type. For more information, see
[Error Handling Strategies](https://learn.microsoft.com/windows/desktop/com/error-handling-strategies).

## Remarks

If a specified property already exists, its value is replaced with the one specified in *rgpspec*, even when the old and new types for the property value are different. If the specified property does not already exist, that property is created. The changes are not persisted to the underlying storage until [IPropertyStorage::Commit](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-commit) has been called.

Property names are stored in a special dictionary section of the property set, which maps such names to property IDs. All properties have an ID, but names are optional. A string name is supplied by specifying PRSPEC_LPWSTR in the **ulKind** member of the
[PROPSPEC](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propspec) structure. If a string name is supplied for a property, and the name does not already exist in the dictionary, the method will allocate a property ID, and add the property ID and the name to the dictionary. The property ID is allocated in such a way that it does not conflict with other IDs in the property set. The value of the property ID also is no less than the value specified by the *propidNameFirst* parameter. If the *rgpspec* parameter specifies string-named properties for which no property IDs currently exist, the *propidNameFirst* parameter specifies the minimum value for the property IDs that the
**WriteMultiple** method must assign.

When a new property set is created, the special **codepage (**[Property ID 1](https://msdn.microsoft.com/)**)** and **Locale ID (**[Property ID 0x80000000](https://msdn.microsoft.com/)**)** properties are written to the property set automatically. These properties can subsequently be read, using the [IPropertyStorage::ReadMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-readmultiple) method, by specifying property IDs with the header-defined PID_CODEPAGE and PID_LOCALE values, respectively. If a property set is non-empty — has one or more properties in addition to the **codepage** and **Locale ID** properties or has one or more names in its dictionary — the special **codepage** and **Locale ID** properties cannot be modified by calling **IPropertyStorage::WriteMultiple**. However, if the property set is empty, one or both of these special properties can be modified.

If an element in the *rgspec* array is set with a PRSPEC_PROPID value of 0xffffffff (PID_ILLEGAL), the corresponding value in the *rgvar* array is ignored by **IPropertyStorage::WriteMultiple**. For example, if this method is called with the *cspec* parameter set to 3, but *rgpspec[1].prspec* is set to PRSPEC_PROPID and *rgpspec[1].propid* is set to PID_ILLEGAL, only two properties will be written. The *rgpropvar[1]* element is silently ignored.

Use the
[PropVariantInit](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-propvariantinit) macro to initialize
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures.

Property sets, not including the data for nonsimple properties, are limited to 256 KB in size for Windows NT 4.0 and earlier. For Windows 2000, Windows XP and Windows Server 2003, OLE property sets are limited to 1 MB. If these limits are exceeded, the operation fails and the caller receives an error message. There is no possibility of a memory leak or overrun. For more information, see
[Managing Property Sets](https://learn.microsoft.com/windows/desktop/Stg/managing-property-sets).

Unless PROPSETFLAG_CASE_SENSITIVE is passed to [IPropertySetStorage::Create](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-create), property set names are case insensitive. Specifying a property by its name in **IPropertyStorage::WriteMultiple** will result in a case-insensitive search of the names in the property set. To compare case-insensitive strings, the locale of the strings must be known. For more information, see
[IPropertyStorage::WritePropertyNames](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-writepropertynames).

For more information, see
[Property Storage Considerations](https://learn.microsoft.com/windows/desktop/Stg/property-storage-considerations).

## See also

[IPropertySetStorage::Create](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-create)

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[IPropertyStorage::ReadMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-readmultiple)

[Managing Property Sets](https://learn.microsoft.com/windows/desktop/Stg/managing-property-sets)

[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)

[Samples](https://learn.microsoft.com/windows/desktop/Stg/samples)

[StgCreatePropSetStg Sample](https://learn.microsoft.com/windows/desktop/Stg/stgcreatepropsetstg-sample)

[WriteRead Sample](https://learn.microsoft.com/windows/desktop/Stg/writeread-sample)
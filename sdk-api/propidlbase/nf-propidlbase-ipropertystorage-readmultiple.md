# IPropertyStorage::ReadMultiple

## Description

The
**ReadMultiple** method
reads specified properties from the current property set.

## Parameters

### `cpspec` [in]

The numeric count of properties to be specified in the *rgpspec* array. The value of this parameter can be set to zero; however, that defeats the purpose of the method as no properties are thereby read, regardless of the values set in *rgpspec*.

### `rgpspec` [in]

An array of
[PROPSPEC](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propspec) structures specifies which properties are read. Properties can be specified either by a property ID or by an optional string name. It is not necessary to specify properties in any particular order in the array. The array can contain duplicate properties, resulting in duplicate property values on return for simple properties. Nonsimple properties should return access denied on an attempt to open them a second time. The array can contain a mixture of property IDs and string IDs.

### `rgpropvar` [out]

Caller-allocated array of a
[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that, on return, contains the values of the properties specified by the corresponding elements in the *rgpspec* array. The array must be at least large enough to hold values of the *cpspec* parameter of the
**PROPVARIANT** structure. The *cpspec* parameter specifies the number of properties set in the array. The caller is not required to initialize these
**PROPVARIANT** structure values in any specific order. However, the implementation must fill all members correctly on return. If there is no other appropriate value, the implementation must set the **vt** member of each
**PROPVARIANT** structure to **VT_EMPTY**.

## Return value

This method supports the standard return value **E_UNEXPECTED**, as well as the following:

This function can also return any file system errors or Win32 errors wrapped in an **HRESULT** data type. For more information, see
[Error Handling Strategies](https://learn.microsoft.com/windows/desktop/com/error-handling-strategies).

For more information, see
[Property Storage Considerations](https://learn.microsoft.com/windows/desktop/Stg/property-storage-considerations).

## See also

[EnumAll Sample](https://learn.microsoft.com/windows/desktop/Stg/enumall-sample)

[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage)

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[IPropertyStorage::WriteMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-writemultiple)

[IPropertyStorage::WritePropertyNames](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-writepropertynames)

[Samples](https://learn.microsoft.com/windows/desktop/Stg/samples)

[StgCreatePropSetStg Sample](https://learn.microsoft.com/windows/desktop/Stg/stgcreatepropsetstg-sample)

[WriteRead Sample](https://learn.microsoft.com/windows/desktop/Stg/writeread-sample)
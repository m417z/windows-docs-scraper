# IPropertyStorage::WritePropertyNames

## Description

The
**WritePropertyNames** method
assigns string [IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) names to a specified array of property IDs in the current property set.

## Parameters

### `cpropid` [in]

The size on input of the array *rgpropid*. Can be zero. However, making it zero causes this method to become non-operational.

### `rgpropid` [in]

An array of the property IDs for which names are to be set.

### `rglpwstrName` [in]

An array of new names to be assigned to the corresponding property IDs in the *rgpropid* array. These names may not exceed 255 characters (not including the **NULL** terminator).

## Return value

This method supports the standard return value **E_UNEXPECTED**, in addition to the following:

## Remarks

For more information about property sets and memory management, see
[Managing Property Sets](https://learn.microsoft.com/windows/desktop/Stg/managing-property-sets).

**IPropertyStorage::WritePropertyNames** assigns string names to property IDs passed to the method in the *rgpropid* array. It associates each string name in the *rglpwstrName* array with the respective property ID in *rgpropid*. It is explicitly valid to define a name for a property ID that is not currently present in the property storage object.

It is also valid to change the mapping for an existing string name (determined by a case-insensitive match). That is, you can use the
**WritePropertyNames** method to map an existing name to a new property ID, or to map a new name to a property ID that already has a name in the dictionary. In either case, the original mapping is deleted. Property names must be unique (as are property IDs) within the property set.

The storage of string property names preserves the case. Unless **PROPSETFLAG_CASE_SENSITIVE** is passed to
[IPropertySetStorage::Create](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertysetstorage-create), property set names are case insensitive by default. With case-insensitive property sets, the name strings passed by the caller are interpreted according to the locale of the property set, as specified by the **PID_LOCALE** property. If the property set has no locale property, the current user is assumed by default. String property names are limited in length to 128 characters. Property names that begin with the binary Unicode characters 0x0001 through 0x001F are reserved for future use.

If the value of an element in the *rgpropid* array parameter is set to 0xffffffff (PID_ILLEGAL), the corresponding name is ignored by **IPropertyStorage::WritePropertyNames**. For example, if this method is called with a *cpropid* parameter of 3, but the first element of the array, *rgpropid[1]*, is set to **PID_ILLEGAL**, then only two property names are written. The *rgpropid[1]* element is ignored.

## See also

[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)

[IPropertyStorage::ReadMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-readmultiple)

[IPropertyStorage::ReadPropertyNames](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-readpropertynames)

[IPropertyStorage::WriteMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-writemultiple)

[Samples](https://learn.microsoft.com/windows/desktop/Stg/samples)

[WriteRead Sample](https://learn.microsoft.com/windows/desktop/Stg/writeread-sample)
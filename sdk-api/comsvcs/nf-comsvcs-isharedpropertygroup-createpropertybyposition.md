# ISharedPropertyGroup::CreatePropertyByPosition

## Description

Creates a new shared property with the specified index. If a shared property with the specified index already exists, **CreatePropertyByPosition** returns a reference to the existing one.

## Parameters

### `Index` [in]

The numeric index within the [SharedPropertyGroup](https://learn.microsoft.com/windows/desktop/cossdk/sharedpropertygroup) object by which the new property is referenced. You can use this index later to retrieve the shared property with the [get_PropertyByPosition](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isharedpropertygroup-get_propertybyposition) method.

### `fExists` [out]

A reference to a Boolean value. If *fExists* is set to VARIANT_TRUE on return from this method, the shared property specified by *Index* existed prior to this call. If it is set to VARIANT_FALSE, the property was created by this call.

### `ppProp` [out]

A reference to a shared property object identified by the numeric index passed in the *Index* parameter, or **NULL** if an error is encountered.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

When you create a shared property, its value is set to the default, which is a VT_I4 VARIANT with a value of 0.

If you create a [SharedProperty](https://learn.microsoft.com/windows/desktop/cossdk/sharedproperty) object with the **CreatePropertyByPosition** method, you can access that property only by using the [get_PropertyByPosition](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isharedpropertygroup-get_propertybyposition) method. You cannot assign a string name to the same property and then access it by using the [get_Property](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isharedpropertygroup-get_property) method. Accessing a property by position is faster than accessing a property by using a string name because it requires less overhead.

The same shared property group can contain some [SharedProperty](https://learn.microsoft.com/windows/desktop/cossdk/sharedproperty) objects that are identified by position and others that are identified by name.

## See also

[ISharedProperty](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isharedproperty)

[ISharedPropertyGroup](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isharedpropertygroup)
# ISharedPropertyGroup::CreateProperty

## Description

Creates a new shared property with the specified name. If a shared property by that name already exists, **CreateProperty** returns a reference to the existing property.

## Parameters

### `Name` [in]

The name of the property to create. You can use this name later to obtain a reference to this property by using the [get_Property](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isharedpropertygroup-get_property) method.

### `fExists` [out]

A reference to a Boolean value that is set to VARIANT_TRUE on return from this method if the shared property specified in the *Name* parameter existed prior to this call, and VARIANT_FALSE if the property was created by this call.

### `ppProp` [out]

A reference to a [SharedProperty](https://learn.microsoft.com/windows/desktop/cossdk/sharedproperty) object with the name specified in the *Name* parameter, or **NULL** if an error is encountered.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

When you create a shared property, its value is set to the default, which is a VT_I4 VARIANT with a value of 0.

If you create a shared property with the **CreateProperty** method, you can access that property only by using the [get_Property](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isharedpropertygroup-get_property) method. You cannot assign a numeric index to the same property and then access it by using the [get_PropertyByPosition](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isharedpropertygroup-get_propertybyposition) method.

The same shared property group can contain some [SharedProperty](https://learn.microsoft.com/windows/desktop/cossdk/sharedproperty) objects that are identified by name and others that are identified by position.

## See also

[ISharedProperty](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isharedproperty)

[ISharedPropertyGroup](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isharedpropertygroup)
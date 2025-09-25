# PSSetPropertyValue function

## Description

Sets the value of a property in a property store.

## Parameters

### `pps` [in]

Type: **[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)***

Pointer to an instance of the [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface, which represents the property store that contains the property.

### `ppd` [in]

Type: **[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)***

Pointer to an instance of the [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription) interface, which identifies the individual property.

### `propvar` [in]

Type: **REFPROPVARIANT**

Reference to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that contains the new value.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used to write a property value to a store. If the calling code already has a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure, it might be simpler to call [IPropertyStore::SetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-setvalue) directly.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSSetPropertyValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pssetpropertyvalue).

```cpp
// IPropertyDescription *pPropDesc;
// IPropertyStore *pStore;
// PROPVARIANT propvar;
// Assume the variables pStore, pPropDesc, and propvar are initialized and valid.

HRESULT hr = PSSetPropertyValue(pStore, pPropDesc, propvar);

if (SUCCEEDED(hr))
{
    // The value has been written to the store but has not been committed yet.
}
```

## See also

[IPropertyStore::Commit](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-commit)

[PSGetPropertyValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertyvalue)
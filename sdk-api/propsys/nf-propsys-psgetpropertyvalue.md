# PSGetPropertyValue function

## Description

Gets a property value from a property store.

## Parameters

### `pps` [in]

Type: **[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)***

Pointer to an instance of the [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface, which represents the property store from which to get the value.

### `ppd` [in]

Type: **[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)***

Pointer to an instance of the [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription) interface, which represents the property in the property store.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer to an uninitialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. When this function returns, points to the requested property value.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This helper function is used to read a property value from a store. If the calling code already has a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure, it might be simpler to call [IPropertyStore::GetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getvalue) directly.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSGetPropertyValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertyvalue).

```cpp
// IPropertyDescription *pPropDesc;
// IPropertyStore *pStore;
// Assume the variables pPropDesc and pStore are initialized and valid.
PROPVARIANT propvar;

HRESULT hr = PSGetPropertyValue(pStore, pPropDesc, &propvar);

if (SUCCEEDED(hr))
{
    // propvar is valid.

    PropVariantClear(&propvar);
}
```

## See also

[PSSetPropertyValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pssetpropertyvalue)
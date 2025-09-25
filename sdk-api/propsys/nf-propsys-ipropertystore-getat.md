# IPropertyStore::GetAt

## Description

Gets a property key from the property array of an item.

## Parameters

### `iProp`

The index of the property key in the array of PROPERTYKEY structures. This is a zero-based index.

### `pkey`

TBD

### `pKey`

A pointer to a PROPERTYKEY structure and it can be used in subsequent calls to [IPropertyStore::GetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getvalue) and [IPropertyStore::SetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-setvalue).

## Return value

The `IPropertyStore::GetAt` method returns a value of S_OK if successful. Otherwise, any other code it returns must be considered to be an error code.

## Remarks

None

## See also

[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)

[IPropertyStore::GetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getvalue)

[IPropertyStore::SetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-setvalue)
# IPropertyStore::GetCount

## Description

This method returns a count of the number of properties that are attached to the file.

## Parameters

### `cProps`

A pointer to a value that indicates the property count.

## Return value

The `IpropertyStore::GetCount` method returns a value of S_OK when the call is successful, even if the file has no properties attached. Any other code returned is an error code.

## Remarks

**IPropertyStore** provides an abstraction over an array of property keys via the `IPropertyStore::GetCount` and [IPropertyStore::GetAt](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getat) methods. The property keys in this array represent the properties that are currently stored by the **IPropertyStore**.

When `GetCount` succeeds, the value pointed to by cProps is a count of property keys in the array. The caller can expect calls to **IPropertyStore::GetAt** to succeed for values of iProp less than cProps.

In the case of failures such as E_OUTOFMEMORY, you should set cProps to zero. It is preferable that errors are discovered during creation or initialization of the property store.

## See also

[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)

[IPropertyStore::GetAt](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getat)
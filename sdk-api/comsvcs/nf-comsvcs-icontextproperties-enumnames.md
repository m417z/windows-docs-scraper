# IContextProperties::EnumNames

## Description

Retrieves a reference to an enumerator for the context object properties.

## Parameters

### `ppenum` [out]

A reference to the [IEnumNames](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-ienumnames) interface on a new enumerator object that you can use to iterate through all the context object properties.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

Use the **EnumNames** method to obtain a reference to an enumerator object. The returned [IEnumNames](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-ienumnames) interface exposes several methods you can use to iterate through a list of **BSTR** values representing context object properties. When you have a name, you can use the [GetProperty](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icontextproperties-getproperty) method to obtain a reference to the context object property it represents. As with any COM object, you must release an enumerator object when you are finished using it.

## See also

[IContextProperties](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icontextproperties)
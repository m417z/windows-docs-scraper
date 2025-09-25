# IObjectConstructString::get_ConstructString

## Description

Retrieves the constructor string for the object.

Object constructor strings should not be used to store security-sensitive information.

## Parameters

### `pVal` [out]

A reference to an administratively supplied object constructor string.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

You can use this method when implementing [IObjectConstruct::Construct](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectconstruct-construct), which is called by the COM+ environment when your component is marked as supporting object construction.

## See also

[COM+ Object Constructor Strings](https://learn.microsoft.com/windows/desktop/cossdk/com--object-constructor-strings)

[IObjectConstruct](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectconstruct)

[IObjectConstructString](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectconstructstring)

[Specifying an Object Constructor String for a Component](https://learn.microsoft.com/windows/desktop/cossdk/specifying-an-object-constructor-string-for-a-component)
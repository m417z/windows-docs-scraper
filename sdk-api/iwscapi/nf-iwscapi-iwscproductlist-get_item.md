# IWSCProductList::get_Item

## Description

Returns one of the types of providers on the computer.

## Parameters

### `index` [in]

The list of the providers.

### `pVal` [out]

A pointer to the [IWscProduct](https://learn.microsoft.com/windows/desktop/api/iwscapi/nn-iwscapi-iwscproduct) product information.

## Return value

If the method succeeds, returns S_OK.

If the method fails, returns a Win32 error code.

## Remarks

A provider is obtained by calling the **Item** method, which returns an interface pointer to an initialized [IWscProduct](https://learn.microsoft.com/windows/desktop/api/iwscapi/nn-iwscapi-iwscproduct) object. The user is then able to retrieve the name, product state, and signature status through the methods of the **IWscProduct** interface.

## See also

[IWSCProductList](https://learn.microsoft.com/windows/desktop/api/iwscapi/nn-iwscapi-iwscproductlist)
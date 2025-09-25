# ICatalogObject::IsPropertyWriteOnly

## Description

Indicates whether the specified property can be read using [Value](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icatalogobject-get_value).

## Parameters

### `bstrPropName` [in]

The name of the property to be read.

### `pbRetVal` [out, retval]

If this value is True, you cannot read the property. Otherwise, you can read the property.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ICatalogObject](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icatalogobject)
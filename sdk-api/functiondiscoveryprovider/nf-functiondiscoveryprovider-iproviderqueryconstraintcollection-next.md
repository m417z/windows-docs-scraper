# IProviderQueryConstraintCollection::Next

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets the name and value of the next query constraint in the collection.

## Parameters

### `ppszConstraintName` [out]

The constraint name.

### `ppszConstraintValue` [out]

The constraint value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IProviderQueryConstraintCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-iproviderqueryconstraintcollection)
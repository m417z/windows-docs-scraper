# IProviderQueryConstraintCollection::Item

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets the name and value of the specified query constraint, by index.

## Parameters

### `dwIndex` [in]

The index of the item in the collection.

### `ppszConstraintName` [out]

The constraint name.

### `ppszConstraintValue` [out]

The constraint value.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | The *pszConstraintName* or *ppszConstraintValue* parameter is **NULL**. |

## See also

[IProviderQueryConstraintCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-iproviderqueryconstraintcollection)
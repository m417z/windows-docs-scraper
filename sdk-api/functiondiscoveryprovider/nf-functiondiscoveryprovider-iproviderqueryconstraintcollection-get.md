# IProviderQueryConstraintCollection::Get

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets the value of the specified query constraint, by name.

## Parameters

### `pszConstraintName` [in]

The constraint name.

### `ppszConstraintValue` [out]

The constraint value.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **S_FALSE** | The method completed successfully, but the property key was not found in the collection. |
| **E_POINTER** | The *pszConstraintName* or *ppszConstraintValue* parameter is **NULL**. |

## See also

[IProviderQueryConstraintCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-iproviderqueryconstraintcollection)
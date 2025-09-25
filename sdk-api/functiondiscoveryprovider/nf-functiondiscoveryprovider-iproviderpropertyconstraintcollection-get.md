# IProviderPropertyConstraintCollection::Get

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets the name and value of the specified property constraint, by property key.

## Parameters

### `Key` [in]

The property key.

### `pPropVar` [out]

A **VARIANT** used for the property key constraint value.

### `pdwPropertyConstraint` [out]

The type of constraint to apply.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **S_FALSE** | The method completed successfully, but the property key was not found in the collection. |
| **E_POINTER** | The *ppropVar* or *pdwPropertyConstraint* parameter is **NULL**. |

## See also

[IProviderPropertyConstraintCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-iproviderpropertyconstraintcollection)
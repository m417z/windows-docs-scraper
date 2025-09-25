# IProviderPropertyConstraintCollection::Item

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Gets the name and value of the specified property constraint, by index.

## Parameters

### `dwIndex` [in]

The index of the item in the collection.

### `pKey` [out]

The property key.

### `pPropVar` [out]

A **PROPVARIANT** used for the property constraint data.

### `pdwPropertyConstraint` [out]

The type of constraint to apply.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_POINTER** | The *ppropVar* or *pdwPropertyConstraint* parameter is **NULL**. |

## See also

[IProviderPropertyConstraintCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-iproviderpropertyconstraintcollection)
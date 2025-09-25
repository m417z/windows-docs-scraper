# IFunctionInstanceCollectionQuery::AddPropertyConstraint

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Adds a property constraint to the query.

This method limits query results to only function instances with a property key (PKEY) matching the specified constraint.

## Parameters

### `Key` [in]

The property key (PKEY) for the constraint. For more information about PKEYs, see [Key Definitions](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/key-definitions).

### `pv` [in]

A **PROPVARIANT** used for the constraint. This type must match the PROPVARIANT type associated with *Key*.

The following shows possible values. Note that only a subset of the PROPVARIANT types supported by the built-in providers can be used as a property constraint.

VT_BOOL

VT_I2

VT_I4

VT_I8

VT_INT

VT_LPWSTR

VT_LPWSTR|VT_VECTOR

VT_UI2

VT_UI4

VT_UI8

VT_UINT

### `enumPropertyConstraint` [in]

A [PropertyConstraint](https://learn.microsoft.com/windows/win32/api/functiondiscoveryconstraints/ne-functiondiscoveryconstraints-propertyconstraint) value that specifies the type of comparison to use when comparing the constraint's PKEY to the function instance's PKEY.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The constraint specified for the query is not supported. Either the constraint is not supported for a specific **VARENUM** type, or the **VARENUM** type is not supported at all. |

## Remarks

A function instance will only match a property constraint when the PROPVARIANT type of the function instance's PKEY matches the PROPVARIANT type of the constraint's PKEY and the function instance's PKEY value matches the constraint's PKEY value using the comparison operator specified by *enumPropertyConstraint*.

If multiple constraints are added, all constraints must be supported to satisfy the query.

## See also

[Function Discovery Queries](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/function-discovery-queries)

[IFunctionInstanceCollectionQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollectionquery)
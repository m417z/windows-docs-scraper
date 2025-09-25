# IFunctionInstanceCollectionQuery::AddQueryConstraint

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **AddQueryConstraint** method adds a query constraint to the query.

This method enables the application to filter the result set to only those instances that fulfill this constraint.

## Parameters

### `pszConstraintName` [in]

The query constraint.

### `pszConstraintValue` [in]

The constraint value.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |

## Remarks

If multiple constraints are added, all constraints must be supported to satisfy the query.

**AddQueryConstraint** will fail with an error if the [IFunctionInstanceCollectionQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollectionquery) object includes all subcategories and the **AddQueryConstraint** method is called with the *pszConstraintName* parameter set to **FD_QUERYCONSTRAINT_PROVIDERINSTANCEID**. To avoid this error, create a **IFunctionInstanceCollectionQuery** object that does not include all subcategories. You can create such an object by calling [CreateInstanceCollectionQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscovery-createinstancecollectionquery) with the *fIncludeAllSubCategories* parameter set to **false**.

## See also

[Constraint Definitions](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/constraint-definitions)

[Function Discovery Queries](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/function-discovery-queries)

[IFunctionInstanceCollectionQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollectionquery)
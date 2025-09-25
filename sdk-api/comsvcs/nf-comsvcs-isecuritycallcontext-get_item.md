# ISecurityCallContext::get_Item

## Description

Retrieves a specified property in the security call context collection.

## Parameters

### `name` [in]

The name of the property item to be retrieved. See Remarks for information about the available items.

### `pItem` [out]

A reference to the retrieved property.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The security call context collection represents a security call context, which provides information about the callers in the chain of calls ending with the current call. For each item in the security call context collection, the following table provides a description, the index name used to retrieve it, and the returned data type of the item.

| Item | Description | Index name | Returned type |
| --- | --- | --- | --- |
| Direct Caller | The immediate caller of the object. | "DirectCaller" | A [SecurityIdentity](https://learn.microsoft.com/windows/desktop/cossdk/securityidentity) object |
| Original Caller | The caller that originated the chain of calls to the object. | "OriginalCaller" | A [SecurityIdentity](https://learn.microsoft.com/windows/desktop/cossdk/securityidentity) object |
| Minimum Authentication Level | The lowest authentication level used in the chain of calls. | "MinAuthenticationLevel" | A **Long** |
| Number of Callers | The number of callers in the chain of calls to the object. | "NumCallers" | A **Long** |
| Callers | The callers in the chain of calls that ends with the current call. | "Callers" | A [SecurityCallers](https://learn.microsoft.com/windows/desktop/cossdk/securitycallers) object |

## See also

[ISecurityCallContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isecuritycallcontext)
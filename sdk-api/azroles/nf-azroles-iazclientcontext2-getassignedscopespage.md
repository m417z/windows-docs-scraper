# IAzClientContext2::GetAssignedScopesPage

## Description

The **GetAssignedScopesPage** method retrieves a list of the scopes in which the client represented by the current [IAzClientContext2](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazclientcontext2) object is assigned to at least one role.

## Parameters

### `lOptions` [in]

A flag that specifies whether this method checks LDAP query groups for scope assignment. Previously cached LDAP query groups are checked regardless of the value of this flag.

| Value | Meaning |
| --- | --- |
| **AZ_CLIENT_CONTEXT_SKIP_LDAP_QUERY**<br><br>1 | LDAP query groups that were not previously cached are not checked. |

### `PageSize` [in]

The number of elements in each page result.

### `pvarCursor` [in, out]

A pointer to a **VARIANT** that represents the current page of results. For the first call to the **GetAssignedScopesPage** method, pass **VT_EMPTY** as the value for this parameter to retrieve the first page of results. The number of elements on a page is determined by the value of the *PageSize* parameter. On output, this parameter contains the value to be passed in the next call to **GetAssignedScopesPage** to retrieve the next page of results. If the value of this parameter on output is **EMPTY**, there are no more result pages.

### `pvarScopeNames`

On return, contains an array of variables of type **VARIANT**. Each element of the array is of type **VT_BSTR** and contains the name of a scope to which the current client is assigned. The number of elements in the array is specified by the *PageSize* parameter.

## Return value

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

If multiple threads access the same authorization store, a call to the **GetAssignedScopesPage** method on one of the threads might not return accurate results if the other thread modifies the store.

In JScript, the returned [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) values must be converted to the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object.
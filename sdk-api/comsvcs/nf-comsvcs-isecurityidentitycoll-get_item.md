# ISecurityIdentityColl::get_Item

## Description

Retrieves a specified property in the security identity collection.

## Parameters

### `name` [in]

The name of the property to be retrieved. See Remarks for information about the available properties.

### `pItem` [out]

A reference to the retrieved property.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

This collection represents a security identity, which provides information about a particular caller in the chain of calls ending with the current call. For each item in the security identity collection, the following table provides a description, the index name used to retrieve it, and the returned data type of the item.

| Item | Description | Index name | Returned type |
| --- | --- | --- | --- |
| SID | The security identifier of the caller. | "SID" | V_ARRAY |
| Account Name | The account name that the caller is using. | "AccountName" | V_BSTR |
| Authentication Service | The authentication service used by the caller, such as NTLMSSP, Kerberos, or SSL. | "AuthenticationService" | V_I4 |
| Impersonation Level | The impersonation level, which indicates how much authority the caller has been given to act on a client's behalf. | "ImpersonationLevel" | V_I4 |
| Authentication Level | The authentication level used by the caller, which indicates the amount of protection given during the call. | "AuthenticationLevel" | V_I4 |

## See also

[COM+ Security](https://learn.microsoft.com/windows/desktop/cossdk/com--security)

[ISecurityIdentityColl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isecurityidentitycoll)
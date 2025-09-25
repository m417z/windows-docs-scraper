# IAzApplication::AddDelegatedPolicyUserName

## Description

The **AddDelegatedPolicyUserName** method adds the specified account name to the list of principals that act as delegated policy users.

## Parameters

### `bstrDelegatedPolicyUser` [in]

Account name to add to the list of delegated policy users. The account name must be in user principal name (UPN) format (for example, "someone@example.com"). The [LookupAccountName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountnamea) function is called to retrieve the domain.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

 If the method succeeds, the method returns S_OK.

An attempt to call this method on an XML store will return E_INVALIDARG.

Any other **HRESULT** value indicates that the operation failed.

## Remarks

Delegated policy users are principals that are allowed to read the subset of the policy data that the policy administrator of an [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object uses to administer the delegated object.

**Note** Delegated policy users are not supported for XML stores.

To view the list of delegated policy users in account name format, use the [DelegatedPolicyUsersName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_delegatedpolicyusersname) property.

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-submit) method to persist any changes made by this method.
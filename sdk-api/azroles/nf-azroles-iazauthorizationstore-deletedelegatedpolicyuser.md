# IAzAuthorizationStore::DeleteDelegatedPolicyUser

## Description

The **DeleteDelegatedPolicyUser** method removes the specified [security identifier](https://learn.microsoft.com/windows/win32/SecGloss/s-gly) (SID) in text form from the list of principals that act as delegated policy users.

## Parameters

### `bstrDelegatedPolicyUser` [in]

Text form of the SID to remove from the list of delegated policy users.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

Delegated policy users are principals that are allowed to read the subset of the policy data that the policy administrator of an [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) or [IAzScope](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazscope) object uses to administer the delegated object.

>[!NOTE]
>Delegated policy users are not supported for XML stores.

To view the list of delegated policy users, use the [DelegatedPolicyUsers](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazauthorizationstore-get_delegatedpolicyusers) property.

## See also

[IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication)

[IAzScope](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazscope)

[DelegatedPolicyUsers](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazauthorizationstore-get_delegatedpolicyusers)
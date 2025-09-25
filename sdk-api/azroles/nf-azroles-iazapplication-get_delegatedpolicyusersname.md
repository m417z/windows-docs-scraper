# IAzApplication::get_DelegatedPolicyUsersName

## Description

The **DelegatedPolicyUsersName** property retrieves the account names of principals that act as delegated policy users.

This property is read-only.

## Parameters

## Remarks

Delegated policy users are principals that are allowed to read the subset of the policy data that the policy administrator of an [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object uses to administer the delegated object.

**Note** Delegated policy users are not supported for XML stores.

In JScript, the returned [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) must be converted to the JScript [Array](https://learn.microsoft.com/scripting/javascript/reference/array-object-javascript) object.
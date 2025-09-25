# IAzApplication::AddDelegatedPolicyUser

## Description

The **AddDelegatedPolicyUser** method adds the specified [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) in text form to the list of principals that act as delegated policy users.

## Parameters

### `bstrDelegatedPolicyUser` [in]

Text form of the SID to add to the list of delegated policy users.

### `varReserved` [in, optional]

Reserved for future use. This parameter can be any of the following values:

* varReserved.vt == VT_ERROR and varReserved.scode == DISP_E_PARAMNOTFOUND
* varReserved.vt == VT_EMPTY
* varReserved.vt == VT_NULL
* varReserved.vt == VT_I4 and varReserved.lVal == 0
* varReserved.vt == VT_I2 and varReserved.iVal == 0

## Return value

### C++

If the method succeeds, the method returns S_OK.

An attempt to call this method on an XML store will return E_INVALIDARG.

Any other **HRESULT** value indicates that the operation failed.

### VB

If the method succeeds, the method returns S_OK.

An attempt to call this method on an XML store will return E_INVALIDARG.

Any other **HRESULT** value indicates that the operation failed.

## Remarks

Delegated policy users are principals that are allowed to read the subset of the policy data that the policy administrator of an [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object uses to administer the delegated object.

**Note** Delegated policy users are not supported for XML stores.

To view the list of delegated policy users, use the [DelegatedPolicyUsers](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_delegatedpolicyusers) property.

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-submit) method to persist any changes made by this method.
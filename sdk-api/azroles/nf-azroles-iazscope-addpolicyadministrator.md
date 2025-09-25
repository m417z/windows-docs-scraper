# IAzScope::AddPolicyAdministrator

## Description

The **AddPolicyAdministrator** method adds the specified [security identifier](https://learn.microsoft.com/windows/win32/SecGloss/s-gly) (SID) in text form to the list of principals that act as policy administrators.

## Parameters

### `bstrAdmin` [in]

Text form of the SID to add to the list of policy administrators.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

Policy administrators for an object can perform the following tasks:

- Read the object
- Write attributes to the object
- Read attributes of child objects of the object
- Write attributes to child objects of the object
- Delete the object
- Delete child objects of the object
- Create child objects of the object

To view the list of policy administrators, use the [PolicyAdministrators](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazscope-get_policyadministrators) property.

You must call the [Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazscope-submit) method to persist any changes made by this method.

## See also

[PolicyAdministrators](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazscope-get_policyadministrators)

[Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazscope-submit)
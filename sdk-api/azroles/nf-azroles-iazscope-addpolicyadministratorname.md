# IAzScope::AddPolicyAdministratorName

## Description

The **AddPolicyAdministratorName** method adds the specified account name to the list of principals that act as policy administrators.

## Parameters

### `bstrAdmin` [in]

The account name to add to the list of policy administrators. The account name can be in either user principal name (UPN) format (for example, `someone@example.com`) or in the `ExampleDomain\UserName` format. If the domain is not in the `ExampleDomain\UserName` format, the [LookupAccountName](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-lookupaccountnamea) function is called to retrieve the domain.

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

To view the list of policy administrators in account name format, use the [PolicyAdministratorsName](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazscope-get_policyadministratorsname) property.

You must call the [Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazscope-submit) method to persist any changes made by this method.

## See also

[LookupAccountName](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-lookupaccountnamea)

[PolicyAdministratorsName](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazscope-get_policyadministratorsname)

[Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazscope-submit)
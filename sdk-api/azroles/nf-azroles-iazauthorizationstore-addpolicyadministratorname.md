# IAzAuthorizationStore::AddPolicyAdministratorName

## Description

The **AddPolicyAdministratorName** method adds the specified account name to the list of principals that act as policy administrators.

This method is an alternate version of the [AddPolicyAdministrator](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-addpolicyadministrator) method.

## Parameters

### `bstrAdmin` [in]

Account name to add to the list of policy administrators. The account name must be in user principal name (UPN) format (for example, "someone@example.com"). The [LookupAccountName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountnamea) function is called to retrieve the domain.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.

## Remarks

Policy administrators for an object can perform the following tasks:

* Read the object
* Write attributes to the object
* Read attributes of child objects of the object
* Write attributes to child objects of the object
* Delete the object
* Delete child objects of the object
* Create child objects of the object

To view the list of policy administrators in account name format, use the [PolicyAdministratorsName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-get_policyadministratorsname) property.

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-submit) method to persist any changes made by this method.
# IAzApplication::DeletePolicyAdministratorName

## Description

The **DeletePolicyAdministratorName** method removes the specified account name from the list of principals that act as policy administrators.

## Parameters

### `bstrAdmin` [in]

Account name to remove from the list of policy administrators. The account name can be in either user principal name (UPN) format (for example, "someone@example.com") or in the format of "ExampleDomain\UserName". If the domain is not in the "ExampleDomain\UserName" format, the [LookupAccountName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountnamea) function is called to retrieve the domain.

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

To view the list of policy administrators in account name format, use the [PolicyAdministratorsName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_policyadministratorsname) property.
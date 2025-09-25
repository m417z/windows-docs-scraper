# IAzApplication::AddPolicyReaderName

## Description

The **AddPolicyReaderName** method adds the specified account name to the list of principals that act as policy readers.

## Parameters

### `bstrReader` [in]

Account name to add to the list of policy readers. The account name must be in user principal name (UPN) format (for example, "someone@example.com"). The [LookupAccountName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountnamea) function is called to retrieve the domain.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.

## Remarks

Policy readers for an object can read attributes for the object and for child objects of the object. Readers can also use the policy; for example, readers can call the [AccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-accesscheck) method. Readers cannot modify the object or its child objects.

To view the list of policy readers in account name format, use the [PolicyReadersName](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-get_policyreadersname) property.

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-submit) method to persist any changes made by this method.
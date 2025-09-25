# IAzScope::DeletePolicyReaderName

## Description

The **DeletePolicyReaderName** method removes the specified account name from the list of principals that act as policy readers.

## Parameters

### `bstrReader` [in]

Account name to remove from the list of policy readers. The account name can be in either user principal name (UPN) format (for example, `someone@example.com`) or in the `ExampleDomain\UserName` format. If the domain is not in the `ExampleDomain\UserName` format, the [LookupAccountName](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-lookupaccountnamea) function is called to retrieve the domain.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

Policy readers for an object can read attributes for the object and for child objects of the object. Readers can also use the policy; for example, readers can call the [AccessCheck](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazclientcontext-accesscheck) method. Readers cannot modify the object or its child objects.

To view the list of policy readers in account name format, use the [PolicyReadersName](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazscope-get_policyreadersname) property.

## See also

[LookupAccountName](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-lookupaccountnamea)

[AccessCheck](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazclientcontext-accesscheck)
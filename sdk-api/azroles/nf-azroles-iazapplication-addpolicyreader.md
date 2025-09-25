# IAzApplication::AddPolicyReader

## Description

The **AddPolicyReader** method adds the specified [security identifier](https://learn.microsoft.com/windows/win32/SecGloss/s-gly) (SID) in text form to the list of principals that act as policy readers.

## Parameters

### `bstrReader` [in]

Text form of the SID to add to the list of policy readers.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

Policy readers for an object can read attributes for the object and for child objects of the object. Readers can also use the policy; for example, readers can call the [AccessCheck](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazclientcontext-accesscheck) method. Readers cannot modify the object or its child objects.

To view the list of policy readers, use the [PolicyReaders](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplication-get_policyreaders) property.

You must call the [Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplication-submit) method to persist any changes made by this method.

## See also

[AccessCheck](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazclientcontext-accesscheck)

[Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplication-submit)

[PolicyReaders](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplication-get_policyreaders)
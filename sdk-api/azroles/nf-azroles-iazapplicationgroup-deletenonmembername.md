# IAzApplicationGroup::DeleteNonMemberName

## Description

The **DeleteNonMemberName** method removes the specified account name from the list of accounts that are refused membership in the application group.

## Parameters

### `bstrProp` [in]

String that contains the account name to remove from the list of accounts that are refused membership in the application group. The account name must be in user principal name (UPN) format (for example, `someone@example.com`). The [LookupAccountName](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-lookupaccountnamea) function is called to retrieve the domain.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

To view the list of account names of accounts that are refused membership in this application group, use the [NonMembersName](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_nonmembersname) property.

## See also

[LookupAccountName](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-lookupaccountnamea)

[NonMembersName](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_nonmembersname)
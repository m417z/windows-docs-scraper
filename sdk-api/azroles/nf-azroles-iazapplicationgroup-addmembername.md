# IAzApplicationGroup::AddMemberName

## Description

The **AddMemberName** method adds the specified account name to the list of accounts that belong to the application group.

## Parameters

### `bstrProp` [in]

String that contains the account name to add to the list of accounts that belong to the application group. The account name must be in user principal name (UPN) format. The [LookupAccountName](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-lookupaccountnamea) function is called to retrieve the domain.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

To view the list of account names of accounts that belong to this application group, use the [MembersName](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_membersname) property.

You must call the [Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-submit) method to persist any changes made by this method.

## See also

[LookupAccountName](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-lookupaccountnamea)

[Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-submit)
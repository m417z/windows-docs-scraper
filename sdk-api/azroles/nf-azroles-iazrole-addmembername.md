# IAzRole::AddMemberName

## Description

The **AddMemberName** method adds the specified account name to the list of accounts that belong to the role.

## Parameters

### `bstrProp` [in]

String that contains the account name to add to the list of accounts that belong to the role. The account name can be in either user principal name (UPN) format (for example, `someone@example.com`) or in the `ExampleDomain\UserName` format. If the domain is not in the `ExampleDomain\UserName` format, the [LookupAccountName](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-lookupaccountnamea) function is called to retrieve the domain.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

To view the list of account names of accounts that belong to this role, use the [MembersName](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-get_membersname) property.

You must call the [Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-submit) method to persist any changes made by this method.

## See also

[MembersName](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-get_membersname)

[Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-submit)

[LookupAccountName](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-lookupaccountnamea)
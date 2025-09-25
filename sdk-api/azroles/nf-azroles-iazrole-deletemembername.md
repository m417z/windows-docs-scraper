# IAzRole::DeleteMemberName

## Description

The **DeleteMemberName** method removes the specified account name from the list of accounts that belong to the role.

## Parameters

### `bstrProp` [in]

String that contains the account name to remove from the list of accounts that belong to the role. The account name can be in either user principal name (UPN) format (for example, `someone@example.com`) or in the `ExampleDomain\UserName` format. If the domain is not in the `ExampleDomain\UserName` format, the [LookupAccountName](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-lookupaccountnamea) function is called to retrieve the domain.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

To view the list of account names of accounts that belong to the role, use the [MembersName](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-get_membersname) property.

## See also

[LookupAccountName](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-lookupaccountnamea)

[MembersName](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-get_membersname)
# IAzApplicationGroup::AddNonMember

## Description

The **AddNonMember** method adds the specified [security identifier](https://learn.microsoft.com/windows/win32/SecGloss/s-gly) (SID) in text form to the list of accounts that are refused membership in the application group.

## Parameters

### `bstrProp` [in]

String that contains the text form of the SID to add to the list of accounts that are refused membership in the application group.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

The application group will never have an account added using this method as a member, even if that account is specified directly or indirectly by the [Members](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_members) property.

Denying membership to an account in an application group does not prevent that account from being assigned to a role through a different application group, nor from being granted permission to a resource through assignment to any other role.

To view the list of SIDs of accounts that are refused membership in this application group in text form, use the [NonMembers](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_nonmembers) property.

You must call the [Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-submit) method to persist any changes made by this method.

## See also

[Members](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_members)

[NonMembers](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_nonmembers)

[Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-submit)
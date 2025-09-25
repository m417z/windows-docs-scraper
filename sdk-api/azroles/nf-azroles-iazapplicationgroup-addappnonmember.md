# IAzApplicationGroup::AddAppNonMember

## Description

The **AddAppNonMember** method adds the specified [IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup) object to the list of application groups that are refused membership in this application group.

## Parameters

### `bstrProp` [in]

String that contains the [Name](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_name) property of the [IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup) object to add to the list of the application groups that are refused membership in this application group.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

To view the list of application groups that are refused membership in this application group, use the [AppNonMembers](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_appnonmembers) property.

Denying membership to an account in an application group does not prevent that account from being assigned to a role through a different application group, nor from being granted permission to a resource through assignment to any other role.

You must call the [Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-submit) method to persist any changes made by this method.

## See also

[IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup)
# IAzRole::AddAppMember

## Description

The **AddAppMember** method adds the specified [IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup) object to the list of application groups that belong to this role.

## Parameters

### `bstrProp` [in]

String that contains the [Name](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_name) property of the [IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup) object to add to the list of the application groups that belong to this role.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

To view the list of application groups that belong to this role, use the [AppMembers](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-get_appmembers) property.

You must call the [Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-submit) method to persist any changes made by this method.

## See also

[IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup)

[Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-submit)
# IAzRole::DeleteAppMember

## Description

The **DeleteAppMember** method removes the specified [IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup) object from the list of application groups that belong to the role.

## Parameters

### `bstrProp` [in]

String that contains the [Name](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_name) property of the [IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup) object to remove from the list of application groups that belong to the role.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

To view the list of application groups that belong to the role, use the [AppMembers](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazrole-get_appmembers) property.

## See also

[IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup)
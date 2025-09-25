# IAzApplicationGroup::DeleteAppNonMember

## Description

The **DeleteAppNonMember** method removes the specified [IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup) object from the list of application groups that are refused membership in this application group.

## Parameters

### `bstrProp` [in]

String that contains the [Name](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_name) property of the [IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup) object to remove from the list of the application groups that are refused membership in this application group.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

To view the list of application groups that are refused membership in this application group, use the [AppNonMembers](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iazapplicationgroup-get_appnonmembers) property.

## See also

[IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup)
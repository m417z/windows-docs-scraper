# IAzAuthorizationStore::CreateApplicationGroup

## Description

The **CreateApplicationGroup** method creates an [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object with the specified name.

## Parameters

### `bstrGroupName` [in]

Name for the new [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object.

### `varReserved` [in, optional]

Reserved for future use.

### `ppGroup` [out]

A pointer to a pointer to the created [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.

## Remarks

You must call the [IAzApplicationGroup::Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplicationgroup-submit) method to persist any changes made to the returned object.

The returned [IAzApplicationGroup](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplicationgroup) object is an immediate child object of the [AzAuthorizationStore](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazauthorizationstore) object.
# IAzAuthorizationStore::CreateApplication

## Description

The **CreateApplication** method creates an [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object with the specified name.

## Parameters

### `bstrApplicationName` [in]

Name for the new [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object.

### `varReserved` [in, optional]

Reserved for future use.

### `ppApplication` [out]

A pointer to a pointer to the created [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.

## Remarks

You must call the [IAzApplication::Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazapplication-submit) method to persist any changes made by the returned object.

The returned [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object is an immediate child object of the [AzAuthorizationStore](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazauthorizationstore) object.
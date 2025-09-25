# IAzAuthorizationStore::OpenApplication

## Description

The **OpenApplication** method opens the [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object with the specified name.

## Parameters

### `bstrApplicationName` [in]

Name of the [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object to open.

### `varReserved` [in, optional]

Reserved for future use.

### `ppApplication` [out]

A pointer to a pointer to the opened [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.
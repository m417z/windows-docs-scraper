# IAzApplication::OpenOperation

## Description

The **OpenOperation** method opens an [IAzOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazoperation) object with the specified name.

## Parameters

### `bstrOperationName` [in]

Name of the [IAzOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazoperation) object to open.

### `varReserved` [in, optional]

Reserved for future use.

### `ppOperation` [out]

A pointer to a pointer to the opened [IAzOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazoperation) object.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.
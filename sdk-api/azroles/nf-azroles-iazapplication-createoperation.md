# IAzApplication::CreateOperation

## Description

The **CreateOperation** method creates an [IAzOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazoperation) object with the specified name.

## Parameters

### `bstrOperationName` [in]

Name for the new [IAzOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazoperation) object.

### `varReserved` [in, optional]

Reserved for future use.

### `ppOperation` [out]

A pointer to a pointer to the created [IAzOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazoperation) object.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.

## Remarks

You must call the [IAzOperation::Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazoperation-submit) method to persist any changes made to the returned object.

The returned [IAzOperation](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazoperation) object is an immediate child object of the [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object.
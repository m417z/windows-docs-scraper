# IAzApplication::CreateTask

## Description

The **CreateTask** method creates an [IAzTask](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iaztask) object with the specified name.

## Parameters

### `bstrTaskName` [in]

Name for the new [IAzTask](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iaztask) object.

### `varReserved` [in, optional]

Reserved for future use.

### `ppTask` [out]

A pointer to a pointer to the created [IAzTask](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iaztask) object.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.

## Remarks

You must call the [IAzTask::Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-submit) method to persist any changes made to the returned object.

The returned [IAzTask](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iaztask) object is an immediate child object of the [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object.
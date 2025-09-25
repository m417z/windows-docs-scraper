# IAzTask::AddTask

## Description

The **AddTask** method adds the [IAzTask](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iaztask) object with the specified name to the task.

## Parameters

### `bstrTask` [in]

Name of the [IAzTask](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iaztask) object to add to the task.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

This method allows the nesting of [IAzTask](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iaztask) objects within another **IAzTask** object.

You must call the [Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iaztask-submit) method to persist any changes made by this method.

## See also

[IAzTask](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iaztask)

[Submit](https://learn.microsoft.com/windows/win32/api/azroles/nf-azroles-iaztask-submit)
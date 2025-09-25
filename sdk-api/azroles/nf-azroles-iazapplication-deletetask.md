# IAzApplication::DeleteTask

## Description

The **DeleteTask** method removes the [IAzTask](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iaztask) object with the specified name from the [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) object.

## Parameters

### `bstrTaskName` [in]

Name of the [IAzTask](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iaztask) object to delete.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

If there are any [IAzTask](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iaztask) references to an **IAzTask** object that has been deleted from the cache, the **IAzTask** object can no longer be used. In C++, you must release references to deleted **IAzTask** objects by calling the [IUnknown::Release](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-release) method. In C# and Visual Basic, references to deleted objects are automatically released.

## See also

[IAzTask](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iaztask)

[IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication)
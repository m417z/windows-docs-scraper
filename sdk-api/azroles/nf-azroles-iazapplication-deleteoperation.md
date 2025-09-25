# IAzApplication::DeleteOperation

## Description

The **DeleteOperation** method removes the [IAzOperation](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazoperation) object with the specified name from the [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) object.

## Parameters

### `bstrOperationName` [in]

Name of the [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) object to delete.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

If there are any [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) references to an **IAzOperation** object that has been deleted from the cache, the **IAzOperation** object can no longer be used. In C++, you must release references to deleted **IAzOperation** objects by calling the [IUnknown::Release](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-release) method. In C# and Visual Basic, references to deleted objects are automatically released.

## See also

[IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication)

[IAzOperation](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazoperation)
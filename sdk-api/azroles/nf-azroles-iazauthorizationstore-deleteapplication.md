# IAzAuthorizationStore::DeleteApplication

## Description

The **DeleteApplication** method removes the [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) object with the specified name from the [AzAuthorizationStore](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazauthorizationstore) object.

## Parameters

### `bstrApplicationName` [in]

Name of the [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) object to delete.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

If the deleted [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) object has child objects, those objects are deleted, as well. If there are any **IAzApplication** references to an **IAzApplication** object that has been deleted from the cache, the **IAzApplication** object can no longer be used. In C++, you must release references to deleted **IAzApplication** objects by calling the [IUnknown::Release](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-release) method. In C# and Visual Basic, references to deleted objects are automatically released.

## See also

[IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication)
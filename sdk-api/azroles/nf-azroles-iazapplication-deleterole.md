# IAzApplication::DeleteRole

## Description

The **DeleteRole** method removes the [IAzRole](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazrole) object with the specified name from the [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) object.

## Parameters

### `bstrRoleName` [in]

Name of the [IAzRole](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazrole) object to delete.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

If there are any [IAzRole](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazrole) references to an **IAzRole** object that has been deleted from the cache, the **IAzRole** object can no longer be used. In C++, you must release references to deleted **IAzRole** objects by calling the [IUnknown::Release](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-release) method. In C# and Visual Basic, references to deleted objects are automatically released.

## See also

[IAzRole](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazrole)

[IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication)
# IAzApplication::DeleteScope

## Description

The **DeleteScope** method removes the [IAzScope](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazscope) object with the specified name from the [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) object.

## Parameters

### `bstrScopeName` [in]

Name of the [IAzScope](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazscope) object to delete.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

If there are any [IAzScope](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazscope) references to an **IAzScope** object that has been deleted from the cache, the **IAzScope** object can no longer be used. In C++, you must release references to deleted **IAzScope** objects by calling the [IUnknown::Release](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-release) method. In C# and Visual Basic, references to deleted objects are automatically released.

## See also

[IAzScope](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazscope)

[IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication)
# IAzScope::DeleteApplicationGroup

## Description

The **DeleteApplicationGroup** method removes the [IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup) object with the specified name from the [IAzScope](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazscope) object.

## Parameters

### `bstrGroupName` [in]

Name of the [IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup) object to delete.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

If there are any [IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup) references to an **IAzApplicationGroup** object that has been deleted from the cache, the **IAzApplicationGroup** object can no longer be used. In C++, you must release references to deleted **IAzApplicationGroup** objects by calling the [IUnknown::Release](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-release) method. In C# and Visual Basic, references to deleted objects are automatically released.

## See also

[IAzApplicationGroup](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplicationgroup)
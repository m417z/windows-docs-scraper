# IAzRoleDefinition::DeleteRoleDefinition

## Description

The **DeleteRoleDefinition** method removes the [IAzRoleDefinition](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroledefinition) object with the specified name from this **IAzRoleDefinition** object.

## Parameters

### `bstrRoleDefinition` [in]

The name of the [IAzRoleDefinition](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroledefinition) object to delete.

## Return value

 If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

If there are any references to an [IAzRoleDefinition](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroledefinition) object that has been deleted from the cache, the **IAzRoleDefinition** object can no longer be used. In C++, you must release references to deleted **IAzRoleDefinition** objects by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method. In Visual Basic, references to deleted objects are automatically released.
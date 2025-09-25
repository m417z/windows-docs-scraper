# IAzScope2::DeleteRoleDefinition

## Description

The **DeleteRoleDefinition** method removes the specified [IAzRoleDefinition](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroledefinition) object from this scope.

## Parameters

### `bstrRoleDefinitionName` [in]

A string that contains the name of the [IAzRoleDefinition](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroledefinition) object to remove.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

If any references to an [IAzRoleDefinition](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroledefinition) object have been deleted from the cache, that object can no longer be used. In C++, you must release references to deleted **IAzRoleDefinition** objects by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method. In Visual Basic, references to deleted objects are automatically released.
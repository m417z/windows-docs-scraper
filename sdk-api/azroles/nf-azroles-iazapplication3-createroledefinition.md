# IAzApplication3::CreateRoleDefinition

## Description

The **CreateRoleDefinition** method creates a new [IAzRoleDefinition](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroledefinition) object with the specified name.

## Parameters

### `bstrRoleDefinitionName` [in]

A string that contains the name of the new [IAzRoleDefinition](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroledefinition) object.

### `ppRoleDefinitions` [out]

The address of a pointer to the [IAzRoleDefinition](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroledefinition) object that this method creates.

When you have finished using this [IAzRoleDefinition](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroledefinition) object, release it by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).
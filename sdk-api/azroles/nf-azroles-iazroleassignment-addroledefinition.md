# IAzRoleAssignment::AddRoleDefinition

## Description

The **AddRoleDefinition** method adds the specified [IAzRoleDefinition](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroledefinition) object to this [IAzRoleAssignment](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroleassignment) object.

## Parameters

### `bstrRoleDefinition` [in]

The name of the [IAzRoleDefinition](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroledefinition) to add.

## Return value

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazrole-submit) method to persist any changes made by this method.
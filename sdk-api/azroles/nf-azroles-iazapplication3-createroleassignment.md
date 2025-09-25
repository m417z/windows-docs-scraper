# IAzApplication3::CreateRoleAssignment

## Description

The **CreateRoleAssignment** method creates a new [IAzRoleAssignment](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroleassignment) object with the specified name.

## Parameters

### `bstrRoleAssignmentName` [in]

A string that contains the name of the new [IAzRoleAssignment](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroleassignment) object.

### `ppRoleAssignment` [out]

The address of a pointer to the [IAzRoleAssignment](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroleassignment) object that this method creates.

When you have finished using this [IAzRoleAssignment](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroleassignment) object, release it by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).
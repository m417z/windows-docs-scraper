# IAzScope2::OpenRoleAssignment

## Description

The **OpenRoleAssignment** method opens an [IAzRoleAssignment](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroleassignment) object with the specified name in this scope.

## Parameters

### `bstrRoleAssignmentName` [in]

A string that contains the name of the [IAzRoleAssignment](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroleassignment) object to open.

### `ppRoleAssignment` [out]

The address of a pointer to the [IAzRoleAssignment](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroleassignment) object that this method opens.

When you have finished using the [IAzRoleAssignment](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazroleassignment) object, release it by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).